#include <vector>
#include <string>
#include <iostream>
using namespace std;

int editDistance(string& A,string& B,vector<vector<int>>& C)
{
    for(int i=1;i<=A.size();i++)
    {
        for(int j=1;j<=B.size();j++)
        {
            int a=C[i-1][j-1],b=C[i][j-1],c=C[i-1][j],min=0;
            if(A[i-1]!=B[j-1])
            {
                a +=1;
            }
            b +=1;
            c +=1;
            if(a<=b)
                min = a;
            else
                min = b;
            if(min>c)
                min = c;
            C[i][j] = min;
        }
    }
    return C[A.size()][B.size()];
}

int main()
{
    string A = "abcdefyyy";
    string B = "wwabudef";
    vector<vector<int>> c(A.size()+1,vector<int>(B.size()+1,0));
    for(int i=0;i<=A.size();i++)
    {
        c[i][0] = i;
    }
    for(int i=0;i<=B.size();i++)
    {
        c[0][i] = i;
    }
    cout << editDistance(A,B,c) << endl;
    for(int i=0;i<=A.size();i++)
    {
        for(int j=0;j<=B.size();j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    int n = A.size();
    int m = B.size();
    string A1;
    string B1;
    while(n>0 || m>0)
    {
        if(n==0)
        {
            A1 += '-';
            B1 += B[m-1];
            m -= 1;
            continue;
        }
        if(m==0)
        {
            A1 += A[n-1];
            B1 += '-';
            n -= 1;
            continue;
        }
        int x=c[n-1][m-1],y=c[n][m-1],z=c[n-1][m];
        if(A[n-1]!=B[m-1])
        {
            x += 1;
        }
        y += 1;
        z += 1;
        if(c[n][m]==x)
        {
           A1 += A[n-1];
           B1 += B[m-1];
           n -= 1;
           m -= 1;
        }
        else if(c[n][m]==y)
        {
            A1 += '-';
            B1 += B[m-1];
            m -= 1;
        }
        else
        {
            A1 += A[n-1];
            B1 += '-';
            n -= 1;
        }
    }
    cout << A1 << endl;
    cout << B1 << endl;
    return 0;
}