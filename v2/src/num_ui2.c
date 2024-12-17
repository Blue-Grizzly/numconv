#include <stdio.h>
#include "num_ui2.h"
#include "numconv2.h"

void display_main_menu() {
    puts("\nChoose Number system to convert:");
    puts("d) decimals");
    puts("b) binary");
    puts("h) hexidecimals");
    puts("o) octodecimals");
    puts("x) Exit");
}

void display_bin_menu() {
    puts("\n Binary:");
    puts("a) To");
    puts("b) From");
    puts("x) Exit");
}

void display_oct_menu() {
    puts("\n Octodecimals:");
    puts("a) To");
    puts("b) From");
    puts("x) Exit");
}

void display_hex_menu() {
    puts("\n Hexidecimals:");
    puts("a) To hexidecimals");
    puts("b) From hexidecimals");
    puts("x) Exit");
}

void display_dec_menu() {
    puts("\n Decimals:");
    puts("a) To");
    puts("b) From");
    puts("x) Exit");
}


void get_string_value(char *str) {
    printf("\nEnter value: ");
    scanf("%s", str);
}

int get_int_value() {
    printf("\nEnter value:");
    int val;
    scanf("%d", &val);
    return val;
}

int main()
{
    while (1)
    {
        char input[255];
        display_main_menu();

        scanf(" %c", input);

        if (*input == 'x'){
            break;
        }

        char type[255];
        char value[255];
        char result[255];

        if (*input == 'd'){
            display_dec_menu();
            scanf(" %c", type);

            if (*type == 'x'){
                continue;
            }

            if (*type == 'a') {
                int v = get_int_value();
                int_to_dec(v, result);
                printf("\nResult is %s\n", result);
            } else if (*type == 'b') {
                get_string_value(value);
                int final = dec_to_int(value);
                printf("\nResult is %d\n", final);
            }


        }  else if (*input == 'b') {
            display_bin_menu();
            scanf(" %c", type);

            if (*type == 'x'){
                continue;
            }

            if (*type == 'a') {
                int v = get_int_value();
                int_to_bin(v, result);
                printf("\nResult is %s\n", result);
            } else if (*type == 'b') {
                get_string_value(value);
                int final = bin_to_int(value);
                printf("\nResult is %d\n", final);
            }

        } else if (*input == 'h') {
            display_hex_menu();
            scanf(" %c", type);

            if (*type == 'x'){
                continue;
            }

            if (*type == 'a') {
                int v = get_int_value();
                int_to_hex(v, result);
                printf("\nResult is %s\n", result);
            } else if (*type == 'b') {
                get_string_value(value);
                int final = hex_to_int(value);
                printf("\nResult is %d\n", final);
            }
 
        } else if (*input == 'o') {
            display_oct_menu();
            scanf(" %c", type);

            if (*type == 'x'){
                continue;
            }

            if (*type == 'a') {
                int v = get_int_value();
                int_to_oct(v, result);
                printf("\nResult is %s\n", result);
            } else if (*type == 'b') {
                get_string_value(value);
                int final = oct_to_int(value);
                printf("\nResult is %d\n", final);
            }

        }

    }
    

    return 0;
}
