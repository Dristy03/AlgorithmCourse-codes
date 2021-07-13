#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define dbl(xz,zx) setprecision(zx)<<fixed<<xz
#define pb push_back
#define pi acos(-1.0)

#ifndef ONLINE_JUDGE // it works locally
#define here cout<<"here"<<endl;
#define print(axr,xx)for(int i=0;i<xx;i++)cout<<axr[i]<<" \n"[i==xx-1];
#define dbg(xxa) cout<<""#xxa""<<" is "<<xxa<<endl;
#define fastio ;
#else // when being compiled in an on line judge
#define here ;
#define print(axr,xx) ;
#define dbg(xxa) ;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#endif

#define YES() cout<<"Yes"<<endl;
#define NO() cout<<"No"<<endl;
#define infL 0x3f3f3f3f3f3f3f3fLL
#define inf 1<<30
#define mod 1000000007
#define sz 100

int dp[sz][sz];


int main()
{
    //fastio
    int T;
    T=1;
    //cin>>T;

    while(T--)
    {
        int i,j,k,m,n,w,l,res=0,ans=0;
        cin>>n>>w;
        int coins[n+1];
        for(i=0; i<n; i++)
        {
            cin>>coins[i];
        }

        for(i=0; i<=n; i++)
        {
            dp[i][0]=0;
        }

        for(i=1; i<=w; i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=i/coins[0];
            }
            else
            {
                dp[0][i]=0;

            }

        }


        for(i=1; i<n; i++)
        {

            for(j=1; j<=w; j++)
            {
                if(coins[i]>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i]]);
                }


            }
        }

        cout<<dp[n-1][w]<<endl;

        i=n-1;
        j=w;

        vector<int>v;

        while(j>0)
        {
            if(dp[i][j]!=dp[i-1][j])
            {
                v.pb(coins[i]);
                j=j-coins[i];

            }
            else
            {
                i--;
            }
        }

        for(auto x: v)
        {
            cout<<x<<" ";
        }




    }
}

/*

4 10
1 5 6 9
*/



