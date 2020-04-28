#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void removeWhiteSpace(string& S)
{
    int c = 0;
    for(int i=0;i<S.size();i++)
    {
        if(S[i]!=' ')
            S[c++] = S[i];
    }
    S[c] = '\0';
}

bool checkSameStringCaseInsensitive(string& S1,string& S2)
{
    if(S1.size()!=S2.size())
    {
        return false;
    }
    transform(S1.begin(),S1.end(),S1.begin(),::tolower);
    transform(S2.begin(),S2.end(),S2.begin(),::tolower);
    sort(S1.begin(),S1.end());
    sort(S2.begin(),S2.end());
    return S1==S2;
}

bool checkSameString(string& S1,string& S2)
{
    if(S1.size()!=S2.size())
    {
        return false;
    }
    sort(S1.begin(),S1.end());
    sort(S2.begin(),S2.end());
    return S1==S2;
}

bool checkPermute(string S1,string S2,int l,int r)
{
    if(l==r)
    {
        if(S1 == S2)
        {
            return true;   
        }
        else
        {
            return false;
        }
    }
    for(int i=l;i<=r;i++)
    {
        swap(S2[i],S2[l]);
        bool res = checkPermute(S1,S2,l+1,r);
        if(res)
            return true;
        swap(S2[i],S2[l]);
    }
    return false;
}

bool isPermute(string& S1,string& S2)
{
    if(S1.size()!=S2.size())
        return false;
    return checkPermute(S1,S2,0,S1.size()-1);
}


int main()
{
    string S1 = "Abcd";
    string S2 = "dbcA";
    cout << isPermute(S1,S2);
    return 0;
}