//Very good question
//sharp mid required
//MOST REVISE

class Solution {
public:
    void leftBoundary(Node* root, vector<int>& ans) {
        Node* curr = root->left;
        while (curr) {
            if (curr->left != NULL || curr->right != NULL) {
                ans.push_back(curr->data);
            }
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    void leafNodes(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
    }

    void rightBoundary(Node* root, vector<int>& ans) {
        vector<int> tmp;
        Node* curr = root->right;
        while (curr) {
            if (curr->left != NULL || curr->right != NULL) {
                tmp.push_back(curr->data);
            }
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        reverse(tmp.begin(), tmp.end());
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }

    vector<int> boundary(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        // Add root node (only if it's not a leaf node)
        if (root->left != NULL || root->right != NULL) {
            ans.push_back(root->data);
        }

        // Get the left boundary in top-down manner (excluding leaf nodes)
        leftBoundary(root, ans);

        // Get all leaf nodes
        leafNodes(root, ans);

        // Get the right boundary in bottom-up manner (excluding leaf nodes)
        rightBoundary(root, ans);

        return ans;
    }
};
