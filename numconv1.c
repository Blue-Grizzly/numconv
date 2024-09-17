char * string_reverse(char* str, int length)
{
    int i = 0;
    char temp;
    for(i = 0; i < length/2; i++)
    {
        temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
    return str;
}

int is_digit( char c )
{
    if( c >= '0' && c <= '9' )
        return 1;
    return 0;
}

int is_bin_digit( char c )
{
    if( c == '0' || c == '1' )
        return 1;
    return 0;
}

int is_hex_digit( char c )
{
    if( (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f') )
        return 1;
    return 0;
}

int is_oct_digit( char c )
{
    if( c >= '0' && c <= '7' )
        return 1;
    return 0;
}

int dec_to_integer(char *str)
{
    int num = 0;
    int j = 0;
    int negative = 0;

    while(str[j] != '\0')
    {
        if(str[0] == 45){
        negative = 1;
        }

        if(is_digit(str[j])){
            num = num * 10 + str[j] - '0';
        }
        j++;
    }
    if (negative == 1){
        num = -num;
    }

    return num;
}

void int_to_dec(int number, char str[])
{
    int remain = number;
    int nextdigit = 0;
    int i = 0;

   do
    {
        nextdigit = remain % 10;
        remain = remain / 10;
        str[i++]= nextdigit + '0';
    }  while (remain > 0);
    str[i] = 0;

    string_reverse(str, i);
}

int bin_to_int(char str[])
{
    int num = 0;
    int i = 0;

    while(str[i] != '\0')
    {
        if(is_bin_digit(str[i])){
            num = num * 2 + str[i] - '0';
        }
        i++;
    }
    return num;
}

int dec_to_int(char str[])
{
    int num = 0;
    int i = 0;

    while(str[i] != '\0')
    {
        if(is_digit(str[i])){
            num = num * 10 + str[i] - '0';
        }
        i++;
    }
    return num;
}

int hex_to_int(char str[])
{
    int num = 0;
    int i = 0;

    while(str[i] != '\0')
    {
        if(is_digit(str[i])){
            num = num * 16 + str[i] - '0';
        }
        else if(str[i] >= 'A' && str[i] <= 'F'){
            num = num * 16 + str[i] - 'A' + 10;
        }
        else if(str[i] >= 'a' && str[i] <= 'f'){
            num = num * 16 + str[i] - 'a' + 10;
        }
        i++;
    }
    return num;
}

int oct_to_int(char str[])
{
    int num = 0;
    int i = 0;

    while(str[i] != '\0')
    {
        if(is_oct_digit(str[i])){
            num = num * 8 + str[i] - '0';
        }
        i++;
    }
    return num;
}

void int_to_bin(int number, char str[])
{
    int negative = 0;
    if(number < 0)
    {
        negative = 1;
        number = -number;
    }

    int remain = number;
    int nextdigit = 0;
    int i = 0;

    do
    {
        nextdigit = remain % 2;
        remain = remain / 2;
        str[i++]= nextdigit + '0';
    }  while (remain > 0);

    if(negative)
    {
        str[i++] = '-';
    }

    str[i] = 0;

    string_reverse(str, i);
}

void int_to_hex(int number, char str[])
{
    int negative = 0;
    if(number < 0)
    {
        negative = 1;
        number = -number;
    }

    int i = 0;
    int remain = number;
    int nextdigit = 0;

    do
    {
        nextdigit = remain % 16;
        remain = remain / 16;
        if(nextdigit < 10)
        {
            str[i++]= nextdigit + '0';
        }
        else
        {
            str[i++]= nextdigit - 10 + 'A';
        }
    }  while (remain > 0);

    if(negative)
    {
        str[i++] = '-';
    }

    str[i] = 0;

    string_reverse(str, i);
}

void int_to_oct(int number, char str[])
{
    int negative = 0;
    if(number < 0)
    {
        negative = 1;
        number = -number;
    }
    int remain = number;
    int nextdigit = 0;
    int i = 0;

    do
    {
        nextdigit = remain % 8;
        remain = remain / 8;
        str[i++]= nextdigit + '0';
    }  while (remain > 0);

    if(negative)
    {
        str[i++] = '-';
    }

    str[i] = 0;

    string_reverse(str, i);
}

