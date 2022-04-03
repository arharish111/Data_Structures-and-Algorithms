#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class CountSort
{
    vector<char> alphabets;
    vector<int> indexes;
    int K,N;
    char val;
    public:
    CountSort(vector<char>& alpha,int K,char val)
    {
        alphabets = alpha;
        indexes.resize(alphabets.size(),0);
        for(int i=0;i<alphabets.size();i++) 
        {
            indexes[i] = alphabets[i] - val;
        }
        K = K;
        N = alphabets.size();
        val = val;
    }
    void sort()
    {
        vector<int> count(K,0);
        vector<char> temp(N,val);
        for(int i=0;i<N;i++)
        {
            count[indexes[i]] += 1;
        }
        for(int i=1;i<K;i++)
        {
            count[i] = count[i] + count[i-1];
        }
        for(int i=N-1;i>=0;i--)
        {
            count[indexes[i]] -= 1;
            temp[count[indexes[i]]] = alphabets[i];
        }
        for(int i=0;i<N;i++)
        {
            alphabets[i] = temp[i];
        }
    }
    vector<char> getSortedArray()
    {
        return alphabets;
    }
    
};


int main()
{
    vector<char> a = {'q','e','t'};
    CountSort cs(a,26,'a');
    cs.sort();
    a = cs.getSortedArray();
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}
