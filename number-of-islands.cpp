#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int h = grid.size();
        int w = grid[0].size();
        vector<vector<char>> color(h,vector<char>(w,'0'));
        int result = 0;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(color[i][j] == '0' && grid[i][j] == '1')
                {
                    result += bfs(grid,i,j,color,w,h);   
                }
            }
        }
        return result;
    }
    
    int bfs(vector<vector<char>>& grid,int u,int v,vector<vector<char>>& color,int w,int h)
    {
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,-1,0,1};
        queue<pair<int,int>> q;
        q.push(make_pair(u,v));
        color[u][v] = '1';
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=h || newY>=w || newX<0 || newY<0)
                    continue;
                if(grid[newX][newY] == '1' && color[newX][newY] == '0')
                {
                    color[newX][newY] = '1';
                    q.push(make_pair(newX,newY));
                }
            }
        }
        return 1;
     }
};