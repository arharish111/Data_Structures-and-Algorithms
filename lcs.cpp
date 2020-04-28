/*
Time : theta(nm)
where n,m are the lengths of strings
*/
#include <vector>
#include <iostream>
using namespace std;

class solution
{
  public:
    int longestCommonSubsequence(string x,string y,vector<vector<int>>& c,vector<vector<int>>& b)
    {
        for(int i=0;i<x.size();i++)
        {
            for(int j=0;j<y.size();j++)
            {
                if(x[i]==y[j])
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
        return c[x.size()][y.size()];
    }
};

void printLCS(string x,vector<vector<int>>& b,int i,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(b[i][j]==1)
    {
        printLCS(x,b,i-1,j-1);
        cout << x[i-1] << endl;
    }
    else if(b[i][j]==2)
    {
        printLCS(x,b,i,j-1);
    }
    else
        printLCS(x,b,i-1,j);
}

int main()
{
    string x = "ABCBDAB";
    string y = "BDCABA";
    vector<vector<int>> c(x.size()+1,vector<int>(y.size()+1,0));
    vector<vector<int>> b(x.size()+1,vector<int>(y.size()+1,0));
    solution lcs;
    cout << lcs.longestCommonSubsequence(x,y,c,b) << endl;
    printLCS(x,b,x.size(),y.size());
    // for(int i=0;i<=x.size();i++)
    // {
    //     for(int j=0;j<=y.size();j++)
    //     {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}