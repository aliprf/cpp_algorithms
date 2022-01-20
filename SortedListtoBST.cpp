
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *sortedListToBST(vector<int> sortedVec, int fromIndex , int toIndex);

int main()
{
    vector<int> sortedVec = {2, 3, 5, 7, 9, 12, 22, 67, 99};
    TreeNode* node = sortedListToBST(sortedVec, 0, sortedVec.size());
    return -1;
}

TreeNode *sortedListToBST(vector<int> sortedVec, int fromIndex , int toIndex)
{
    if(toIndex< fromIndex) return NULL;

    if (fromIndex == toIndex)
    {
        TreeNode *node = new TreeNode();
        node->val = sortedVec[toIndex];
        return node;
    }
    int mid = (fromIndex + toIndex) /2;

    TreeNode *node = new TreeNode();
    node->val = sortedVec[mid];
    node->left = sortedListToBST(sortedVec, fromIndex, mid-1);
    node->right = sortedListToBST(sortedVec, mid+1, toIndex);

    return node;
}