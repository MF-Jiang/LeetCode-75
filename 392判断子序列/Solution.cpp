class Solution {
public:
    //dp解法
    bool isSubsequence(string s, string t){
        int n = s.length(),m = t.length();
        //dp数组dp[i][j]表示字符串t以i位置开始第一次出现字符j的位置
        vector<vector<int>> dp(m + 1,vector<int> (26,0));

        //初始化边界条件，dp[i][j] = m表示t中不存在字符j
        for(int i=0;i<26;i++){
            dp[m][i] = m;
        }

        //从后往前递推初始化dp数组
        for(int i = m - 1;i>=0;i--) {
            for(int j=0;j<26;j++){
                if(t[i] == 'a' + j){
                    dp[i][j] = i;
                }else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        int add = 0;
        for(int i = 0;i<n;i++){
            //t中没有s[i] 返回false
            if(dp[add][s[i] - 'a'] == m){
                return false;
            }
            //否则直接跳到t中s[i]第一次出现的位置之后一位
            add = dp[add][s[i] - 'a'] + 1;
        }
        return true;
    }
};