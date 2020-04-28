/*
Time: theta(W*n)
space: theta(W*n)
recover items: theta(W*n)
*/
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W,int n,vector<int>& v,vector<int>& x,vector<vector<int>>& picked)
{
    vector<vector<int>> sol(v.size()+1,vector<int>(W+1,0));
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= W; j++) 
        {
            int localV = 0;
            if(x[i-1]<=j)
            {
                int maxW = j - x[i-1];
                localV = v[i-1] + sol[i-1][maxW];
                if(localV>sol[i-1][j])
                {
                    sol[i][j] = localV;
                    picked[i][j] = v[i-1];
                }
                else
                {
                    sol[i][j] = sol[i-1][j];
                }
            }
            else
            {
                sol[i][j] = sol[i-1][j]; 
            }
        }
    }
    return sol[n][W];
}

int main()
{
    vector<int>v = {10,8,4,9};
    vector<int>x = {10,12,5,7};
    int W = 25;
    vector<vector<int>> picked(v.size()+1,vector<int>(W+1,-1));
    cout << knapSack(W,v.size(),v,x,picked)<<endl;
    int n=v.size();
    while(n>0)
    {
        if(picked[n][W]!=-1)
        {
            cout << picked[n][W] << endl;
            W = W - x[n-1];
            n=n-1;
        }
        else
        {
            n=n-1;
        }
    }
    return 0;
}