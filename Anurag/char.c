#include <stdio.h>

struct str1 {
    unsigned int f1:1;
    unsigned int f2:2;
    unsigned int f3:1;
    // char ca[48];
} my_str;



struct str1 my_str_tab[20];

union {
    int i;
    float f;
    char c;
    // char ca[48];
} my_uni;


void
main()
{

    int x;
    int *xp;
    int f1, f2, f3;

    x = 20;

    xp = &x;

    *xp = 200;

    my_str.f1 = 1;
    my_str.f2 = 2;
    my_str.f3 = 1;



    printf("struct size %ld union %ld\n", sizeof(my_str), sizeof(my_uni));

    // my_str.c = 'a';
    // // my_str.i = 500000;

    // f1 = my_str.f1;
    // f2 = my_str.f2;
    // f3 = my_str.f3;
    //

    printf("str.f1 %u str.f2 %u str.f3 %u\n", my_str.f1,  my_str.f2, my_str.f3);
    // printf("str.i %p str.f %p str.c %p\n", &my_str.i, &my_str.f, &my_str.c);
    //
    // my_uni.c = 'a';
    // // my_uni.i = 500000;
    // printf("uni.i %d uni.f %f uni.c %c\n", my_uni.i, my_uni.f, my_uni.c);
    // printf("uni.i %p uni.f %p uni.c %p\n", &my_uni.i, &my_uni.f, &my_uni.c);



    // unsigned char    ch = '1';
    // int     i;
    // signed long    j;
    // float   k;
    //
    // /*
    // 4 bits: 0000, 1111
    // 8 bits        00000000, 11111111
    // unsigned    0 -- 2**8 (256-1) = 255
    // signed        -20, 20
    //               000100100
    //               100000110
    // *             000000000 == 0
    // *             100000000    (2s complement system to represent -ve numbers)
    // *  +ve, -ve, print there values in 0x.
    // */
    //
    // /*
    // string in C
    // */
    //
    // char tab[100];
    //
    // strcpy(tab, "hello world");
    //
    // tab[11] = '\0';
    // tab[11] = 'A';
    //
    //
    // printf("%c %d %d", ch, (int)ch, ch - '0');
    //
    // x = y + z / 3;
    // x = (y / z) + ((4 / 2) * 6);
    //
    // if (x < y) {
    //     printf("x is greater\n");
    // } else (y > z) {
    //     printf("y is greate\n" );
    //
    // }

}
