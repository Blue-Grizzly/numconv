#include <stdio.h>
#include "numconv2.h"


int dec_to_int(char *string) {
    int value = 0;
    int isNegative = 0;

    if (*string == '-') {
        string++;
        isNegative = 1;
    }

    while (is_digit(*string))
    {
        value *= 10;
        value += *string - '0';
        string++;
    }
    
    if (isNegative == 1) {
        value *= -1;
    }
    
    return value;
}

void int_to_dec(int num, char* string) {
    int remain = num;
    char *start = string;
    do
    {
        int digit = remain % 10;
        *string = digit + '0';
        string++;
        remain /= 10;
    } while (remain > 0);

    *string = '\0';
    reverse_string(start, string);
}

int oct_to_int(char *string) {
    int value = 0;

    while (is_oct_digit(*string))
    {
        value <<= 3;
        printf("%d\n", *string);
        value += *string & 0b111; 

        string++;
    }

    return value;
}

void int_to_oct(int num, char *string) {
    int remain = num;
    char *start = string; 
    
    do {
        int digit = remain & 0b111;

        *string = digit | 0b00110000;

        string++;
        remain >>= 3;
    } while (remain > 0);
    
    *string = '\0';
    reverse_string(start, string);
}

int hex_to_int(char *string) {
    int value = 0;

    while (is_hex_digit(*string))
    {
        value <<= 4; 
        char c = *string;

        if (c > 0x39) { 
            c -= 7;
        }

        value += c & 0b1111;
        string++;
    }

    return value;
}

void int_to_hex(int num, char *string) {
    int remain = num;
    char *start = string;
    
    do {
        int digit = remain & 0xF;

        if (digit < 10) {
            *string = digit | 0b00110000;
        } else {
            *string = (0x41 & 0xF0) | (digit - 9); 
        }

        string++;
        remain >>= 4;
    } while (remain > 0);
    
    *string = '\0';
    reverse_string(start, string);
}

int bin_to_int(char *string) {
    int value = 0;

    while (is_bin_digit(*string))
    {
        value <<= 1;

        value |= (*string & 0b1);

        string++;
    }

    return value;
}

void int_to_bin(int num, char *string) {
    int remain = num;
    char *start = string;
    
    do {
        int digit = remain & 0b1; 
        *string = digit | 0b00110000; 
        string++;
        remain >>= 1;
    } while (remain > 0);
    

    *string = '\0';
    reverse_string(start, string);
}

int is_bin_digit(char c) {
    return (c == '0' || c == '1') ? 1 : 0;
}

int is_hex_digit(char c) {
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) ? 1 : 0;
}

int is_oct_digit(char c) {
    return (c >= '0' && c <= '8') ? 1 : 0;
}

int is_digit(char c) {
    return (c >= '0' && c <= '9') ? 1 : 0;
}

void reverse_string(char *start, char *string) {
    int len = string - start;
    for (int i = 0; i < len / 2; i++) {
        char temp = start[i];
        start[i] = start[len - i - 1];
        start[len - i - 1] = temp;
    }
}