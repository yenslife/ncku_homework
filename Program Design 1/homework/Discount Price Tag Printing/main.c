#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\n");
    printf("\\    %3d%%off!    \\\n", a);
    printf("\\ Before  $ %4d \\\n", b);
    printf("\\ After   $%5.2f \\\n", b * (1 - 0.01 * a) );
    printf("\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"");
    return 0;
}
