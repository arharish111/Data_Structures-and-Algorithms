#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1,4,2,5,3};
    vector<int> sortedNums = {0,2,4,1,3};
    int key = 1,res=-1;
    int high = nums.size();
    int low = 0;
    int mid = (low+high)/2;
    while(low<=high){
        if(nums[sortedNums[mid]] == key){
            res = mid;
            break;
        }
        else if(nums[sortedNums[mid]] > key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        mid = (low+high)/2;
    }
    cout << res << endl;
    return 0;
}