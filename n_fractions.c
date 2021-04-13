//WAP to find the sum of n fractions.

#include <stdio.h>

struct fraction
{
    int Num,Deno;
};
typedef struct fraction Fract;
int get_n(int n)
{
    printf("enter the no of fractions to be added:");
    scanf("%d",&n);
    return n;
}
Fract input(char a[])
{    
    Fract temp;
    printf("enter the value of %s:",a);
    scanf("%d%d",&temp.Num,&temp.Deno);
    return temp;
}
void get_fract(int n, Fract a[])
{
    for(int i=0;i<n;i++)
    {
        printf("For fraction %d\n",(i+1));
        a[i]=input("numerator/denominator");
    }
}
Fract sum(Fract a, Fract b)
{
    Fract res;
    if (a.Deno==b.Deno)
    {
        res.Deno=a.Deno;
        res.Num=a.Num+b.Num;
    }
    else
    {
        res.Deno=a.Deno*b.Deno;
        res.Num=(a.Num*b.Deno)+(b.Num*a.Deno);
    }
    return res;
}
int find_gcd(int a, int b)
{
    int temp;
    while(a!=0)
    {
        temp=a;
        a=b%a;
        b=temp;
    }
     return b;
}
Fract compute_sum(Fract c)
{
    int gcd=find_gcd(c.Num,c.Deno);
    c.Num=c.Num/gcd;
    c.Deno=c.Deno/gcd;
    return c;
}

Fract add_fraction(int n, Fract c, Fract a[])
{
    for(int i=0;i<n;i++)
    {
        c=sum(c,a[i]);
    }
    return c;
}
void output(Fract res)
{
    printf("The final sum is %d/%d",res.Num,res.Deno);
}
int main()
{
    int n=get_n(n);
    Fract c,a[n],fraction,result;
    c.Num=0;
    c.Deno=1;
    get_fract(n,a);
    fraction=add_fraction(n,c,a);
    result=compute_sum(fraction);
    output(result);
}


