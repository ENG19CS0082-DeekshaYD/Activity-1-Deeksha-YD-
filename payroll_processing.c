# payroll processing
#include<stdio.h>
#include <string.h>
struct Time_Card
{
    char ename[50];
    float mins;
};
typedef struct Time_Card time_card;
struct employee
{
    char name[50];
    float Hwage;
    float hours;
    float gross_pay;
};
typedef struct employee emp;
void input_1 (emp * one)
{
    printf ("Enter the name of employee and hourly wage: \n");
    scanf ("%s%f", one->name, &one->Hwage);
}
void input_n (int n, emp em[])
{
    for (int i = 0; i < n; i++)
    input_1 (&em[i]);
}
void input_tc (int m, time_card tc[])
{
    for (int i = 0; i < m; i++)
    {
        printf ("Enter the name of employee and minutes worked: \n");
        scanf ("%s%f", tc[i].ename, &tc[i].mins);
    }
}

float calc_hrs (emp * one, int m, time_card tc[])
{
    float Tmins = 0, Thours = 0;
    for (int i = 0; i < m; i++)
    {
        int c = strcmp (one->name, tc[i].ename);
        if (c == 0)
	    {
	        Tmins = Tmins + tc[i].mins;
	    }
    }
    Thours = Tmins / 60;
    return Thours;
}
void compute_1 (emp * one, int m, time_card tc[])
{
    one->hours = calc_hrs (one, m, tc);
    if (one->hours > 40)
    {
        one->gross_pay = (40 * one->Hwage + (one->hours - 40) * (1.5 * one->Hwage));
    }
    else
    {
        one->gross_pay = one->hours * one->Hwage;
    }
}
void compute_n (int n, emp em[], int m, time_card tc[])
{
    for (int i = 0; i < n; i++)
    compute_1 (&em[i], m, tc);
}
void output_1 (emp * one)
{
    if (one->hours != 0)
    printf ("%s : %.2f hours, $ %.2f \n", one->name, one->hours, one->gross_pay);
}
void output_n (int n, emp em[])
{
    for (int i = 0; i < n; i++)
    output_1 (&em[i]);
}
int main ()
{
    int n, m;
    printf ("Enter the number of employee: \n");
    scanf ("%d", &n);
    emp em[n];
    input_n (n, em);
    printf ("Enter the number of time cards: \n");
    scanf ("%d", &m);
    time_card tc[m];
    input_tc (m, tc);
    compute_n (n, em, m, tc);
    output_n (n, em);
    return 0;
}
