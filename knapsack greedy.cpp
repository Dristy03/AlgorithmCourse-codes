#include<bits/stdc++.h>
using namespace std;

struct node
{
    int id,profit,weight;
    node(int a,int b,int c)
    {
        id=a;
        profit=b;
        weight=c;
    }

};

bool cmp(node a,node b)
{
    return a.profit*b.weight>a.weight*b.profit;
}

int main()
{

    vector<node>v;
    int i,k,l,m,n,w,j,total=0;
    scanf("%d %d",&n,&w);
    int a[n+1];
    memset(a,0,sizeof(a));
    for(i=1; i<=n; i++)
    {
        scanf("%d %d",&j,&k);
        v.push_back(node(i,j,k));
    }
    sort(v.begin(),v.end(),cmp);
    for(i=0; i<n; i++)
    {
        if(v[i].weight<=w)
        {
            total+=v[i].profit;
            w-=v[i].weight;
            a[v[i].id]=1;
        }
        else
        {
            break;
        }
    }
    printf("%d\n",total);
    for(i=1; i<=n; i++)
    {
        printf("%d ",a[i]);
    }

}

/*
3 50
60 10
100 20
120 30
*/
