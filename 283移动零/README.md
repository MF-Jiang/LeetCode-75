## 代码：
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

## 做法：
遍历数组，定位到0两两交换

## 时间复杂度：
O(n),空间复杂度O(1)。