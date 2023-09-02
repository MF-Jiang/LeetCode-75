class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        //排序
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int count = 0;
        while(left < right)
        {
            if(nums[left] + nums[right] < k)
            {
                left ++;
            }
            else if(nums[left] + nums[right] > k)
            {
                right --;
            }
            else{
                right --;
                left ++;
                count ++;
            }
        }
        return count;

    }
};
