#include <bits/stdc++.h>
using namespace std;


struct Point
{
    int x, y;
};

bool compareY(Point a,Point b)
{
	return a.y>b.y;
}

bool compareX(Point a,Point b)
{
	return a.x>b.x;
}
double dist(Point a,Point b)
{
    int d1=b.x-a.x;
    int d2=b.y-a.y;
    return sqrt(d1*d1+d2*d2);
}

Point min1,min2;
double minimum = FLT_MAX;

double bruteForce(Point P[], int n)
{
    double min = FLT_MAX;
    for (int i = 0; i < n; ++i)// n == 3
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                {
                    min = dist(P[i], P[j]);
                    if(min<minimum)
                    {
                        minimum = min;
                        min1 = P[i];
                        min2 = P[j];
                    }
                }
    return min;
}


float stripClosest(Point strip[], int size, float d)
{
    float min = d;

    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                {
                    min = dist(strip[i], strip[j]);
                    if(min<minimum)
                    {
                        minimum = min;
                        min1 = strip[i];
                        min2 = strip[j];
                    }
                }

    return min;
}

double closestUtil(Point Px[], Point Py[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);

    // Find the middle point
    int mid = n/2;
    Point midPoint = Px[mid];


    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    Point Pxl[mid];   // y sorted points on left of vertical line
    Point Pxr[n-mid];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++)
    {
      if (Px[i].x <= midPoint.x && li<mid)
         Pxl[li++] = Px[i];
      else
         Pxr[ri++] = Px[i];
    }

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    double dl = closestUtil(Pxl, Py, mid);
    double dr = closestUtil(Pxr , Py, n-mid);

    // Find the smaller of two distances
    double d = min(dl, dr);

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return stripClosest(strip, j, d);
}
double closest(Point P[], int n)
{
    Point px[n];
    Point py[n];
    for (int i = 0; i < n; i++)
    {
        px[i] = P[i];
        py[i] = P[i];
    }
  	sort(px,px+n,compareX);
  	sort(py,py+n,compareY);


    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(px, py, n);
}

int main(int argc, char const *argv[])
{
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(P, n) << endl;
    cout << "the points are {"<< min1.x << "," << min1.y << "},{" << min2.x << "," << min2.y << "}\n";
    return 0;



	return 0;
}
