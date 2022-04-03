#include <iostream>
#include <string>
using namespace std;

string mergeStringsAlternate(string a,string b)
{
    if(a.size()<1)
        return b;
    if(b.size()<1)
        return a;
    string res;
    for(int i=0;i<a.size()+b.size();i++)
    {
        if(i<a.size())
            res += a[i];
        if(i<b.size())
            res += b[i];
    }
    return res;
}

int main()
{
    string a = "geeks";
    string b = "forgeeks";
    cout << mergeStringsAlternate(a,b);
}