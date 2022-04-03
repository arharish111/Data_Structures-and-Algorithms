#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pairOfInts;

struct link
{
    int item;
    int weight;
    link *next;
    link(int val,int w): item(val),weight(w),next(NULL) {}
    link(int val): item(val),next(NULL),weight(0) {}
};

void insertItemAtEndOfList(vector<link>& res,int index,int item,int w)
{
    link* temp = &res[index];
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    link* element = new link(item,w);
    temp->next = element;
}

vector<link> getAdjacencyList(vector<vector<int>> input,int numOfVertices)
{
    vector<link> res;
    for(int i=0;i<numOfVertices;i++)
    {
        res.push_back(i);
    }
    for(int i=0;i<input.size();i++)
    {
        insertItemAtEndOfList(res,input[i][0],input[i][1],input[i][2]);
        insertItemAtEndOfList(res,input[i][1],input[i][0],input[i][2]);
    }
    return res;
}

vector<vector<int>> primMST(vector<link>g,int startIndex,int numOfVertices)
{
    vector<vector<int>> result;
    set<int> vertices;
    vector<int> parent(numOfVertices,-1);
    vector<int> weights(numOfVertices,INT_MAX);
    weights[startIndex] = 0;
    for(int i=0;i<numOfVertices;i++)
    {
        vertices.insert(i);
    }
    while(!vertices.empty())
    {
        auto it = min_element(weights.begin(),weights.end());
        int u = distance(weights.begin(),it);
        vector<int> localRes = {parent[u],u,weights[u]};
        result.push_back(localRes);
        
        weights[u] = INT_MAX;
        vertices.erase(u);
        
        link* temp = g[u].next;
        
        while(temp!=NULL)
        {
            int v = temp->item;
            int w = temp->weight;
            auto search = vertices.find(v);
            if(search!=vertices.end() && w<weights[v])
            {
                parent[v] = u;
                weights[v] = w;
            }
            temp = temp->next;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> g = {
        {0,5,10},
        {0,1,20},
        {0,7,15},
        {0,2,30},
        {0,6,20},
        {5,3,15},
        {5,4,18},
        {3,4,25},
        {7,4,10},
        {4,6,30}
    };
    vector<link> graph = getAdjacencyList(g,8);
    vector<vector<int>> result = primMST(graph,7,8);
    int sum = 0;
    for(int i=0;i<result.size();i++)
    {
        cout << result[i][0] << result[i][1] << result[i][2] << endl;
        sum += result[i][2];
    }
    cout << sum << endl;
    return 0;
}