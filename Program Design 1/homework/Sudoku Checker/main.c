#include <stdio.h>
#include <stdbool.h>

#define NUM 9

void check_sudoku(int grid_p[][NUM]);

int main(void) {
    int grid[NUM][NUM]; // sudoku puzzle
    for (int i = 0; i < NUM; ++i) {
        for (int j = 0; j < NUM; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

void check_sudoku(int grid_p[][NUM]) {
    bool check[NUM][NUM] = {};     //有誤的方格為true
    int check_repeat[NUM] = {};    //重複的
    int target = grid_p[0][0];
    //先檢查每一列(row)
    for (int i = 0; i < NUM; i++) {
        for (int c = 0; c < NUM; c++)
            check_repeat[c] = 0;
        for (int j = 0; j < NUM; j++) {
            check_repeat[grid_p[i][j] - 1]++;
        }
        for (int i1 = 0; i1 < NUM; i1++) {
            if (check_repeat[i1] >= 2) {
                for (int j1 = 0; j1 < NUM; j1++) {
                    if (grid_p[i][j1] == i1 + 1)
                        check[i][j1] = true;
                }
            }
        }
    }

    //先檢查每一行(column)
    for (int i = 0; i < NUM; i++) {
        for (int c = 0; c < NUM; c++)
            check_repeat[c] = 0;
        for (int j = 0; j < NUM; j++) {
            check_repeat[grid_p[j][i] - 1]++;
        }
        for (int i1 = 0; i1 < NUM; i1++) {
            if (check_repeat[i1] >= 2) {
                for (int j1 = 0; j1 < NUM; j1++) {
                    if (grid_p[j1][i] == i1 + 1)
                        check[j1][i] = true;
                }
            }
        }
    }

    //檢查3 * 3方格情況

    for (int i = 0; i < NUM; i += 3) {
        for (int j = 0; j < NUM; j += 3) {
            for (int i1 = i; i1 < i + 3; i1++) {
                for (int j1 = j; j1 < j + 3; j1++) {
                    for (int m = i; m < i + 3; m++) {
                        for (int n = j; n < j + 3; n++) {
                            if (grid_p[i1][j1] == grid_p[m][n] && (i1 != m && j1 != n)) {
                                check[i1][j1] = true;
                                check[m][n] = true;
                            }
                        }
                    }
                }
            }
        }
    }


    /*印出check檢查一下
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            printf("%d ", check[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (check[i][j] == true) {
                printf("(%d,%d)\n", i, j);
            }
        }
    }
}
//基本上是3*3的問題