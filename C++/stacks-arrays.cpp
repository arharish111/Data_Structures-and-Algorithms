#include <bits/stdc++.h>
using namespace std;

struct stacks {
    int *items;
    int  top;
    int maxSize;
};

stacks* createStack(int m){
    stacks* res = new stacks;
    res->items = new int[m];
    res->top = -1;
    res->maxSize = m;
    return res;
}

void push(stacks** s,int m){
    if(((*s)->top+1)==(*s)->maxSize){
        return;
    }
    (*s)->items[(*s)->top+1] = m;
    (*s)->top += 1;
}

int pop(stacks** s){
    if((*s)->top<0){
        return -1;
    }
    int item = (*s)->items[(*s)->top];
    (*s)->top -= 1;
    return item;
}

int main()
{
    stacks* res = createStack(3);
    push(&res,30);
    cout << pop(&res) << endl;
    cout << pop(&res) << endl;
    push(&res,40);
    push(&res,1);
    push(&res,1000);
    cout << pop(&res) << endl;
    push(&res,2000);
    cout << pop(&res) << endl;
    cout << pop(&res) << endl;
    return 0;
}
