#include <stdio.h>

int strlength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void strCopy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
}

void strConcatination(char *dest1, const char *src1)
{
    int i = 0, j = 0;
    while (dest1[i] != '\0')
    {
        i++;
    }

    while (src1[j] != '\0')
    {
        dest1[i] = src1[j];
        i++;
        j++;
    }
}

int strCompare(const char *str1, const char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return 0;
        i++;
    }
    return 1;
}

void strReverse(char *str3)
{
    int start = 0, end = 0;

    while (str3[end] != '\0')
        end++;
    end--;

    while (start < end)
    {
        char temp = str3[start];
        str3[start] = str3[end];
        str3[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char str[] = "Hello, world!";

    char destination[] = "Who are You?";

    // strCopy(destination, str);
    // printf("The length of this string is %d\n", strlength(destination));
    // printf("copied String is: %s\n", destination);
    // strConcatination(str, destination);
    // printf("Concatinated string is: %s\n", str);
    // printf("The length of this string is %d\n", strlength(str));

    // if(strCompare(str, destination))
    //     printf("These strings are equal\n");
    //     else printf("These strings are unequal\n");
    strReverse(str);
    printf("Reversed string is: %s\n", str);

    return 0;
}