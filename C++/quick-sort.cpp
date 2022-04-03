#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& A,int s,int e)
{
    int pivot = A[e];
    int t = s;
    for(int i=s;i<=e-1;i++)
    {
        if(A[i]<=pivot)
        {
            swap(A[i],A[t]);
            t++;
        }
    }
    swap(A[t],A[e]);
    return t;
}

void quickSort(vector<int>& A,int s,int e)
{
    if(s<e)
    {
        int pIndex = partition(A,s,e);
        quickSort(A,s,pIndex-1);
        quickSort(A,pIndex+1,e);
    }
}
int main()
{
    vector<int> A = {5,0,9,40,5};
    quickSort(A,0,4);
    for(int i=0;i<A.size();i++)
    {
        cout << A[i] << ",";
    }
    return 0;
}