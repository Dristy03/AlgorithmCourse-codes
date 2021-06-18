#include<bits/stdc++.h>
using namespace std;

#define sz 100

int dp[sz][sz],weight[sz],profit[sz],plist[sz];
int n,w;


int main()
{
    //fastio
    int T;
    T=1;
    //cin>>T;

    while(T--)
    {
        int i,j,k,m,l,res=0,ans=0;
        cin>>n>>w;
        for(i=1; i<=n; i++)
        {
            cin>>weight[i]>>profit[i];
        }

        for(i=0; i<=n; i++)
        {
            for(j=0; j<=w; j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
                else if(weight[i]<=j)
                {
                    dp[i][j]=max(profit[i]+dp[i-1][j-weight[i]],dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        cout<<dp[n][w]<<endl;

        i=n;
        j=w;

        while(i>0 && j>-1)
        {
            if(dp[i][j]==dp[i-1][j])
            {
                cout<<i<<" = 0"<<endl;
                i--;
            }
            else
            {
                cout<<i<<" = 1"<<endl;
                j-=weight[i];
                i--;
            }
        }

    }
}

/*

4 8
2 1
3 2
4 5
5 6
*/

