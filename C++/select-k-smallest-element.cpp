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

int selectKSmallestElement(vector<int>&A,int s,int e,int kIndex)
{
    int pIndex = partition(A,s,e);
    if(pIndex==kIndex)
        return A[pIndex];
    else if(pIndex>kIndex)
        return selectKSmallestElement(A,s,pIndex-1,kIndex);
    else
        return selectKSmallestElement(A,pIndex+1,e,kIndex);
}
int main()
{
    vector<int> A = {6,0,9,40,5};
    cout << "Given array is 6,0,9,40,5" << endl;
    cout << "Third Smallest Element is " << selectKSmallestElement(A,0,4,2);
    return 0;
}