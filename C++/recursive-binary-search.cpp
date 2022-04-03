#include <bits/stdc++.h>
using namespace std;

int rec_bin(vector<int>& A,int left,int right,int val){
    if(left > right)
        return -1;
    int m = (left+right)/2;
    if(A[m]==val)
        return m;
    if(A[m]<val)
        return rec_bin(A,m+1,right,val);
    else
        return rec_bin(A,left,m-1,val);
    
}
int main(){
    vector<int> A = {10,20,30,50};
    cout << rec_bin(A,0,4,30);
    return 0;
}