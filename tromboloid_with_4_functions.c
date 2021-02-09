//WAP to find the volume of a tromboloid using 4 functions.

#include<stdio.h>
float input(char b)
{
  float a;
  printf("Enter the value of %c :",b);
  scanf("%f",&a);
  return a;
}
float find_vol(float a,float b,float c)
{
  float volume=(float)1/(float)3*((a*b*c)+(c/b));
  return volume;
}
void output(float volume)
{
  printf("Volume of tromboloid is: %f",volume);
}
int main()
{
  float h,b,d,V;
  h=input('h');
  b=input('b');
  d=input('d');
  V=find_vol(h,b,d);
   output(V);
return 0;
}
