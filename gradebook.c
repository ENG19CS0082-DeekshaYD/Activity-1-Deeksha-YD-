//WAP to find the sum of n complex numbers using structures and 4 or more functions.
#include<stdio.h>
struct student
{
char name[200];
int marks[200];
char grade;
float score;
};
typedef struct student stud;
struct gradebook
{
char subject[200];
int num_weights;
float weights[200];
int num_students;
stud student[200];
};
typedef struct gradebook gb;
void input_gb(gb *onegb)

{
printf("enter the course name:\n");
scanf("%s",onegb->subject);
printf("enter the no of students:\n");
scanf("%d",&onegb->num_students);
printf("enter the number of weights:\n");
scanf("%d",&onegb->num_weights);
for(int i=0;i<onegb->num_weights;i++)
{
printf("enter the weights:\n");
scanf("%f",&onegb->weights[i]);
}
for(int j=0;j<onegb->num_students;j++)
{
printf("enter the name:");
scanf("%s",onegb->student[j].name);
for(int k=0;k<onegb->num_weights;k++)
{
printf("enter the marks of the student\n");
scanf("%d",&onegb->student[j].marks[k]);
}
}
}
int input()
{
 int n;
 printf("enter the number of gradebooks:\n");
 scanf("%d",&n);
  return n;
}
void input_n(int n,gb a[ ])
{
for(int i=0;i<n;i++)
input_gb(&a[i]);
}
char grade( float r)
{
if(r>=0 && r<60)
return 'F';
else if(r>=60 && r<70)
return 'D';
else if(r>=70 && r<80)
return 'C';
else if(r>=80 && r<90)
return 'B';
else
return 'A';
}
void compute(gb *one)
{

float w=0.0;
for(int i=0;i<one->num_weights;i++)
{
w+=one->weights[i];
}
int i;
for( i=0;i<one->num_students;i++)
{
one->student[i].score=0.0;
for (int j=0;j<one->num_weights;j++)
{
one->student[i].score += one->student[i].marks[j]*one->weights[j];
}

one->student[i].score = one->student[i].score / w;
one->student[i].grade=grade(one->student[i].score);
}
}
void compute_n(int n,gb a[ ])
{
for ( int i=0;i<n;i++)
compute(&a[i]);
}

void output(gb *one)
{
printf("%s\n",one->subject);
for(int i=0;i<one->num_students;i++)
{
printf("%s\t%f\t%c\n" ,one->student[i].name,one->student[i].score,one->student[i].grade);
}
}
void output_n(int n, gb a[])
{
for(int i=0;i<n;i++)
output(&a[i]);
}
int main()
{
int n=input();
gb a[n];
input_n(n,a);
compute_n(n,a);
output_n(n,a);
return 0;
}
