#include <bits/stdc++.h>
using namespace std;

struct link {
    int item;
    link *next;
};
struct lists {
    link *first;
    int length;    
};

lists* getList(vector<int>& nums){
    lists *res = new lists;
    link *elements = new link[nums.size()];
    int i;
    for(i=0;i<nums.size()-1;i++){
        elements[i].item = nums[i];
        elements[i].next = &elements[i+1];
    }
    elements[i].item = nums[i];
    elements[i].next = NULL;
    res->first = &elements[0];
    res->length = nums.size();
    return res;
}

int main()
{
    vector<int> nums = {3,2,1};
    lists *ress = getList(nums);
    link *curr = ress->first;
    while(curr!=NULL){
        cout << curr->item << endl;
        curr = curr->next;
    }
    return 0;
}