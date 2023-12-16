#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN_1 50
#define MAX_LEN_2 50
int main()
{
    char ch;
    char *s=malloc(sizeof(char)*MAX_LEN_1);
    char *sen=malloc(sizeof(char)*MAX_LEN_2);
    scanf("%c\n%s\n%[^\n]s", &ch, s, sen);
    printf("%c\n%s\n%s", ch, s, sen);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
