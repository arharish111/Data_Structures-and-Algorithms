#include<bits/stdc++.h>
using namespace std;

int stairClimbing(int N)
{
    if(N<0)
        return 0;
    if(N==0)
        return 1;
    vector<int> sol(N+1,0);
    sol[0] = 1;
    for (int i = 1; i <= N; i++) 
    {
        int a = i-1;
        int b = i-2;
        int c = i-3;
        if(b<0)
            sol[i] = sol[a];
        else if(c<0)
            sol[i] = sol[a] + sol[b];
        else
            sol[i] = sol[a]+sol[b]+sol[c];
    }
    return sol[N];
}

int main()
{
    cout<< stairClimbing(4);
    return 0;
}