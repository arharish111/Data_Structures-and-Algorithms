/*
Time: theta(W*n)
space: theta(W)
recover items: theta(W)
*/
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W,int n,vector<int>& v,vector<int>& x,vector<int>& picked)
{
    vector<int>sol(W+1,0);
    for (int i = 1; i <= W; i++) 
    {
        int maxV = 0;
        for (int j = 0; j < n; j++) 
        {
            int localV = 0;
            if(x[j]<=i)
            {
                int maxW = i - x[j];
                localV = v[j] + sol[maxW];
                if(localV>maxV)
                {
                    sol[i] = localV;
                    maxV = localV;
                    picked[i] = j;
                }
            }
        }
    }
    return sol[W];
}

int main()
{
    vector<int>v = {10,8,4,9};
    vector<int>x = {10,12,5,7};
    int W = 20;
    vector<int>picked(W+1,-1);
    cout << knapSack(W,v.size(),v,x,picked)<<endl;
    while(picked[W]!=-1)
    {
        cout << picked[W] << endl;
        W = W - x[picked[W]];
    }
    return 0;
}
