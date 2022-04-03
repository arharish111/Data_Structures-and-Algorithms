#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <climits> 
using namespace std;

class TrendingStock
{
    unordered_map<string,int> stockIndexMap;
    vector<pair<string,int>> pq;
    
    void increaseKey(int index)//O(lgN)
    {
        pq[index].second += 1;
        swimUp(index);
    }
    void swimUp(int index)//O(lgN)
    {
        while(index>1 && pq[index].second >= pq[floor(index/2)].second)
        {
            stockIndexMap[pq[index].first] = floor(index/2);
            stockIndexMap[pq[floor(index/2)].first] = index;
            swap(pq[index],pq[floor(index/2)]);
            index = floor(index/2);
        }
    }
    string removeMax()//O(lgN)
    {
        string str = pq[1].first;
        stockIndexMap[pq[pq[0].second].first] = 1;
        pq[1] = pq[pq[0].second];
        pq[0].second -= 1;
        sinkDown(1);
        stockIndexMap.erase(str); 
        return str;
    }
    void sinkDown(int p)//O(lgN)
    {
        int l = 2*p;
        int r = 2*p + 1;
        int index = p;
        int N = pq[0].second;
        if(l<=N && pq[l].second > pq[index].second)
            index = l;
        if(r<=N && pq[r].second > pq[index].second)
            index = r;
        if(index!=p)
        {
            stockIndexMap[pq[index].first] = p;
            stockIndexMap[pq[p].first] = index;
            swap(pq[index],pq[p]);
            sinkDown(index);
        }
    }
    public:
        TrendingStock()
        {
            pq.push_back(make_pair("size",0));
        }
        void processStock(string stock)//O(lgN)
        {
            auto search = stockIndexMap.find(stock);
            if(search!=stockIndexMap.end())
            {
                increaseKey(stockIndexMap[stock]);
            }
            else
            {
                if(pq[0].second < pq.size()-1)
                {
                    pq[pq[0].second+1] = make_pair(stock,1);
                    pq[0].second += 1;
                }
                else
                {
                    pq.push_back(make_pair(stock,1));
                    pq[0].second = pq.size()-1;
                }
                stockIndexMap[stock] = pq[0].second;
                swimUp(pq[0].second);
            }
	    }

        string getTrendingStock()//O(lgN)
        {
            if(pq[0].second>0)
            return removeMax();
            else
            return "No stocks to return";
	    }
    
};

int main()
{
    TrendingStock obj;
    cout << obj.getTrendingStock() << endl;
    obj.processStock("TSLA");
    obj.processStock("APPL");
    obj.processStock("TSLA");
    obj.processStock("APPL");
    cout << obj.getTrendingStock() << endl;
    obj.processStock("NETL");
    obj.processStock("TSLA");
    cout << obj.getTrendingStock() << endl;
    obj.processStock("TSLA");
    cout << obj.getTrendingStock() << endl;
    cout << obj.getTrendingStock() << endl;
    cout << obj.getTrendingStock() << endl;
    return 0;
}