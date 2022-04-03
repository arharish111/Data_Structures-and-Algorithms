#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct node* link;

struct node
{
    int item;
    link left;
    link right;
    node(int x): item(x),left(NULL),right(NULL){}
};

void insertElement(link* root,int i)
{
    if(*root==NULL)
    {
        *root = new node(i);
        return;
    }
    queue<link*> q;
    q.push(root);
    while(!q.empty())
    {
        link* element = q.front();
        q.pop();
        if(*element != NULL)
        {
            q.push(&(*element)->left);
            q.push(&(*element)->right);
        }
        else
        {
            *element =  new node(i);
            break;
        }
    }
    return;
}


link getBinaryTree(vector<int>& nums)
{
    link result = NULL; 
    if(nums.size()<1)
        return result;
    for(int i=0;i<nums.size();i++)
    {
        insertElement(&result,nums[i]);
    }
    return result;
}

void printLevelOrder(link tree)
{
    if(tree==NULL)
        return;
    queue<link> q;
    q.push(tree);
    while(!q.empty())
    {
        link element = q.front();
        q.pop();
        cout << element->item << endl;
        if(element->left != NULL)
            q.push(element->left);
        if(element->right != NULL)
            q.push(element->right);
    }
    
}

void printInorder(link tree)
{
    if(tree==NULL)
        return;
    printInorder(tree->left);
    cout << tree->item << endl;
    printInorder(tree->right);
}

void printPreOrder(link tree)
{
   if(tree==NULL)
        return;
    cout << tree->item << endl;
    printPreOrder(tree->left);
    printPreOrder(tree->right);
}

void printPostOrder(link tree)
{
    if(tree==NULL)
        return;
    printPostOrder(tree->left);
    printPostOrder(tree->right);
    cout << tree->item << endl;
}

int getNumberOfNodes(link tree)
{
    if(tree==NULL)
        return 0;
    int lCount = getNumberOfNodes(tree->left);
    int rCount = getNumberOfNodes(tree->right);
    return lCount + rCount + 1;
}

int getHeightOfTheTree(link tree)
{
    if(tree == NULL)
        return 0;
    int lH = getHeightOfTheTree(tree->left);
    int rH = getHeightOfTheTree(tree->right);
    if(lH > rH)
        return lH + 1;
    else
        return rH + 1;
}

void insertElementInBST(link* tree,int i)
{
    if(*tree == NULL)
    {
        *tree = new node(i);
        return;
    }
    if(i<=(*tree)->item)
        insertElementInBST(&(*tree)->left,i);
    else
        insertElementInBST(&(*tree)->right,i);
}

link getBST(vector<int> nums)
{
    link res = NULL;
    for(auto i:nums)
    {
        insertElementInBST(&res,i);
    }
    return res;
}

void printAllPaths(link tree,vector<int>& nums)
{
    if(tree == NULL)
        return;
    if(tree->left == NULL && tree->right == NULL)
    {
        for(auto &i:nums)
            cout << i << ",";
        cout << tree->item << endl;
    }
    nums.push_back(tree->item);
    printAllPaths(tree->left,nums);
    printAllPaths(tree->right,nums);
    nums.pop_back();
}

int getMinInBST(link tree)
{
    if(tree==NULL)
        return -1;
    if(tree->left==NULL)
        return tree->item;
    return getMinInBST(tree->left);
}

bool hasPathSum(link tree,int sum)
{
    if(tree==NULL)
    {
        return (sum==0);
    }
    else
    {
        int subSum = sum - tree->item;
        return (hasPathSum(tree->left,subSum) || hasPathSum(tree->right,subSum));
    }
}

int main()
{
    vector<int> nums = {3,2,4,0,3};
    link res = getBST(nums);
    vector<int> numbers;
    cout << hasPathSum(res,4);
    return 0;
}