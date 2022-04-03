#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class CountSort
{
    protected:
    vector<char> alphabets;
    vector<int> indexes;
    int K,N;
    char val;
    
    public:
    CountSort(){}
    CountSort(vector<char>& alpha,int K,char val):alphabets(alpha),K(K),val(val)
    {
        N = alphabets.size();
        indexes.resize(N,0);
        for(int i=0;i<N;i++) 
        {
            indexes[i] = alphabets[i] - val;
        }
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

class RadixSort: public CountSort
{
    vector<int> input;
    int d;
    
    void sort()
    {
        for(int i=1;i<=d;i++)
        {
            vector<int> count(K,0);
            vector<int> temp(N,0);
            for(int j=0;j<N;j++)
            {
                count[getIndex(input[j],i)] += 1; 
            }
            for(int j=1;j<K;j++)
            {
                count[j] += count[j-1];
            }
            for(int j=N-1;j>=0;j--)
            {
                int index = getIndex(input[j],i);
                count[index] -= 1;
                temp[count[index]] = input[j];
            }
            for(int j=0;j<N;j++)
            {
                input[j] = temp[j];
            }
        }
    }
    
    int getIndex(int num,int position)
    {
        int m = 0;
        while(position>0)
        {
            if(num>0)
            {
                m = num%10;
                num = num/10;
                position--;
            }
            else
            {
                return 0;
            }
        }
        return m;
    }
    
    public:
    RadixSort(vector<int> in,int numOfKeys,int numOfDigits): input(in),d(numOfDigits)
    {
        N = input.size();
        K = numOfKeys;
        sort();
    }
    
    vector<int> getSortedArray()
    {
        return input;
    }
};


int main()
{
    vector<int> A = {10,4,3,99,87};
    RadixSort r(A,10,2);
    A = r.getSortedArray();
    for(int i=0;i<A.size();i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}
