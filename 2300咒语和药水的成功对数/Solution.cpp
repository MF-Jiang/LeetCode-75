class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        sort(potions.begin(), potions.end());
        for (auto &x : spells)
            x = potions.end() - upper_bound(potions.begin(), potions.end(), (success - 1) / x);
        return spells;
    }
};

