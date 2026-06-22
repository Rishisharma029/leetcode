/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        Node* curr = root;

        while (curr) {

            Node* head = nullptr; // first node of next level
            Node* prev = nullptr; // previous node on next level

            while (curr) {

                // Left child
                if (curr->left) {
                    if (!head)
                        head = curr->left;

                    if (prev)
                        prev->next = curr->left;

                    prev = curr->left;
                }

                // Right child
                if (curr->right) {
                    if (!head)
                        head = curr->right;

                    if (prev)
                        prev->next = curr->right;

                    prev = curr->right;
                }

                curr = curr->next;
            }

            curr = head;
        }

        return root;
    }
};