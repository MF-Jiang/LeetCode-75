# 1318. 或运算的最小翻转次数
给你三个正整数 a、b 和 c。

你可以对 a 和 b 的二进制表示进行位翻转操作，返回能够使按位或运算   a OR b == c  成立的最小翻转次数。

「位翻转操作」是指将一个数的二进制表示任何单个位上的 1 变成 0 或者 0 变成 1 。

 

## 示例 1：
![1](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/11/sample_3_1676.png)


输入：a = 2, b = 6, c = 5
输出：3
解释：翻转后 a = 1 , b = 4 , c = 5 使得 a OR b == c
## 示例 2：

输入：a = 4, b = 2, c = 7
输出：1
## 示例 3：

输入：a = 1, b = 2, c = 3
输出：0
 

## 提示：

1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9

## 代码：
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c = (c >> i) & 1;
            if (bit_c == 0) {
                ans += bit_a + bit_b;
            }
            else {
                ans += (bit_a + bit_b == 0);
            }
        }
        return ans;
    }
};


## 做法：
枚举+位运算
## 时间复杂度：
O(logC)
