#include<bits/stdc++.h>
using namespace std;

int vis[100], col[100];
set<int> st[100];
vector <int> graph[100];
int n,m;

void bfs()
{
    int cnt=0,i;
    int mx=-1,pos=-1;
    for(i=1;i<=n;i++)
    {
        if(vis[i]) {
            cnt++;
            continue;
        }
        if((int)st[i].size()>mx)
        {
            mx=st[i].size();
            pos=i;
        }
    }
    if(cnt==n) return;
    vis[pos]=1;
    if(st[pos].size()==0) {
        col[pos]=1;
        for(auto it:graph[pos]) {st[it].insert(1);}
        bfs();
        return;
    }
    int j=1;
    for(auto itt: st[pos]) {
        if(itt!=j)
        {
            col[pos]=j;
            for(auto it:graph[pos]) {st[it].insert(j);}
            bfs();
            return;
        }
        j++;
    }
    col[pos]=j;
    for(auto it:graph[pos]) {st[it].insert(j);}
    bfs();
}


void solve()
{
    int x,y;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs();
    for(int i=1;i<=n;i++) cout << col[i] << " ";
    cout << endl;
}



int main()
{
    int t=1;
    while(t--) solve();
}
