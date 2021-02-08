//Write a program to add two user input numbers using 4 functions.

#include<stdio.h>

float input()
{   
    float number;
    printf("Enter Number:");
    scanf("%f",&number);
    return number;
}
float add(float num1, float num2)
{
    return num1+num2;
}
void output(float n1,float n2,float sum)
{
    printf("Sum of %f and %f is : %f",n1,n2,sum);
}
int main()
{
    float x,y,z;
    x=input();
    y=input();
    z=add(x,y);
    output(x,y,z);
    return 0;
}
