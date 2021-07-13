#include<bits/stdc++.h>
using namespace std;
#define sz 110
#define inf 1<<28

int capacity[sz][sz];
vector<int>adj[sz];
int n;

int bfs(int s, int t, vector<int>&parent)
{
    fill(parent.begin(), parent.end(),-1);
    parent[s]=-2;
    queue<pair<int,int>>q;
    q.push({s,inf});
    while(!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int next=0; next<adj[cur].size(); next++)
        {
            if(parent[adj[cur][next]]==-1 and capacity[cur][adj[cur][next]])
            {
                parent[adj[cur][next]]=cur;
                int new_flow = min(capacity[cur][adj[cur][next]],flow);
                if(adj[cur][next]==t)
                    return new_flow;
                q.push({adj[cur][next],new_flow});
            }
        }
    }
    return 0;
}
int maxflow(int s,int t)
{
    int flow  = 0,new_flow;
    vector<int>parent(n+1);
    while(new_flow=bfs(s,t,parent))
    {
        flow += new_flow;
        int cur=t;
        while(cur!=s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main()
{
    int t,cnt=0;
    cin>>t;
    while(t--)
    {
        int m,i,s,t,c,j;
        cin>>n;
        cin>>s>>t>>c;
        memset(capacity,0,sizeof(capacity));
        while(c--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            capacity[u][v]+=w;
            capacity[v][u]+=w;
        }
        cout<<"Case "<<++cnt<<": "<<maxflow(s,t)<<endl;
        for(i=0; i<sz; i++)
        {
            adj[i].clear();
        }

    }
}

