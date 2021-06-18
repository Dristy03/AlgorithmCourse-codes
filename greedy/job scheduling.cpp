#include<bits/stdc++.h>
using namespace std;

struct node
{
    int id,deadline,profit;
    node(int a,int b,int c)
    {
        id=a;
        deadline=b;
        profit=c;
    }
};

bool cmp(node a,node b)
{
    return a.profit>b.profit;
}

int main()
{
    int i,j,k,l,n,d,total=0;
    vector<node>v;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&j,&k);
        v.push_back(node(i+1,j,k));
    }
    sort(v.begin(),v.end(),cmp);
    int a[n];
    memset(a,0,sizeof(a));

    for(i=0; i<n; i++)
    {
        for(int j=min(n,v[i].deadline)-1; j>=0; j--)
        {
            if(!a[j])
            {
                a[j]=v[i].id;
                total+=v[i].profit;
                break;
            }
        }
    }
    printf("%d\n",total);
    for(i=0; i<n; i++)
    {
        if(a[i])
            printf("%d ",a[i]);
    }



}
/*
10
9 15
2 2
5 18
7 1
4 25
2 20
5 8
7 10
4 12
3 5
*/
