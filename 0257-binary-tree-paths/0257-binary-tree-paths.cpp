/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, string s, vector<string> &ans){
      if(!root) return;
      
      s+= to_string(root->val);
      
      if( !root->left and !root->right ) {
        ans.push_back(s);
        return;
      }
      s += "->";
      
      inorder(root->left, s, ans);
      inorder(root->right, s, ans);
    }
  
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> ans;
      string s= "";
      inorder(root, s, ans);
      return ans;
    }
};