# Egyptian fractions

#include<stdio.h>
struct fractions
{
    int num;
    int den;
};
struct operations
{
    int n_den;
    struct fractions dens[100];
};
int input_n()
{
    int a;
    scanf("%d",&a);
    return a;
}
int oneinput()
{
    int d;
    scanf("%d",&d);
    return d;
}
void n_inputs(int n,struct operations s[100])
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i].n_den);
        for(int j=0;j<s[i].n_den;j++)
        {
            s[i].dens[j].den=oneinput();
            s[i].dens[j].num=1;
        }
    }
}
int gcd(int num1,int num2)
{
    int div;
    for(int i=1;i<=num1 && i<=num2;i++)
    {
        if(num1%i==0 && num2%i==0)
        div=i;
    }
    return div;
}
struct fractions simplify(struct fractions simp,int di)
{
    simp.num=simp.num/di;
    simp.den=simp.den/di;
    return simp;
}
struct fractions calone(struct operations ans)
{
    struct fractions res;
    res.num=ans.dens[0].num;
    res.den=ans.dens[0].den;
    int g;
    for(int i=1;i<ans.n_den;i++)
    {
        res.num=(res.num*ans.dens[i].den)+(ans.dens[i].num*res.den);
        res.den=(res.den*ans.dens[i].den);
    }
    g=gcd(res.num,res.den);
    return simplify(res,g);
}
void caln(int n,struct operations s[],struct fractions r[])
{
    for(int i=0;i<n;i++)
    {
    r[i]=calone(s[i]);
}
}
void showone(struct operations se,struct fractions re)
{
    int i;
    for(i=0;i<se.n_den-1;i++)
    {
        printf("%d/%d + ",se.dens[i].num,se.dens[i].den);
    }
    printf("%d/%d=%d/%d\n",se.dens[i].num,se.dens[i].den,re.num,re.den);
}
void shown(int n,struct operations s[],struct fractions r[])
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        showone(s[i],r[i]);
    }
}
int main()
{
    int n=input_n();
    struct fractions res[n];
    struct operations set[100];
    n_inputs(n,set);
    caln(n,set,res);
    shown(n,set,res);
    return 0;
}
