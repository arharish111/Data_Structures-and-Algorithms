class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> numbers;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            auto search = numbers.find(target - nums[i]);
            if(search != numbers.end()){
                res.push_back(i);
                res.push_back(search->second);
                break;
            }
            numbers[nums[i]] = i;
        }
        return res;
    }
};