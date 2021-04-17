# rectangular area
#include<stdio.h>
#include<math.h>
typedef struct point
{
float x;
float y;
}point;
typedef struct rectangle
{
point a,b,c;
float ab, bc, ac;
float area;
}rectangle;
float distance ( point a, point b)
{
float dist = sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));
return dist;
}
point input_point()
{
point p;
printf("Enter x value :");
scanf("%f", &p.x);
printf("Enter y value :");
scanf("%f", &p.y);
return p;
}
rectangle input_rectangle()
{
rectangle r;
printf("Enter first point \n");
r.a = input_point();
printf("Enter second point\n");
r.b = input_point();
printf("Enter third point\n");
r.c = input_point();
return r;
}
void input_n(int n, rectangle ar[n])
{
for(int i=0;i<n;i++)

{
printf(" For rectangle number : %d \n",(i+1));
ar[i] = input_rectangle();
}
}
float min(float a, float b, float c)
{
if(a<=b)
if(a<=c)
return a;
else if(c<a)
return c;
else if(b<a)
if(c<=b)
return c;
else if(a<=c)
return b;
}
float max(float a, float b, float c)
{
if(a>=b)
if(a>=c)
return a;
else if(c>=a)
return c;
else if(b>a)
if(c>=b)
return c;
else if(a>=c)
return b;
}
void compute_rectangle(rectangle *r)
{
r->ab = distance( r->a , r->b );
r->bc = distance( r->b , r->c );
r->ac = distance( r->a , r->c );
float side1 = min(r->ab, r->bc, r->ac);
float side3 = max(r->ab, r->bc, r->ac);
float sum = r->ab + r->bc + r->ac;
float side2 = sum - side1 - side3;
r->area = side1 * side2;
}
void compute_n( int n, rectangle ar[n])
{

for(int i=0;i<n;i++)
compute_rectangle(&ar[i]);

}
void display(rectangle r)
{
printf("Area of rectangle with vertices :(%.1f,%.1f) , (%.1f,%.1f) , (%.1f,%.1f) is %.1f \n", r.a.x, r.a.y,
r.b.x, r.b.y, r.c.x, r.c.y, r.area );
}
void display_n(int n, rectangle ar[n])
{
for(int i=0;i<n;i++)
{
display(ar[i]);
}
}
int input()
{
int n=0;
while ( 1 )
{
printf("Enter number of rectangles :");
scanf("%d", &n);
if ( n<=0 )
{
printf("Invlaid Input\n");
}
else
break;

}
return n;
}
int main()
{
int n = input();
rectangle ar[n];
input_n(n, ar);
compute_n(n, ar);
display_n(n, ar);
return 0;
}
