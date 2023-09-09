# 872. 叶子相似的树
请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。

![1](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png)

举个例子，如上图所示，给定一棵叶值序列为 (6, 7, 4, 9, 8) 的树。

如果有两棵二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

如果给定的两个根结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

 

## 示例 1：

![2](https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-1.jpg)

输入：root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
输出：true
## 示例 2：

![3](https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-2.jpg)

输入：root1 = [1,2,3], root2 = [1,3,2]
输出：false
 

## 提示：

给定的两棵树结点数在 [1, 200] 范围内
给定的两棵树上的值在 [0, 200] 范围内

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
    void dfs(TreeNode* node, vector<int>& seq) {
        if (!node->left && !node->right) {
            seq.push_back(node->val);
        }
        else {
            if (node->left) {
                dfs(node->left, seq);
            }
            if (node->right) {
                dfs(node->right, seq);
            }
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        if (root1) {
            dfs(root1, seq1);
        }

        vector<int> seq2;
        if (root2) {
            dfs(root2, seq2);
        }

        return seq1 == seq2;
    }
};

## 做法：
我们可以使用深度优先搜索的方法得到一棵树的「叶值序列」。

具体地，在深度优先搜索的过程中，我们总是先搜索当前节点的左子节点，再搜索当前节点的右子节点。如果我们搜索到一个叶节点，就将它的值放入序列中。

在得到了两棵树分别的「叶值序列」后，我们比较它们是否相等即可。


## 时间复杂度：
O(n1+n2)

