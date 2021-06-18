#include<bits/stdc++.h>
using namespace std;

struct node
{
    int id,weight;
    double profit;
    node(int a,double b,int c)
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

    int i,k,l,m,n,w;
    double j,total=0.0;
    scanf("%d %d",&n,&w);
    int a[n];
    memset(a,0,sizeof(a));
    for(i=1; i<=n; i++)
    {
        scanf("%lf %d",&j,&k);
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
        else if(v[i].weight>w && w!=0)
        {
            total+=v[i].profit*(w/(double)(v[i].weight));
            w-=w;
            a[v[i].id]=1;
        }
    }
    printf("%0.2f\n",total);
    for(i=1; i<=n; i++)
    {
        printf("%d ",a[i]);
    }

}
