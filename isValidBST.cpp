#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool isValidBST(TreeNode* root);
void preOrderTravers(TreeNode* root, stack<int> &stc);
void inOrderTravers(TreeNode* root, vector<int> &result);
void postOrderTravers(TreeNode* root, vector<int> &result);
TreeNode *defineTree();

int main ()
{   
    TreeNode* tree = defineTree();

    cout << isValidBST(tree) << "\n\r";

}

TreeNode *defineTree()
{
    TreeNode* tree = new TreeNode();
    
    tree->val = 3;
    tree->left =  new TreeNode();
    tree->right =  new TreeNode();

    tree->left->val = 1;
    tree->left->left = new TreeNode();
    tree->left->right = new TreeNode();
    tree->left->left->val=0;
    tree->left->right->val=2;

    tree->right->val = 5;
    tree->right->left = new TreeNode();
    tree->right->right = new TreeNode();

    tree->right->left->val=4;
    tree->right->right->val=6;
    
    return tree;
}

void inOrderTravers(TreeNode* root, vector<int> &result)
{
    if(!root) return;

    inOrderTravers(root->left, result);

    result.push_back(root->val);

    inOrderTravers(root->right, result);

}

bool isValidBST(TreeNode* root) 
{
    vector<int> sorted; 
    inOrderTravers(root, sorted);
    // postOrderTravers(root, sorted);
    for(int i=1; i<sorted.size(); i++)
        if(sorted[i]< sorted[i-1]) return false;
    return true;
}

void preOrderTravers(TreeNode* root, stack<int> &stc)
{
    if(!root) return;

    stc.push(root->val);

    preOrderTravers(root->left, stc);
    preOrderTravers(root->right, stc);
}

void postOrderTravers(TreeNode* root, vector<int> &result)
{
    if(!root) return;

    postOrderTravers(root->left, result);
    postOrderTravers(root->right, result);
    result.push_back(root->val);
}

// int isValidTree(TreeNode* root, int minVal, int maxVal) 
// {
//     int isValidLeft = 1, isValidRight=1;
//     if(root)
//     {
//         if(root->left)
//         {
//             if (root->left->val < root->val && ( minVal== -1 || root->left->val < maxVal))
//             {
//                 isValidLeft = isValidTree(root->left, root->left->val, root->val);
//             }
//             else
//             {
//                 isValidLeft=0;
//             }
//         }
//         if(root->right)
//         {
//             if (root->right->val > root->val && ( minVal== -1 || root->right->val > minVal)) //  && root->right->val < maxVal  ))
//             {
//                 isValidRight = isValidTree(root->right, root->val, root->right->val);
//             }
//             else
//             {
//                 isValidRight=0;
//             }
//         }
//     }
//     return isValidLeft*isValidRight;
// }

