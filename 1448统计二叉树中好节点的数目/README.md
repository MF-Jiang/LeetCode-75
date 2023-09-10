# 1448. 统计二叉树中好节点的数目
给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。

 

## 示例 1：

![1](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/16/test_sample_1.png)

输入：root = [3,1,4,3,null,1,5]
输出：4
解释：图中蓝色节点为好节点。
根节点 (3) 永远是个好节点。
节点 4 -> (3,4) 是路径中的最大值。
节点 5 -> (3,4,5) 是路径中的最大值。
节点 3 -> (3,1,3) 是路径中的最大值。
## 示例 2：

![2](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/16/test_sample_2.png)

输入：root = [3,3,null,4,2]
输出：3
解释：节点 2 -> (3, 3, 2) 不是好节点，因为 "3" 比它大。
## 示例 3：

输入：root = [1]
输出：1
解释：根节点是好节点。
 

## 提示：

二叉树中节点数目范围是 [1, 10^5] 。
每个节点权值的范围是 [-10^4, 10^4] 。

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
    int dfs(TreeNode* root, int path_max) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        if (root->val >= path_max) {
            res++;
            path_max = root->val;
        }
        res += dfs(root->left, path_max) + dfs(root->right, path_max);
        return res;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};

## 做法：
在题目的定义中，从根到好节点所经过的节点中，没有任何节点的值大于好节点的值，等同于根节点到好节点的路径上所有节点（不包括好节点本身）的最大值小于等于好节点的值。

因此我们可以在深度优先遍历的过程中，记录从根节点到当前节点的路径上所有节点的最大值，若当前节点的值大于等于该最大值，则认为当前节点是好节点。

具体来说，定义递归函数求解以某个节点为根的子树中，好节点的个数。递归函数的参数为根节点以及路径上的最大值，若当前节点的值大于等于该最大值，则将答案加一，并更新路径最大值为当前节点的值。紧接着递归遍历左右子树时，将最大值以参数的形式传递下去。递归返回的结果需要累加到答案中。

最终，我们以根节点为入口，无穷小为路径最大值去调用递归函数，所得到的返回值即为答案。



## 时间复杂度：
O(n),空间复杂度O(n)
