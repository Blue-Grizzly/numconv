#include<stdio.h>
#include"numberconv.h"

int main()
{
    char s1[100];
    char s2[100];
    char s3[100];

    char* d = "-1073626914";
    char* d2 = "-559038242";
    char* d3 = "-2000000000";
    char* d4 = "123123123";


    int_to_bin(dec_to_integer(d), s1);
    int_to_hex(dec_to_integer(d), s2);
    int_to_oct(dec_to_integer(d), s3);

    printf("%s in decimal is %d in int\n", d, dec_to_integer(d));
    printf("%s in decimal is %s in binary\n", d, s1);
    printf("%s in decimal is %s in hexadecimal\n", d, s2);
    printf("%s in decimal is %s in octal\n", d, s3);

    printf("%s binary is %d in int\n", s1, bin_to_int(s1));
    printf("%s octal is %d in int\n", s3, oct_to_int(s3));
    printf("%s hexadecimal is %d in int\n", s2, hex_to_int(s2));

    int_to_bin(dec_to_integer(d2), s1);
    int_to_hex(dec_to_integer(d2), s2);
    int_to_oct(dec_to_integer(d2), s3);

    printf("%s in decimal is %d in int\n", d2, dec_to_integer(d2));
    printf("%s in decimal is %s in binary\n", d2, s1);
    printf("%s in decimal is %s in hexadecimal\n", d2, s2);
    printf("%s in decimal is %s in octal\n", d2, s3);

    printf("%s binary is %d in int\n", s1, bin_to_int(s1));
    printf("%s octal is %d in int\n", s3, oct_to_int(s3));
    printf("%s hexadecimal is %d in int\n", s2, hex_to_int(s2));

    int_to_bin(dec_to_integer(d3), s1);
    int_to_hex(dec_to_integer(d3), s2);
    int_to_oct(dec_to_integer(d3), s3);

    printf("%s in decimal is %d in int\n", d3, dec_to_integer(d3));
    printf("%s in decimal is %s in binary\n", d3, s1);
    printf("%s in decimal is %s in hexadecimal\n", d3, s2);
    printf("%s in decimal is %s in octal\n", d3, s3);

    printf("%s binary is %d in int\n", s1, bin_to_int(s1));
    printf("%s octal is %d in int\n", s3, oct_to_int(s3));
    printf("%s hexadecimal is %d in int\n", s2, hex_to_int(s2));

    printf("%s binary is %d in int\n", s1, bin_to_int(s1));
    printf("%s octal is %d in int\n", s3, oct_to_int(s3));
    printf("%s hexadecimal is %d in int\n", s2, hex_to_int(s2));

    printf("%s binary is %d in int\n", s1, bin_to_int(s1));
    printf("%s octal is %d in int\n", s3, oct_to_int(s3));
    printf("%s hexadecimal is %d in int\n", s2, hex_to_int(s2));
    
    
}