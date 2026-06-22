/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> pos;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int left, int right) {
        if (left > right)
            return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];

        // Right subtree first
        root->right = build(postorder, mid + 1, right);
        root->left = build(postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return build(postorder, 0, inorder.size() - 1);
    }
};