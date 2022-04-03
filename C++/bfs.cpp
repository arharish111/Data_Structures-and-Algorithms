#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct link {
    int item;
    link *next;
    link(int x) : item(x), next(NULL){}
};

vector<link> getGraphList(vector<vector<int>>& input)
{
    vector<link> res;
    for(int i=0;i<input.size();i++)
    {
        res.push_back(input[i][0]);
    }
    for(int i=0;i<input.size();i++)
    {
        link **elements = &(res[i].next);
        for(int j=1;j<input[i].size();j++)
        {
            *elements = new link(input[i][j]);
            elements = &((*elements)->next);
        }
    }
    return res;
}

vector<vector<int>> getGraphMatrix(vector<vector<int>>& input)
{
    int n = input.size();
    vector<vector<int> > res(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++)
    {
        int num1 = input[i][0];
        for(int j=1;j<input[i].size();j++)
        {
            res[num1][input[i][j]] = 1;
            res[input[i][j]][num1] = 1;
        }
    }
    return res;
}

vector<vector<int>> bfs(vector<link>& g,int s)
{
    vector<int> color(g.size(),0);
    vector<int> distance(g.size(),0);
    vector<int> pred(g.size(),-1);
    vector<int> visited;
    color[s] = 1;
    queue<int> q;
    q.push(s);
    visited.push_back(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        link *temp = g[u].next;
        while(temp!=NULL)
        {
            int v = temp->item;
            if(color[v]==0)
            {
                visited.push_back(v);
                color[v] = 1;
                distance[v] = distance[u] + 1;
                pred[v] = u;
                q.push(v);
            }
            temp = temp->next;
        }
        color[u] = 2;
    }
    vector<vector<int>> result;
    result.push_back(visited);
    result.push_back(distance);
    return result;
}
int main()
{
    vector<vector<int>> input = {
        {0,5,1,4},
        {1,5,0,4,6},
        {2,6,3},
        {3,2,6},
        {4,1,5,7,0},
        {5,4,0,1,6},
        {6,2,3,5,1},
        {7,4}
    };
    vector<link> res = getGraphList(input);
    vector<int> v = bfs(res,1)[0];
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << endl;
    }
    return 0;    
}