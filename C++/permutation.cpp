#include <bits/stdc++.h>
using namespace std;
void permute(string a, int l, int r)  
{  
    // Base case  
    if (l == r){
     cout<< a << endl;
     return;
    }
    // Permutations made  
    for (int i = l; i <= r; i++)  
    {  
        // Swapping done  
        swap(a[l], a[i]);  

        // Recursion called  
        permute(a, l+1, r);  

        //backtrack  
        swap(a[l], a[i]);  
    }  
}  
  
// Driver Code  
int main()  
{  
    string str = "ABCD";  
    int n = str.size();  
    permute(str, 0, n-1);  
    return 0;  
}  