class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        map<int,int>row;
        map<int,int>column;
        for(int i=0;i<n;i++)
        {
          row.insert({i,0});  
        }
        for(int i=0;i<m;i++)
        {
          column.insert({i,0});  
        }
        for(int i=0;i<indices.size();i++)
        {
            int r = indices[i][0];
            int c = indices[i][1];
            row[r] = row[r] + 1;
            column[c] = column[c] + 1;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int res = row[i] + column[j];
                if(res%2!=0)
                {
                    count +=1;
                }
            }
        }
        return count;
    }
};