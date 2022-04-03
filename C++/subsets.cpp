class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int powerSet = pow(2,nums.size());
        int counter,j;
        for(counter=0;counter<powerSet;counter++)
        {
            vector<int> temp;
            for(j=0;j<nums.size();j++)
            {
                if(counter&(1<<j))
                {
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};