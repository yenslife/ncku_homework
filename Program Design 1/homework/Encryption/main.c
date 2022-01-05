#include <stdio.h>
#include<assert.h>

void number1();
void number2();
void number3();
void number4();
void number5();
void swap(char password[], int start1, int start2);
void caesarCipher(int k, char password[], int start, int end);
void VC(char key[], int n, char password[], int start, int end);
void rotate(char password[], int k, int start, int end, char way);
void TC(char password[], int k, int start, int end, char way);
void RFC(char password[], int key[], int keyLength, int start, int end);
//void mynumber3();



int main() {
    int type = 0;
    scanf("%d", &type);
    switch (type) {
        case 1:
            number1();
            break;
        case 2:
            number2();
            break;
        case 3:
            number3();
            break;
        case 4:
            number4();
            break;
        case 5:
            number5();
            break;
    }
    return 0;
}

void swap(char password[], int start1, int start2) {
    char tmp = '0';
    for (int i = start1, j = start2; i < start2; i++, j++) {
        tmp = password[i];
        password[i] = password[j];
        password[j] = tmp;
    }
}
void caesarCipher(int k, char password[], int start, int end) {
    for (int i = start; i < end; i++) {
        int c = password[i];
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) c += k;
        if (c > 'z' && ('a' <= c - k && c - k <= 'z')) c -= 26;
        else if ((c > 'Z') && ('A' <= c - k && c - k <= 'Z')) c -= 26;

        password[i] = c;
    }
}
void VC(char key[], int n, char password[], int start, int end) {
    for (int i = 0; i < n ; i++) key[i] = (int) key[i] - (int) 'a';
    for (int i = start, keyIndex = 0; i < end; i++) {
        if (((int) password[i]) >= 'A' && (int) password[i] <= 'Z') {
            password[i] = (int)password[i] + key[keyIndex % n] > 90 ? password[i] - 26 + key[keyIndex % n] : password[i] + key[keyIndex % n];
            keyIndex++;
        } else if ((int) password[i] >= 'a' && (int) password[i] <= 'z'){
            password[i] = (int)password[i] + key[keyIndex % n] > 122 ? password[i] - 26 + key[keyIndex % n] : password[i] + key[keyIndex % n];
            keyIndex++;
        }
    }
}
void rotate(char password[], int k, int start, int end, char way) {
    char tmp[64] = {};
    if (way == 'r') {
        for (int i = start; i < end; i++) {
            if (i + k >= end) tmp[i + k - end + start] = password[i];
            else tmp[i + k] = password[i];
        }
    } else if (way == 'l') {
        for (int i = end - 1; i > start - 1; i--) {
            if (i - k < start) tmp[i - k + end - start] = password[i];
            else tmp[i - k] = password[i];
        }
    }
    for (int i = start; i < end; i++) password[i] = tmp[i];
}
void TC(char password[], int k, int start, int end, char way) {
    if (way == 'a'){
        for (int i = start; i < end; i++) {
            int c = password[i];
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {c += (k % 26); k++;};
            if (c > 'z' && ('a' <= c - ((k - 1) % 26) && c - ((k - 1) % 26) <= 'z')) c -= 26;
            else if ((c > 'Z') && ('A' <= c - ((k - 1) % 26) && c - ((k - 1) % 26) <= 'Z')) c -= 26;
            password[i] = c;
        }
    } else if (way == 'd') {
        for (int i = start; i < end; i++) {
            int c = password[i];
            k%=26;
            if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')))continue;
            assert(k>=0);
            if('a' <= c && c <= 'z'){
                c=(c-'a'+k)%26+'a';
            }else{
                c=(c-'A'+k)%26+'A';
            }
            k--;
            k = (k%26+26)%26;
            //password[i] = c;
            //if (c < 'A' && c != password[i] && 'A' <= password[i] && password[i] <= 'Z') c += 26;
            //else if ('a' - 26 < c && c < 'a' && c != password[i] && 'a' <= password[i] && password[i] <= 'z') c += 26;
            password[i] = c;
        }
    }
}
void RFC(char password[], int key[], int keyLength, int start, int end) {
    char tmp[64] = {};
    for (int i = start, times = 0; i < end; i++) {
        tmp[key[i % keyLength] - 1 + times] = password[i];
        if (i % keyLength == (keyLength - 1)) times += keyLength;
    }
    for (int i = start, j = 0; i < end; i++, j++) password[i] = tmp[j];
}
// 'a' = 97 'z' = 122 'A' = 65 'Z' = 90
void number1() {
    char password[64] = {}, trashCan = '0';
    trashCan = getchar();
    char key[5] = {'m', 'e', 'o', 'w'};
    for (int i = 0; i < 64; i++) {
        password[i] = getchar();
    }
    swap(password, 0, 32);
    caesarCipher(13, password, 0, 32);
    // 維吉尼雅加密 k = meow 12, 4, 14, 22
    VC(key, 4, password, 32, 64);
    rotate(password, 3, 0, 64, 'l');
    for (int i = 0; i < 64; i++) printf("%c", password[i]);
}
void number2() {
    char password[64] = {}, trashCan = '0';
    trashCan = getchar();
    int keyRFC[8] = {4, 3, 1, 2, 7, 6, 5, 8};
    for (int i = 0; i < 64; i++) {
        password[i] = getchar();
    }
    rotate(password, 11, 0, 64, 'r');
    TC(password, 74, 0, 64, 'a');
    rotate(password, 1, 0, 32, 'r');
    rotate(password, 3, 32, 64, 'r');
    RFC(password, keyRFC, 8, 0, 64);
    for (int i = 0; i < 64; i++) printf("%c", password[i]);
}
void number3() {
    char password[64] = {}, trashCan = '0';
    trashCan = getchar();
    int keyRFC1[4] = {3, 2, 4, 1}, keyRFC2[8] = {1, 8, 4, 3, 6, 5, 7, 2};
    for (int i = 0; i < 64; i++) {
        password[i] = getchar();
    }
    RFC(password, keyRFC1, 4, 0, 64);
    caesarCipher(8, password, 0, 32);
    RFC(password, keyRFC2, 8, 32, 64);
    swap(password,  0, 32);
    TC(password, 602, 0 , 64, 'd');
    rotate(password, 7, 0, 64, 'r');
    for (int i = 0; i < 64; i++) printf("%c", password[i]);
}
void number4() {
    char password[64] = {}, trashCan = '0', keyVC[8] = {'v', 'i', 'g', 'e', 'n', 'e', 'r', 'e'};
    trashCan = getchar();
    for (int i = 0; i < 64; i++) {
        password[i] = getchar();
    }
    VC(keyVC, 8, password, 0, 32);
    swap(password, 0, 16);
    TC(password, 3, 0, 32, 'a');
    rotate(password, 24, 32, 64, 'l');
    rotate(password, 19, 0, 64, 'r');
    for (int i = 0; i < 64; i++) printf("%c", password[i]);
}
void number5() {
    char password[64] = {}, trashCan = '0';
    int key1[8] = {3, 1, 7, 6, 4, 5, 2, 8}, key2[4] = {2,4,1,3};
    trashCan = getchar();
    for (int i = 0; i < 64; i++) {
        password[i] = getchar();
    }
    RFC(password, key1, 8, 0, 64);
    caesarCipher(10, password, 0, 32);
    RFC(password, key2, 4, 32, 64);
    swap(password, 0, 32);
    TC(password, 52, 0, 64, 'a');
    rotate(password, 7, 0, 64, 'r');
    for (int i = 0; i < 64; i++) printf("%c", password[i]);
}
