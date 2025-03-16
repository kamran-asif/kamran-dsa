
class Solution {
public:
    vector<TreeNode*> generatehelper(int start, int end) {
        if (start > end) return {nullptr}; // Base case

        vector<TreeNode*> allTrees;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generatehelper(start, i - 1);
            vector<TreeNode*> rightTrees = generatehelper(i + 1, end); // Fixed declaration

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generatehelper(1, n);
    }
};