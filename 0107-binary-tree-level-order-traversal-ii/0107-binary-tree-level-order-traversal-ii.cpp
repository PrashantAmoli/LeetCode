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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> output;
      if(root == nullptr) return output;
      
      queue<TreeNode*> q;
      q.push(root);
      
      while(!q.empty()){
        vector<int> v;
        int n = q.size();
        
        for(int i=0 ; i<n ; i++){
          TreeNode* node = q.front();
          q.pop();
          if(node->left != nullptr) q.push(node->left);
          if(node->right != nullptr) q.push(node->right);
          v.push_back(node->val);
        }
        output.push_back(v);
      }
      reverse(output.begin(), output.end());
      return output;
    }
};