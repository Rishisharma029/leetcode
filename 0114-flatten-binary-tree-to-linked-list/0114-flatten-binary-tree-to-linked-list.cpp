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
    void flatten(TreeNode* root) {

        while (root) {

            if (root->left) {

                // Find rightmost node of left subtree
                TreeNode* prev = root->left;

                while (prev->right)
                    prev = prev->right;

                // Connect original right subtree
                prev->right = root->right;

                // Move left subtree to right
                root->right = root->left;
                root->left = nullptr;
            }

            root = root->right;
        }
    }
};