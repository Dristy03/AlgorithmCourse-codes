#include<bits/stdc++.h>
using namespace std;

int applicant,jobs;
int adj[100][100];

bool bipartite(int u,bool vis[],int arr[])
{
    for(int v=0; v<jobs; v++)
    {
        if(adj[u][v] && !vis[v])
        {
            vis[v]=1;
            if(arr[v]<0 || bipartite(arr[v],vis,arr))
            {
                arr[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int maxMatch()
{
    int arr[jobs];
    bool vis[jobs];
    memset(arr,-1,sizeof(arr));

    int jobCount=0;

    for(int i=0; i<applicant; i++)
    {
        memset(vis,0,sizeof(vis));
        if(bipartite(i,vis,arr))
            jobCount++;
    }
    return jobCount;
}


int main()
{
    int i,j;
    cin>>applicant>>jobs;
    for(i=0; i<applicant; i++)
    {
        for(j=0; j<jobs; j++)
        {
            cin>>adj[i][j];
        }
    }



    cout<<maxMatch()<<endl;
}




/*

6 6
0 1 1 0 0 0
1 0 0 1 0 0
0 0 1 0 0 0
0 0 1 1 0 0
0 0 0 0 0 0
0 0 0 0 0 1

*/
