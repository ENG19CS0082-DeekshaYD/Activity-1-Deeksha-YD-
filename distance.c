//WAP to find the distance between two point using 4 functions.

#include<stdio.h>
#include<math.h>
float input(char b1[])
{
    float a;
    printf("Enter the %s co-ordinate:",b1);
    scanf("%f", &a);
    return a;
}
float compute_distance(float a1,float a2,float b1,float b2)
{
    float dist=sqrt((a2-a1)*(a2-a1)+(b2-b1)*(b2-b1));
    return dist;
}
void output(float a1,float a2, float b1, float b2,float result)
{
    printf("Distance between (%f,%f) and (%f,%f) is :%f",a1,a2,b1,b2,result);
}
int main()
{
    float x1,x2,y1,y2,D;
    x1=input("x1");
    y1=input("y1");
    x2=input("x2");
    y2=input("y2");
    D=compute_distance(x1,x2,y1,y2);
    output(x1,y1,x2,y2,D);
    return 0;
}
