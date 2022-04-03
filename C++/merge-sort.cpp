#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;

void merge(vector<int>& A,int p,int q,int r)
{
    vector<int> a;
    vector<int> b;
    for(int i=p;i<=q;i++)
    {
        a.push_back(A[i]);
    }
    a.push_back(INT_MAX);
    for(int i=q+1;i<=r;i++)
    {
        b.push_back(A[i]);
    }
    b.push_back(INT_MAX);
    int i=0,j=0;
    for(int k=p;k<=r;k++)
    {
        if(a[i]<=b[j])
        {
            A[k] = a[i];
            i++;
        }
        else
        {
            A[k] = b[j];
            j++;
        }
    }
}

void mergeSort(vector<int>& A,int p,int r)
{
    if(p<r)
    {
        int q = floor((p+r)/2);
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}

int main()
{
    vector<int> A = {7,1,3,9,4,1,8,6,12,90};
    mergeSort(A,0,A.size()-1);
    for(int i=0;i<A.size();i++)
    {
        cout << A[i] << ",";
    }
    return 0;
}