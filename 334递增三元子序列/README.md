# 334. 递增的三元子序列
给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。

 

## 示例 1：

输入：nums = [1,2,3,4,5]
输出：true
解释：任何 i < j < k 的三元组都满足题意
## 示例 2：

输入：nums = [5,4,3,2,1]
输出：false
解释：不存在满足题意的三元组
## 示例 3：

输入：nums = [2,1,5,0,4,6]
输出：true
解释：三元组 (3, 4, 5) 满足题意，因为 nums[3] == 0 < nums[4] == 4 < nums[5] == 6
 

## 提示：

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
 

## 进阶：你能实现时间复杂度为 O(n) ，空间复杂度为 O(1) 的解决方案吗？

## 代码：
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        int first = nums[0], second = INT_MAX;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            if (num > second) {
                return true;
            } else if (num > first) {
                second = num;
            } else {
                first = num;
            }
        }
        return false;

    }
};

## 做法：
确定第一个数后，取第二个数如果比第一个大则找第三个数，如果第三个数比第一个大比第二个小，则将这个数定为第二个数，如果找到大于第二个数的第三个数，则返回true

这里有一定的分治想法。分成两部分，找second大于first，和找third大于second。first second和third不一定是一组同时符合条件的解。但只要有third被确定，就表示找到了最后的结果。

## 时间复杂度：
O(n)。空间复杂度O(1)。