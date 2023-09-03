class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; 
    }
    
    int maxVowels(string s, int k) {
        int n = s.size();
        int vowel_count = 0;
        for (int i = 0; i < k; ++i) {
            vowel_count += isVowel(s[i]);
        }
        int ans = vowel_count;
        for (int i = k; i < n; ++i) {
            vowel_count += isVowel(s[i]) - isVowel(s[i - k]);
            ans = max(ans, vowel_count);
        }
        return ans;
    }
};
