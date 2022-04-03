#include<iostream>
#include<vector>
using namespace std;
class AdjacencyLists
{
    public:
    int item;
    AdjacencyLists* next;
    AdjacencyLists(){}
    AdjacencyLists(int x):item(x),next(NULL){}
    vector<AdjacencyLists> getGraph(vector<vector<int>>& input,int numOfVertices)
    {
        vector<AdjacencyLists> res;
        for(int i=1;i<=numOfVertices;i++)
        {
            res.push_back(i);
        }
        for(int i=0;i<input.size();i++)
        {
            AdjacencyLists **elements = &(res[i].next);
            for(int j=0;j<input[i].size();j++)
            {
                *elements = new AdjacencyLists(input[i][j]);
                elements = &((*elements)->next);
            }
        }
        return res;
    }
    AdjacencyLists* getList(vector<int>& input)
    {
        AdjacencyLists* res;
        AdjacencyLists** elements = &res;
        for(int i=0;i<input.size();i++)
        {
            *elements = new AdjacencyLists(input[i]);
            elements = &((*elements)->next);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> input = {
        {2,4},
        {3},
        {4,5,6},
        {},
        {},
        {5}
    };
    AdjacencyLists ob;
    vector<AdjacencyLists> res1 = ob.getGraph(input,6);
    vector<int> in = {1,2,3};
    AdjacencyLists* res2 = ob.getList(in);
    return 0;    
    // vector<AdjacencyLists> l;
    // for(int i=1;i<=6;i++)
    // {
    //     l.push_back(i);
    // }
    // for(int i=0;i<input.size();i++)
    // {
    //     AdjacencyLists temp;
    //     for(int j=0;j<input[i].size();j++)
    //     {
    //         AdjacencyLists *ob = new AdjacencyLists(input[i][j]);
    //         if(j==0)
    //         {
    //             l[i].next = ob;
    //             temp.next = ob;
    //         }
    //         else
    //         {
    //             temp.next->next = ob;
    //             temp.next = ob;
    //         }
    //     }
    // }
}