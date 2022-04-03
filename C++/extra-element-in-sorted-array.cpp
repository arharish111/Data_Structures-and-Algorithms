#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
#include<string>
using namespace std;

int findExtraElement(vector<int>& A,vector<int>& B,int low,int high)
{
    if(A[low]!=B[low])
        return A[low];
    if(high>=low)
    {
        int mid = (low+high)/2;   
        if(A[mid]==B[mid])
            return findExtraElement(A,B,mid+1,high);
        else
            return findExtraElement(A,B,low,mid);
    }
    else
        return -1;
}

int main()
{
    vector<int> A = {1,2,3,4,5};
    vector<int> B = {1,2,4,5};
    cout << findExtraElement(A,B,0,4);
    return 0;
}