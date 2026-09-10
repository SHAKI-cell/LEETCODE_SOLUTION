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
typedef pair<int,int> pi;
    int res=0;
    pi solve(TreeNode* root){
         if(root==NULL) return {0,0};
          auto p1=solve(root->left);
           auto p2=solve(root->right);
         int total= p1.first+p2.first+root->val;
         int count=p1.second+p2.second+1;
         int avg=total/count;
         if(avg==root->val) res+=1;
         return {total,count};
    }
    int averageOfSubtree(TreeNode* root) {
       solve(root);
       return res;
    }
};