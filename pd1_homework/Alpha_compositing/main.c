#include <stdio.h>

#define SIZE 256

void alpha_composite(unsigned int image[][SIZE], unsigned int width, unsigned int height, float alpha, int background_color);

int main(void) {
    //Co = (Ca * Aa + Cb * Ab * (1 - Aa)) / (Aa + Ab * (1 - Aa))
    unsigned int width, height, image[SIZE][SIZE] = {0}, backgounrd_color;
    float alpha;

    scanf("%f %u", &alpha, &backgounrd_color);
    scanf("%u %u", &width, &height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            scanf("%u", &image[i][j]);
        }
    }

    alpha_composite(image, width, height, alpha, backgounrd_color);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            printf("%u ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void alpha_composite(unsigned int image[][SIZE], unsigned int width, unsigned int height, float alpha, int background_color){
    //Co = (Ca * Aa + Cb * Ab * (1 - Aa)) / (Aa + Ab * (1 - Aa))
    //前景Ca 不透明純色背景Cb  透明度Aa = alpha, Ab = 1

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int Co = 0, Ab = 1, Ca = image[i][j], Cb = background_color;
            float Aa = alpha;
            Co = (Ca * Aa + Cb * Ab * (1 - Aa)) / (Aa + Ab * (1 - Aa));
            image[i][j] = Co;
        }
    }
}
