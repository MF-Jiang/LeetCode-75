# 1161. 最大层内元素和
给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。

请返回层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。

 

## 示例 1：

![1](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/08/17/capture.jpeg)

输入：root = [1,7,0,7,-8,null,null]
输出：2
解释：
第 1 层各元素之和为 1，
第 2 层各元素之和为 7 + 0 = 7，
第 3 层各元素之和为 7 + -8 = -1，
所以我们返回第 2 层的层号，它的层内元素之和最大。
## 示例 2：

输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
输出：2
 

## 提示：

树中的节点数在 [1, 10^4]范围内
-105 <= Node.val <= 105

## 代码：
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
    int maxLevelSum(TreeNode *root) {
        int ans = 1, maxSum = root->val;
        vector<TreeNode*> q = {root};
        for (int level = 1; !q.empty(); ++level) {
            vector<TreeNode*> nq;
            int sum = 0;
            for (auto node : q) {
                sum += node->val;
                if (node->left) {
                    nq.emplace_back(node->left);
                }
                if (node->right) {
                    nq.emplace_back(node->right);
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                ans = level;
            }
            q = move(nq);
        }
        return ans;
    }
};


## 做法：
广度优先搜索
## 时间复杂度：
O(n)
