class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    bool check(int mask, int k, int n) {
        temp.clear();
        for (int i = 0; i < 9; ++i) {
            if ((1 << i) & mask) {
                temp.push_back(i + 1);
            }
        }
        return temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == n; 
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        for (int mask = 0; mask < (1 << 9); ++mask) {
            if (check(mask, k, n)) {
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};

