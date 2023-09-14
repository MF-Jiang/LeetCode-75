class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = (int)nums1.size();

        int idxs[n];
        for (int i = 0; i < n; i ++){
            idxs[i] = i;
        }
        sort(idxs, idxs + n, [&](const int & i, const int & j){
            return nums2[i] > nums2[j];
        });

        long long res = 0LL;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum1 = 0LL;
        for (int idx: idxs){
            int x = nums1[idx];
            int y = nums2[idx];

            while ((int)minHeap.size() > k - 1){
                sum1 -= minHeap.top();  minHeap.pop();
            }
            minHeap.push(x);
            sum1 += x;

            if ((int)minHeap.size() == k){
                long long cur = sum1 * y;
                res = max(res, cur);
            }
        }

        return res;
    }
};
