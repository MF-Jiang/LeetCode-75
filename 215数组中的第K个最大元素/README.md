# 215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

## 示例 1:

输入: [3,2,1,5,6,4], k = 2
输出: 5
## 示例 2:

输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4
 

## 提示：

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

## 代码：
class Solution {
public:
    int quickselect(vector<int> &nums, int l, int r, int k) {
        if (l == r)
            return nums[k];
        int partition = nums[l], i = l - 1, j = r + 1;
        while (i < j) {
            do i++; while (nums[i] < partition);
            do j--; while (nums[j] > partition);
            if (i < j)
                swap(nums[i], nums[j]);
        }
        if (k <= j)return quickselect(nums, l, j, k);
        else return quickselect(nums, j + 1, r, k);
    }

    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }
};

## 做法：
通过快排进行选择
## 时间复杂度：
O(n)，空间复杂度O(logn)