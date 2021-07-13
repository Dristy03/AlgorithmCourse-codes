#include<bits/stdc++.h>
using namespace std;
#define sz 16
int n;
int board[sz][sz];
int left_diagonal[sz][sz];
int right_diagonal[sz][sz];
bool row_check[sz];
bool left_diagonal_check[2*sz];
bool right_diagonal_check[2*sz];

void print()
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solve(int col)
{
    if(col>=n)
        return 1;
    int i,j;
    for(i=0; i<n; i++)
    {
        if(!left_diagonal_check[left_diagonal[i][col]] && !right_diagonal_check[right_diagonal[i][col]]
                && !row_check[i])
        {
            board[i][col]=1;
            left_diagonal_check[left_diagonal[i][col]]=1;
            right_diagonal_check[right_diagonal[i][col]]=1;
            row_check[i]=1;

            if(solve(col+1))
            {
                return 1;
            }

            board[i][col]=0;
            left_diagonal_check[left_diagonal[i][col]]=0;
            right_diagonal_check[right_diagonal[i][col]]=0;
            row_check[i]=0;
        }
    }
    return 0;
}

int main()
{
    int i,j,k;
    cin>>n;

    memset(board,0,sizeof(board));
    memset(left_diagonal_check,0,sizeof(left_diagonal_check));
    memset(right_diagonal_check,0,sizeof(right_diagonal_check));
    memset(row_check,0,sizeof(row_check));

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            left_diagonal[i][j]=i+j;
            right_diagonal[i][j]=j-i+(n-1);
        }
    }

    if(solve(0))
    {
        print();
    }
    else
    {
        cout<<"No solution exits"<<endl;
    }
}
