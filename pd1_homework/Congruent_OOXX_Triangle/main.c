#include <stdio.h>

int main() {
    int h;
    scanf("%d", &h);
    for (int i1 = 0; i1 + 1 < h; i1++) {
        for (int i2 = h - i1 - 1; i2 > 0; i2--) {
            printf(" ");
            if (i2 == 1) {
                printf("O");
            }
        }
        for (int i3 = i1; i3 > 0; i3--){
            printf("XO");
        }
        printf("\n");
    }
    //最下面
    for (h = h * 2 - 1; h > 0; h--) {
        printf("O");
    }
    return 0;
}

/*#include<stdio.h>
int main(){
	int h;
	scanf("%d", &h);
	for(int i = 0; i<h-1; i++){
		for(int j = 0; j<h-i-1; j++){
			printf(" ");
		}
		for(int j = 0; j<2*i+1; j++){
			//printf("OwO");
			printf("%c", (j%2 ? 'X' : 'O'));
		}
		printf("\n");
	}
	for(int i = 0; i<2*h-1; i++){
		printf("O");
	}

}*/
