#include<bits/stdc++.h>
using namespace std;
# define sz 100

vector<int>ans;
int lps[sz];

void init_lps(string pat)
{
    int i=1,j=0;
    lps[0]=0;
    while(i<pat.size())
    {
        if(pat[i]==pat[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

void kmp(string txt,string pat)
{
    int i=0,j=0;

    while(i<txt.size())
    {
        if(pat[j]==txt[i])
        {
            j++;
            i++;
        }
        if(j==pat.size())
        {
            ans.push_back(i+i-j); //index of last character
            j=lps[j-1];
        }
        else if(i<txt.size() && pat[j]!=txt[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
                i++;
        }
    }
}





int main()
{

    string a,b;
    cin>>a>>b;

    init_lps(b);
    kmp(a,b);

    cout<<ans.size()<<endl;


}
