// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

}

/*

void add (int, int);
void subtract (int, int);
void multiply (int, int);
void divide (int, int);

int main() {

    void (*ptr_func_arr[])(int, int) = {add, subtract, multiply, divide};
    //add = 0
    //subtract = 1
    //multiply = 2
    //divide = 3
    int a, b, op;

    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Enter the operation: ");
    scanf("%d", &op);

    if (op >= 0 && op > sizeof(ptr_func_arr))
    {
        return 0;
    }
    else
    {
        (*ptr_func_arr[op])(a,b);
    }

}
void add (int x, int y) {
    printf("The result of the addition = %d\n", x+y);
}
void subtract (int x, int y) {
    printf("The result of the subtraction = %d\n", x-y);
}
void multiply (int x, int y) {
    printf("The result of the myltiplication = %d\n", x*y);
}
void divide (int x, int y) {
    printf("The result of the division = %f\n", (float)(x/y));
}

  int min, max, avg;
    int students[3][4];
    for(int i = 0; i < 3; i++ ) {
        for (int j= 0; j < 4 ; j++)
        {
            students[i][j] = (rand() % (100 - 0 + 1)) + 0;
            printf("  %d", students[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < 3; i++) {
        min = 0;
        max = 0;
        avg = 0;
        for(int j = 0 ; j < 4; j++)
        {
            min = students[i][0];
            max = students[i][0];
            if (min > students[i][j])
            {
                min = students[i][j];
            }
            else if (max < students[i][j])
            {
                max = students[i][j];
            }
            avg += students[i][j];
        }
        avg = avg / 4;
        printf("the min value for the %d", i);
        printf(" student %d", min);
        printf("\n");
        printf("the max value for the %d", i);
        printf(" student %d", max);
        printf("\n");
        printf("the avarage value for the %d", i);
        printf(" student %d", avg);
        printf("\n");



    int x, y, z;`
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    printf("Enter z: ");
    scanf("%d", &z);
    if(x + y > z && y + z > x && x + z > y) {
        printf("triangle");
        if ((x*x)+(y*y) == (z*z) || (x*x)+(z*z) == (y*y) || (y*y)+(z*z) == (x*x)) {
            printf("       right side triangle ");
        }
        else
        {
            printf("      not right angled");
        }
    }
    else {
    printf("not a triangle");
    }
*/
