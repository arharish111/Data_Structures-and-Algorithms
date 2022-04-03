#include <iostream>
#include <vector>
#include <stack>
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
    vector<vector<int>> res(n+1,vector<int>(n+1,0));
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

void dfs(vector<link>& g,int i,vector<int>& visited,vector<int>& color,
        vector<int>& pred,vector<int>& label,int c,vector<int>& startTime,vector<int>& finishTime,
        int* timer,int* noCycle,stack<int>& topology)
{
    *timer = *timer + 1;
    startTime[i] = *timer;
    color[i] = 1;
    link *temp = g[i].next;
    while(temp!=NULL)//For every v of u
    {
        if(color[temp->item] == 0)
        {
            visited.push_back(temp->item);
            pred[temp->item] = i;
            label[temp->item] = c;
            dfs(g,temp->item,visited,color,pred,label,c,startTime,finishTime,timer,noCycle,topology);   
        }
        if(color[temp->item] == 1)
        {
            *noCycle = 1;
        }
        temp = temp->next;
    }
    *timer = *timer + 1;
    finishTime[i] = *timer;
    topology.push(i);
    color[i] = 2;
}

int main()
{
    vector<vector<int>> input = {
        {0,5,1},
        {1,5},
        {2,5,3},
        {3},
        {4,1,5},
        {5},
        {6,2,3}
    };
    vector<link> res = getGraphList(input);
    vector<int> visited;
    vector<int> color(input.size(),0);
    vector<int> pred(input.size(),-1);
    vector<int> label(input.size(),0);
    int count = 1;
    int timer = 0;
    int noCycle = 0;
    vector<int> startTime(input.size(),0);
    vector<int> finishTime(input.size(),0);
    stack<int> topology;
    for(int i=0;i<input.size();i++)//For every u in g
    {
        if(color[i] == 0)
        {
            visited.push_back(i);
            label[i] = count;
            dfs(res,i,visited,color,pred,label,count,startTime,finishTime,&timer,&noCycle,topology);
            cout << "Group/Connected components in undirected graph " << count << ": " <<endl;
            for(int i=0;i<label.size();i++)
            {
                if(label[i]==count)
                cout << i << endl;
            }
            count++;
        }
    }
    cout << "Cycle(detected if color of v(neighbor of u) is gray): " << noCycle << endl;
    cout << "Topological Sort(increasing order of FT or use stack): " << endl;
    while(!topology.empty())
    { 
        cout << topology.top() << endl;
        topology.pop();
    }
    for(int i=0;i<visited.size();i++)
    {
        cout << "visited: " << visited[i] << endl;
        cout << "pred: " << pred[visited[i]] << endl;
        cout << "ST: " << startTime[visited[i]] << endl;
        cout << "FT: " << finishTime[visited[i]] << endl;
    }
    return 0;    
}