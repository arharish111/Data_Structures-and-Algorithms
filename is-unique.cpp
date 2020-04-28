#include<bits/stdc++.h>
using namespace std;

bool isUnique(string& S)
{
    vector<int> mapping(128,0);
    for(int i=0;i<S.size();i++)
    {
        int acsii = (int)S[i];
        if(mapping[acsii]!=0)
        {
            return false;
        }
        mapping[acsii] = 1;
    }
    return true;
}

bool isUniqueUsingMap(string& S)
{
    map<char,int> mapp;
    for(int i=0;i<S.size();i++)
    {
        if(mapp[S[i]]!=0)
        {
            return false;
        }
        mapp[S[i]] = 1;
    }
    return true;
}

int main()
{
    //manual creating hash map
    map<char,int> mapping = {{'a',0},{'b',1}};
    string S = "abcdA";
    cout << isUnique(S) << endl;
    cout << isUniqueUsingMap(S) << endl;
    return 0;
}