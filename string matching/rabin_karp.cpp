#include<bits/stdc++.h>
#define p 31
#define m 1000000009
using namespace std;


vector<int> rabin_karp(string pattern, string text)
{

    int S = pattern.size(), T = text.size();

    vector<long long int> p_pow(max(S+1, T+1));

    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p)%(m);

    vector<long long int> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (pattern[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurences;

    for (int i = 0; i + S - 1 < T; i++)
    {
        int j;
        long long cur_h = (h[i+S] + m - h[i]) % m;

        if (cur_h == h_s * p_pow[i] % m)
        {

            for (j = 0; j < S; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }


            if (j == S)
                occurences.push_back(i);
        }
    }


    return occurences;

}


int main()
{
    string t,pp;
    cin>>t>>pp;
    vector<int>ans;
    ans = rabin_karp(pp,t);

    cout<<ans.size()<<endl;


}

