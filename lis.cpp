#include <bits/stdc++.h>
using namespace std;

class solution
{
    int lcs(vector<int>& A,vector<int>& B,vector<vector<int>>& c,vector<vector<int>>& b)
    {
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<B.size();j++)
            {
                if(A[i]==B[j])
                {
                    c[i+1][j+1] = c[i][j] + 1;
                    b[i+1][j+1] = 1;
                }
                else
                {
                    if(c[i+1][j]>c[i][j+1])
                    {
                        c[i+1][j+1] = c[i+1][j];
                        b[i+1][j+1] = 2;
                    }
                    else
                    {
                        c[i+1][j+1] = c[i][j+1];
                        b[i+1][j+1] = 3;
                    }
                }
            }
        }
        return c[A.size()][B.size()];
    }
    void printLIS(vector<int>& A,vector<vector<int>>& b,int x,int y)
    {
        if(x==0 || y==0)
        {
            return;
        }
        if(b[x][y]==1)
        {
            printLIS(A,b,x-1,y-1);
            cout<< A[x-1] << endl;
        }
        else if(b[x][y]==2)
        {
            printLIS(A,b,x,y-1);
        }
        else
        {
            printLIS(A,b,x-1,y);            
        }
    }
    
    public:
    int lis(vector<int>& A,int rep)
    {
        int res = 0;
        if(A.size() < 1)
        {
            return res;
        }
        else if(A.size() == 1)
        {
            return A[0];
        }
        cout << "LIS:"<<endl;
        if(rep==1)
        {
            vector<int> aSorted = A;
            for(int j=1;j<aSorted.size();j++)
            {
                int i = j-1;
                int key = aSorted[j];
                while(i>=0 && aSorted[i]>key)
                {
                    aSorted[i+1] = aSorted[i];
                    i = i-1;
                }
                aSorted[i+1] = key;
            }
            vector<vector<int>> c(A.size()+1,vector<int>(aSorted.size()+1,0));
            vector<vector<int>> b(A.size()+1,vector<int>(aSorted.size()+1,0));
            res = lcs(A,aSorted,c,b);
            printLIS(A,b,A.size(),aSorted.size());
        }
        else
        {
            int max = *max_element(A.begin(),A.end());
            int min = *min_element(A.begin(),A.end());
            vector<int> B;
            for(int i=min;i<=max;i++)
            {
                B.push_back(i);
            }
            vector<vector<int>> c(A.size()+1,vector<int>(B.size()+1,0));
            vector<vector<int>> b(A.size()+1,vector<int>(B.size()+1,0));
            res = lcs(A,B,c,b);
            printLIS(A,b,A.size(),B.size());
        }
        return res;
    }
};

int main()
{
    vector<int> A = {3,5,3,9,3,4,3,1,2,1,4};
    solution sol;
    int res = sol.lis(A,1);
    cout<<"lenght:";
    cout << res;
}