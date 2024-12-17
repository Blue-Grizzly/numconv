#include <stdio.h>
#include"numberconv.h"
#include"num_ui.h"

int main()
{

    printf("  _   _                 _                  _____                          _            \n");
    printf(" | \\ | |               | |                / ____|                        | |           \n");
    printf(" |  \\| |_   _ _ __ ___ | |__   ___ _ __  | |     ___  _ ____   _____ _ __| |_ ___ _ __ \n");
    printf(" | . ` | | | | '_ ` _ \\| '_ \\ / _ \\ '__| | |    / _ \\| '_ \\ \\ / / _ \\ '__| __/ _ \\ '__|\n");
    printf(" | |\\  | |_| | | | | | | |_) |  __/ |    | |___| (_) | | | \\ V /  __/ |  | ||  __/ |   \n");
    printf(" |_| \\_|\\__,_|_| |_| |_|_.__/ \\___|_|     \\_____\\___/|_| |_|\\_/ \\___|_|   \\__\\___|_|   \n");

    char choice;
    while(1)
    {
        char s1[255];
        char input[255];
        int num;
        print_menu();
        choice = get_choice();
        switch (choice)
        {
        case 'q':
            return 0;
            break;
        case '1':
            start_decimal:
            printf("Enter a decimal number: ");
            fgets(input, 255, stdin);

            for(int i = 0; input[i] != '\0'; i++)
            {
                printf("%c\n", input[i]);
                if(is_digit(input[i]) || input[i] == '-' || input[i] == '\0' || input[i] == '\n')
                {
                    continue;
                }
                else
                {
                    printf("Invalid input\n");
                    goto start_decimal;
                }
            }

            num = dec_to_integer(input);

            print_decimal_menu();

            choice = get_choice();

            switch (choice)
            {
            case '1':
                int_to_bin(num, s1);
                printf("Binary: \033[4m%s\033[0m\n", s1);
                break;
            case '2':
                int_to_hex(num, s1);
                printf("Hexadecimal: \033[4m%s\033[0m\n", s1);
                break;
            case '3':
                int_to_oct(num, s1);
                printf("Octal: \033[4m%s\033[0m\n", s1);
                break;
            case '4':
                printf("Integer: \033[4m%d\033[0m\n", num);
                break;
            case 'b':
                break;
            default:
                break;
            }

            break;
        case '2':
            start_binary:
            printf("Enter a binary number: ");
            fgets(input, 255, stdin);
            
            for(int i = 0; input[i] != '\0'; i++)
            {
                printf("%c\n", input[i]);
                if(is_bin_digit(input[i]) || input[i] == '-' || input[i] == '\0' || input[i] == '\n')
                {
                    continue;
                }
                else
                {
                    printf("Invalid input\n");
                    goto start_binary;
                }
            }

            num = bin_to_int(input);
            print_binary_menu();

            choice = get_choice();

            switch (choice)
            {
            case '1':
                printf("Decimal: \033[4m%d\033[0m\n", num);
                break;
            case '2':
                int_to_hex(num, s1);
                printf("Hexadecimal: \033[4m%s\033[0m\n", s1);
                break;
            case '3':
                int_to_oct(num, s1);
                printf("Octal: \033[4m%s\033[0m\n", s1);
                break;
            case '4':
                printf("Integer: \033[4m%d\033[0m\n", num);
                break;
            case 'b':
            default:
                break;
            }
            break;
        case '3':
            start_hexadecimal:
            printf("Enter a hexadecimal number: ");
            fgets(input, 255, stdin);
            
            for(int i = 0; input[i] != '\0'; i++)
            {
                printf("%c\n", input[i]);
                if(is_hex_digit(input[i]) || input[i] == '-' || input[i] == '\0' || input[i] == '\n')
                {
                    continue;
                }
                else
                {
                    printf("Invalid input\n");
                    goto start_hexadecimal;
                }
            }

            num = hex_to_int(input);
            print_hexadecimal_menu();

            choice = get_choice();

            switch (choice)
            {
            case '1':
                printf("Decimal: \033[4m%d\033[0m\n", num);
                break;
            case '2':
                int_to_bin(num, s1);
                printf("Binary: \033[4m%s\033[0m\n", s1);
                break;
            case '3':
                int_to_oct(num, s1);
                printf("Octal: \033[4m%s\033[0m\n", s1);
                break;
            case '4':
                printf("Integer: \033[4m%d\033[0m\n", num);
                break;
            case 'b':
            default:
                break;
            }
            break;
        case '4':
            start_octal:
            printf("Enter an octal number: ");
            fgets(input, 255, stdin);
            
            for(int i = 0; input[i] != '\0'; i++)
            {
                printf("%c\n", input[i]);
                if(is_oct_digit(input[i]) || input[i] == '-' || input[i] == '\0' || input[i] == '\n')
                {
                    continue;
                }
                else
                {
                    printf("Invalid input\n");
                    goto start_octal;
                }
            }

            num = oct_to_int(input);
            print_decimal_menu();

            choice = get_choice();

            switch (choice)
            {
            case '1':
                int_to_bin(num, s1);
                printf("Binary: %s\n", s1);
                break;
            case '2':
                int_to_hex(num, s1);
                printf("Hexadecimal: \033[4m%s\033[0m\n", s1);
                break;
            case '3':
                printf("Octal: \033[4m%d\033[0m\n", num);
                break;
            case '4':
                printf("Integer: \033[4m%d\033[0m\n", num);
                break;
            case 'b':
        default:
            break;
        }
        
        }
    }
    return 0;
}
void print_menu()
{
    printf("======================================================================================\n");
    printf("1. Convert From Decimal                    \n");
    printf("2. Convert From Binary                     \n");
    printf("3. Convert From Hexadecimal                \n");
    printf("4. Convert From Octal                      \n");
    printf("q. Quit                                    \n");
    printf("======================================================================================\n");
    printf("Enter your choice: ");
}

void print_decimal_menu()
{
    printf("======================================================================================\n");
    printf("1. Convert to Binary                       \n");
    printf("2. Convert to Hexadecimal                  \n");
    printf("3. Convert to Octal                        \n");
    printf("4. Convert to Integer                      \n");
    printf("b. Back                                    \n");
    printf("======================================================================================\n");
    printf("Enter your choice: ");
}

void print_binary_menu()
{
    printf("======================================================================================\n");
    printf("1. Convert to Decimal                      \n");
    printf("2. Convert to Hexadecimal                  \n");
    printf("3. Convert to Octal                        \n");
    printf("4. Convert to Integer                      \n");
    printf("b. Back                                    \n");
    printf("======================================================================================\n");
    printf("Enter your choice: ");
}

void print_hexadecimal_menu()
{
    printf("======================================================================================\n");
    printf("1. Convert to Decimal                      \n");
    printf("2. Convert to Binary                       \n");
    printf("3. Convert to Octal                        \n");
    printf("4. Convert to Integer                      \n");
    printf("b. Back                                    \n");
    printf("======================================================================================\n");
    printf("Enter your choice: ");
}


char get_choice()
{
    char choice;
    scanf(" %c", &choice);
    clear_input_buffer();
    return choice;
}

void clear_input_buffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
