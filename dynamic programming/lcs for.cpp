#include<bits/stdc++.h>
using namespace std;
int lcs[100][100];
int main()
{
    int i,j;
    string a,b;
    cin>>a>>b;

    for(i=0; i<=a.size();i++)
    {
        lcs[i][0]=0;
    }
     for(i=0; i<=b.size();i++)
    {
        lcs[0][i]=0;
    }

        for(i=1; i<=a.size(); i++)
        {
            for(j=1; j<=b.size(); j++)
            {
                if(a[i-1]==b[j-1])
                {
                    lcs[i][j]=lcs[i-1][j-1]+1;
                }
                else
                {
                    lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
                }
            }
        }

        cout<<lcs[a.size()][b.size()]<<endl;

        i=a.size();
        j=b.size();
        string s;

        while(i>0 && j>0)
        {
            if(lcs[i][j]!= lcs[i-1][j] && lcs[i][j]!=lcs[i][j-1])
            {
                s+=a[i-1];
                i--;
                j--;
            }
            else
            {
                if(lcs[i][j]==lcs[i-1][j])
                {
                    i--;
                }
                else if (lcs[i][j]==lcs[i][j-1])
                {
                    j--;
                }
            }
        }

        reverse(s.begin(),s.end());
        cout<<s<<endl;
}

