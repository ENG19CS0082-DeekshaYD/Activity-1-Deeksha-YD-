//WAP to find the distance between two points using structures and 4 functions.

#include<stdio.h>
#include<math.h>
struct point
{      
    float x,y;
};
typedef struct point Point;
Point input(char b1[], char b2[])
{   
    Point p;
    printf("Enter %s coordinate :",b1);
    scanf("%f",&p.x);
    printf("Enter %s coordinate :",b2);
    scanf("%f",&p.y);
    return p;
}
float compute_distance(Point p1,Point p2)
{
    float dist=sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));
    return dist;
}
void output (Point p1, Point p2,float distance)
{
    printf("The distance between (%f,%f) and (%f,%f) is :%f",p1.x,p1.y,p2.x,p2.y,distance);
}
int main()
{
    float D;
    Point p1,p2;
    p1=input("x1","y1");
    p2=input("x2","y2");
    D=compute_distance(p1,p2);
    output(p1,p2,D);
    return 0;
}
