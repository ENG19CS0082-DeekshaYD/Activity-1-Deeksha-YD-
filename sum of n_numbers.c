//Write a program to add n different numbers

#include<stdio.h>
int input_n()
{
    int a;
    printf("Enter numbers of elements to be added:");
    scanf("%d",&a);
    return a;
}
void input_array(int n,float a[n])
{
    for(int i=0;i<n;i++)
    {
    printf("Enter the %d th element of an array:",i);
    scanf("%f",&a[i]);
    }
}
float array_sum(int n,float a[n])
{
    float sum=0;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
    }
    return sum;
}
void show_results(int n, float a[n], float sum)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%f=%.2f",a[i],sum);
    }
}
int main()
{
    int n=input_n();
    float a[n];
    input_array(n,a);
    float sum=array_sum(n,a);
    show_results(n,a,sum);
    return 0;
}
