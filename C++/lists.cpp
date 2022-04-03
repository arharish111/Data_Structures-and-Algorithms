#include <bits/stdc++.h>
using namespace std;

struct link {
    int item;
    link *next;
    link(int x) : item(x), next(NULL) {}
};

link* getList(vector<int>& nums){
    link *res =NULL;
    link **elements=&res;
    int i;
    for(i=0;i<nums.size();i++){
        *elements = new link(nums[i]);
        elements = &((*elements)->next);
    }
    return res;
}

void printList(link** l){
    while(*l!=NULL){
        cout << (*l)->item << endl;
        *l = (*l)->next;
    }
}

void destroyList(link** l){
    while(*l!=NULL){
        link* i = (*l)->next;
        delete *l;
        *l = i;
    }
    *l = NULL;
}

void insertAtBeginning(link** l,int n){
    link *ne = new link(n);
    ne->next = *l;
    *l = ne;
}

void removeFirst(link** l){
    if(*l==NULL){
        return;
    }
    *l = (*l)->next;
}

void insertAtEnd(link** l,link* o){
    if(*l==NULL){
        *l = o;
    }
    link* i = *l;
    while(i->next!=NULL){
        i = i->next;
    }
    i->next = o;
}

void reverseList(link** l){
    link* curr = *l;
    link* pre = NULL;
    while(curr!=NULL){
        link* temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    *l = pre;
}

bool detectCircle(link** l){
    if(l == NULL)
    {
        return false;
    }
    link* fast = (*l)->next;
    link* slow = *l;
    while(fast!=NULL && fast->next!=NULL && slow!=NULL){
        if(fast==slow)
            return true;
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

int main()
{
    vector<int> nums = {3,2,1,4};
    link *ress = getList(nums);
    insertAtBeginning(&ress,5);
    link *e = new link(6);
    insertAtEnd(&ress,e);
    reverseList(&ress);
    removeFirst(&ress);
    printList(&ress);
    cout << detectCircle(NULL) << endl;
    destroyList(&ress);
    return 0;
}