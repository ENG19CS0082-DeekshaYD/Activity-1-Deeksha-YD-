//WAP to find the sum of two fractions.

#include<stdio.h>
struct fraction
{
    int Num,Deno;
};
typedef struct fraction Fract;
Fract input(char a[])
{    
    Fract temp;
    printf("enter the value of %s:",a);
    scanf("%d%d",&temp.nr,&temp.dr);
    return temp;
}
int find_gcd(int a, int b)
{
    int temp;
	while (a!=0)
	{
	    temp=a;
	    a=b%a;
	    b=temp;
	}
	return b;
}
Fract simplify(Fract sum)
{
    int gcd=find_gcd(sum.Num,sum.Deno);
    sum.Num=sum.Num/gcd;
    sum.Deno=sum.Deno/gcd;
    return sum;
}
Fract add_fraction(Fract f1, Fract f2)
{   
    Fract sum;
    sum.Num=(f1.Num*f2.Deno)+(f2.Num*f1.Deno);
    sum.Deno=f1.Deno*f2.Deno;
    sum=simplify(sum);
    return sum;
}
void display_sum(Fract f1, Fract f2, Fract sum)
{
    printf("The sum of %d/%d and %d/%d is: %d/%d.\n",f1.Num,f1.Deno,f2.Num,f2.Deno,sum.Num,sum.Deno);
}
int main()
{
   Fract f1,f2,sum;
   f1=input("a/b");
   f2=input("c/d");
   sum=add_fraction(f1,f2);
   display_sum(f1,f2,sum);
   return 0;
}
