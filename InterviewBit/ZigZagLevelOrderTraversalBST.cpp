/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /* Author : Saurav Dubey */
int height(TreeNode* A)
{
    if (!A)
        return 0;
    return 1 + max(height(A->left), height(A->right));
}

void levelTraversal(vector<int>& res, TreeNode* A, int level, bool inverse)
{
    if (!A)
        return;
    if (level == 1)
        res.emplace_back(A->val);
    else
    {
        if (inverse)
        {
            levelTraversal(res, A->right, level-1, inverse);
            levelTraversal(res, A->left, level-1, inverse);
        }
        else
        {
            levelTraversal(res, A->left, level-1, inverse);
            levelTraversal(res, A->right, level-1, inverse);
        }
    }
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    int levels = height(A);
    vector<vector<int> > res;
    for (auto h = 1; h<=levels; ++h)
    {
        bool inverse = false;
        vector<int> row;
        if (h%2 == 0)
            inverse = true;
        levelTraversal(row, A, h, inverse);
        res.emplace_back(row);
    }
    return res;
}
