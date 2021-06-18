#include<bits/stdc++.h>
using namespace std;

char b[100][100];

string s1,s2;

int lcs(int n,int m)
{
    if(n==-1 || m==-1)
        return 0;
    if(s1[n]==s2[m])
    {
        b[n][m]='d';
        return 1+lcs(n-1,m-1);
    }
    else if(lcs(n,m-1)<=lcs(n-1,m))
    {
        b[n][m]='u';
        return lcs(n-1,m);
    }
    else
    {
        b[n][m]='l';
        return lcs(n,m-1);
    }
}

void print(int n,int m)
{
    if(n==-1 || m==-1)
        return;
    if(b[n][m]=='d')
    {
        print(n-1,m-1);
        cout<<s1[n];
    }
    else if(b[n][m]=='u')
    {
        print(n-1,m);
    }
    else
    {
        print(n,m-1);
    }
}

int main()
{
    cin>>s1>>s2;
    printf("%d\n",lcs(s1.size()-1,s2.size()-1));
    print(s1.size()-1,s2.size()-1);
}
