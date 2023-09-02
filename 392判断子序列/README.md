# 392. 判断子序列

给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

## 进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

 

## 示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true
## 示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false
 

## 提示：

0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成。

## 代码：

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
};


## 做法：
暴力解法

## 时间复杂度：
时间复杂度：O(n+m)，其中 n 为 s 的长度，m   t 的长度。每次无论是匹配成功还是失败，都有至少一个指针发生右移，两指针能够位移的总距离为 n+m。

空间复杂度：O(1)

## 动态规划DP！！！
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