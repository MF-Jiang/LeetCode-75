# 1768. 交替合并字符串

给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。

返回合并后的字符串。

## 示例 1：

输入：word1 = "abc", word2 = "pqr"
输出："apbqcr"
解释：字符串合并情况如下所示：
word1：  a   b   c
word2：    p   q   r
合并后：  a p b q c r

## 示例 2：

输入：word1 = "ab", word2 = "pqrs"
输出："apbqrs"
解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
word1：  a   b 
word2：    p   q   r   s
合并后：  a p b q   r   s

## 示例 3：

输入：word1 = "abcd", word2 = "pq"
输出："apbqcd"
解释：注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
word1：  a   b   c   d
word2：    p   q 
合并后：  a p b q c   d
 

## 提示：

1 <= word1.length, word2.length <= 100
word1 和 word2 由小写英文字母组成


## 代码
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len=0;
        string ans;
        if(word1.size()>word2.size()){
            len = word1.size();
        }else{
            len = word2.size();
        }
        ans.reserve(len);
        int index=0;
        for(int i=0;i<len;i++){
            if(index<word1.size()){
                ans.push_back(word1[index]);
                //cout<<word1[index];
            }
            if(index<word2.size()){
                ans.push_back(word2[index]);
                //cout<<word2[index];
            }
            index++;
        }
        return ans;
    }
};

## 做法
遍历较长的字符串，每次同时从两个字符串中分别取一个字符加入新字符串中，如果一个字符串被用完，则把另一个字符串中的字符取完。

## 时间复杂度
O(max(word1.size(),word2.size)) ==> O(n)
 
