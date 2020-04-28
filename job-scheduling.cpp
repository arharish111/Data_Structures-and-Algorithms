#include <vector>
#include <iostream>
using namespace std;

class solution
{
  public:
    int jobScheduling(vector<int>&s,vector<int>&e,vector<int>&v,vector<int>&picked)
    {
        int n = v.size();
        vector<int>p(n,0);
        for(int i=1;i<n;i++)
        {
            int j = i-1;
            while(s[i]<e[j])
            {
                j=j-1;
            }
            p[i] = j;
        }
        vector<int>sol(n,0);
        for(int i=1;i<n;i++)
        {
            //sol[i] = max(sol[i-1],v[i]+sol[p[i]])
            int first = sol[i-1];
            int second = v[i]+sol[p[i]];
            if(first>second)
            {
                sol[i] = first;
            }
            else
            {
                sol[i] = second;
                picked[i] = i;
            }
        }
        return sol[n-1];
    }
};

int main()
{
    vector<int> s = {0,1,2,5,4,6,3};
    vector<int> e = {0,4,5,6,7,8,11};
    vector<int> v = {0,5,6,3,2,2,5};
    vector<int> p = {0,0,0,2,1,3,0};
    vector<int> picked(7,-1);
    solution job;
    cout << job.jobScheduling(s,e,v,picked) << endl;
    int i = 6;
    while(i>0)
    {
        if(picked[i]!=-1)
        {
            cout << picked[i] << endl;
            i = p[i];
        }
        else
        {
           i=i-1; 
        }
        
    }
    return 0;
}