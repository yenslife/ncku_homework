#include <stdio.h>

//Arabic to Roman
int main() {
    int num, i1, i2, i3, i4;
    scanf("%d", &num);
    if (num >= 1000) {
        i4 = num / 1000;
        i3 = (num - i4 * 1000) / 100;
        i2 = (num - i4 * 1000 - i3 * 100) / 10;
        i1 = (num - i4 * 1000 - i3 * 100 - i2 * 10);
    } else if (100 <= num && num < 1000) {
        i3 = num / 100;
        i2 = (num - i3 * 100) / 10;
        i1 = num - i3 * 100 - i2 * 10;
    } else if (10 <= num && num < 100) {
        i2 = num / 10;
        i1 = num - i2 * 10;
    } else {
        i1 = num;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    if (num >= 1000) {
        switch (i4) {
            case 1:
                printf("M");
                break;
            case 2:
                printf("MM");
                break;
            case 3:
                printf("MMM");
                break;
        }
        switch (i3) {
            case 1:
                printf("C");
                break;
            case 2:
                printf("CC");
                break;
            case 3:
                printf("CCC");
                break;
            case 4:
                printf("CD");
                break;
            case 5:
                printf("D");
                break;
            case 6:
                printf("DC");
                break;
            case 7:
                printf("DCC");
                break;
            case 8:
                printf("DCCC");
                break;
            case 9:
                printf("CM");
                break;
        }
        switch (i2) {
            case 1:
                printf("X");
                break;
            case 2:
                printf("XX");
                break;
            case 3:
                printf("XXX");
                break;
            case 4:
                printf("XL");
                break;
            case 5:
                printf("L");
                break;
            case 6:
                printf("LX");
                break;
            case 7:
                printf("LXX");
                break;
            case 8:
                printf("LXXX");
                break;
            case 9:
                printf("XC");
                break;
        }
        switch (i1) {
            case 1:
                printf("I");
                break;
            case 2:
                printf("II");
                break;
            case 3:
                printf("III");
                break;
            case 4:
                printf("IV");
                break;
            case 5:
                printf("V");
                break;
            case 6:
                printf("VI");
                break;
            case 7:
                printf("VII");
                break;
            case 8:
                printf("VIII");
                break;
            case 9:
                printf("IX");
                break;
        }
    } else if (100 <= num && num < 1000) {
        switch (i3) {
            case 1:
                printf("C");
                break;
            case 2:
                printf("CC");
                break;
            case 3:
                printf("CCC");
                break;
            case 4:
                printf("CD");
                break;
            case 5:
                printf("D");
                break;
            case 6:
                printf("DC");
                break;
            case 7:
                printf("DCC");
                break;
            case 8:
                printf("DCCC");
                break;
            case 9:
                printf("CM");
                break;
        }
        switch (i2) {
            case 1:
                printf("X");
                break;
            case 2:
                printf("XX");
                break;
            case 3:
                printf("XXX");
                break;
            case 4:
                printf("XL");
                break;
            case 5:
                printf("L");
                break;
            case 6:
                printf("LX");
                break;
            case 7:
                printf("LXX");
                break;
            case 8:
                printf("LXXX");
                break;
            case 9:
                printf("XC");
                break;
        }
        switch (i1) {
            case 1:
                printf("I");
                break;
            case 2:
                printf("II");
                break;
            case 3:
                printf("III");
                break;
            case 4:
                printf("IV");
                break;
            case 5:
                printf("V");
                break;
            case 6:
                printf("VI");
                break;
            case 7:
                printf("VII");
                break;
            case 8:
                printf("VIII");
                break;
            case 9:
                printf("IX");
                break;
        }
    } else if (10 <= num && num < 100) {
        switch (i2) {
            case 1:
                printf("X");
                break;
            case 2:
                printf("XX");
                break;
            case 3:
                printf("XXX");
                break;
            case 4:
                printf("XL");
                break;
            case 5:
                printf("L");
                break;
            case 6:
                printf("LX");
                break;
            case 7:
                printf("LXX");
                break;
            case 8:
                printf("LXXX");
                break;
            case 9:
                printf("XC");
                break;
        }
        switch (i1) {
            case 1:
                printf("I");
                break;
            case 2:
                printf("II");
                break;
            case 3:
                printf("III");
                break;
            case 4:
                printf("IV");
                break;
            case 5:
                printf("V");
                break;
            case 6:
                printf("VI");
                break;
            case 7:
                printf("VII");
                break;
            case 8:
                printf("VIII");
                break;
            case 9:
                printf("IX");
                break;
        }
    } else {
        switch (i1) {
            case 1:
                printf("I");
                break;
            case 2:
                printf("II");
                break;
            case 3:
                printf("III");
                break;
            case 4:
                printf("IV");
                break;
            case 5:
                printf("V");
                break;
            case 6:
                printf("VI");
                break;
            case 7:
                printf("VII");
                break;
            case 8:
                printf("VIII");
                break;
            case 9:
                printf("IX");
                break;
        }

    }

    return 0;
}
