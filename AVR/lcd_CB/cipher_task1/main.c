#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_LEN 100
char* decription(char* msg, int key);
char* encription(char* msg, int key);
int main()
{

    char *s=malloc(sizeof(char)*MAX_LEN);
    fgets(s, MAX_LEN, stdin);
    for (int i = 0; i < strlen(s); i++)
    {
        if (i == strlen(s)-1)
        {
            s[i] = ' ';
        }
    }
    printf("Please, Enter the Encryption Key");
    printf("\n");
    int k = fgetc(stdin);
    printf("%s", encription(s, k));
    printf("\n");
    printf("%s", decription(s, k));
    return 0;
}
char* encription(char* msg, int key)
{
    if (!(key < 0) && !(key > 255))
    {
        if (key > 26)
        {
            key = key % 26;
            printf("\n");
            printf("%d", key);
        }
    }
    for (int i = 0; i < strlen(msg); i++)
    {
        if (!isdigit(msg[i]) && msg[i] != ' ' && isupper(msg[i]))
        {
            if (( msg[i] + key) > 90)
            {
                int dif = ((int) msg[i] + key) - 90;
                msg[i] = 65 + dif;
            }
            else
            {
                msg[i] = (int) msg[i] + key;
            }
        }
        else if (!isdigit(msg[i]) && msg[i] != ' ' && !isupper(msg[i]))
        {
            if (( msg[i] + key) > 122)
            {
                int dif = ((int) msg[i] + key) - 122;
                msg[i] = 97 + dif;
            }
            else
            {
                msg[i] = (int) msg[i] + key;
            }
        }
        else{

        }
    }
    return msg;
}
char* decription(char* msg, int key)
{
    if (!(key < 0) && !(key > 255))
    {
        if (key > 26)
        {
            key = key % 26;
        }
    }
    for (int i = 0; i < strlen(msg); i++)
    {
        if (!isdigit(msg[i]) && msg[i] != ' ' && isupper(msg[i]))
        {
            if (( msg[i] - key < 65))
            {
                int dif = 65 - ((int) msg[i] - key);
                msg[i] = 90 - dif;
            }
            else
            {
                msg[i] = (int) msg[i] - key;
            }
        }
        else if (!isdigit(msg[i]) && msg[i] != ' ' && !isupper(msg[i]))
        {
            if ((int) msg[i] - key < 97)
            {
                int dif = 97 - ((int) msg[i] - key);
                msg[i] = 122 - dif;
            }
            else
            {
                msg[i] = (int) msg[i] - key;
            }
        }
        else{

        }
    }
    return msg;
}
