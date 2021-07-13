#include<bits/stdc++.h>
using namespace std;

struct point{
    long long int x,y;
};

point p0;

point nextToTop(stack<point>s)
{
    point p=s.top();
    s.pop();
    point res=s.top();
    s.push(p);
    return res;
}

void swapPoint(point p1,point p2)
{
    point temp=p1;
    p1=p2;
    p2=temp;
}

int dist(point p1,point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int orientation(point p,point q,point r)
{
    int val =(q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(val==0)
        return 0;
    else if(val>0)
        return 1;
    else
        return 2;
}

int compare(const void *vp1, const void *vp2)
{
   point *p1 = (point *)vp1;
   point *p2 = (point *)vp2;

   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}

void convexHull(point points[],int n)
{
    int ymin=points[0].y,minimum=0,i,j,m=1;
    for(i=0;i<n;i++)
    {
        int y=points[i].y;
        if((y<ymin) || (ymin==y && points[i].x<points[minimum].x))
        {
            ymin=points[i].y;
            minimum=i;
        }
    }


    swapPoint(points[0],points[minimum]);

    p0=points[0];

    qsort(&points[1],n-1,sizeof(point),compare);

    for(i=1;i<n;i++)
    {
        while(i<n-1 && orientation(p0,points[i],points[i+1])==0)
            i++;

        points[m]=points[i];
        m++;

    }

    if(m<3)
        return;

    stack<point>s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    for(i=3;i<m;i++)
    {
        while(orientation(nextToTop(s),s.top(),points[i])!=2)
            s.pop();
        s.push(points[i]);
    }

    while(!s.empty())
        {
       point p = s.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       s.pop();
   }

}

int main()
{
    point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},{0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
