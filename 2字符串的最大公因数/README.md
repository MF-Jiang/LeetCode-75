# 1071. 字符串的最大公因子

对于字符串 s 和 t，只有在 s = t + ... + t（t 自身连接 1 次或多次）时，我们才认定 “t 能除尽 s”。

给定两个字符串 str1 和 str2 。返回 最长字符串 x，要求满足 x 能除尽 str1 且 x 能除尽 str2 。

 

## 示例 1：

输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"

## 示例 2：

输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"

## 示例 3：

输入：str1 = "LEET", str2 = "CODE"
输出：""
 

## 提示：

1 <= str1.length, str2.length <= 1000
str1 和 str2 由大写英文字母组成

## 代码：
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, __gcd((int)str1.length(), (int)str2.length())); // __gcd() 为c++自带的求最大公约数的函数
    }
};

## 做法：
这是一个很不错的方法。(我傻傻遍历了，没想到，这是标准答案)
需要知道一个性质：如果 str1 和 str2 拼接后等于 str2和 str1 拼接起来的字符串（注意拼接顺序不同），那么一定存在符合条件的字符串 X。

先证必要性，即如果存在符合条件的字符串 X ，则 str1 和 str2 拼接后等于 str2和 str1 拼接起来的字符串。

如果字符串 X 符合条件，那么 str1=X+X+...+X+X=n*X ，str2=X+X+..+X+X=m*X，n*X 表示 n 个字符串 X 拼接，m*X 同理，则 str1 与 str2 拼接后的字符串即为 (n+m)*X，而 str2 与 str1 拼接后的字符串即为 (m+n)*X，等于 (n+m)*X，所以必要性得证。

再看充分性，简单来说，我们可以如下图一样先将两个拼接后的字符串放在一起。不失一般性，我们假定 str1 的长度大于 str2，

![图1](https://assets.leetcode-cn.com/solution-static/1071_fig1.png)

我们等间隔取 gcd(len1,len2)长度的字符串。

如果该长度等于 str2 的长度，即 str1 的长度可以整除 str2 的长度。我们可以知道，已知图中第一部分等于图中的第二部分（都是字符串 str1 的开头），而图中的第二部分又等于第三部分（两个字符串相等），所以我们知道第三部分也是等于第一部分。同理我们可以推得图中划分的 1,3,5,7 四个部分都相等，所以拼接起来的字符串可以由第一部分的前缀串经过若干次拼接得到。

![图2](https://assets.leetcode-cn.com/solution-static/1071_fig2.png)

那么如果不等于 str2 的长度，我们由上文一样的方法可以推得下图中被染颜色相同的字符串片段是相等的，其中每个颜色片段都是长为gcd(len1,len2)的字符串。那么不同颜色代表的字符串是否也相等呢？如果相等就可以推得我们的结论是正确的。

![图3](https://assets.leetcode-cn.com/solution-static/1071_fig3.gif)

其实由上图我们可以知道，因为第一个字符串和第二个字符串相等，所以两个字符串开头的部分必然相等。我们将前len2/(gcd(len1,len2))个被染颜色的部分放在一起比较即可推得不同颜色的部分都是两两相等的，但是这是基于它们开头被染的颜色顺序是不同的，这一定成立吗？
其实图中可以看出第一个字符串被染的颜色是以 str2 的长度在循环的，由于第二种情况下 str1 的长度不整除 str2 的长度，导致第一个字符串的 str1 部分被染完颜色的时候，str2 被染的颜色的顺序必然不等于开头 str1 被染的颜色顺序，而第二个字符串的开头又是 str2，它被染色的顺序是等于第一个字符串中 str2 被染色的顺序的，所以两个字符串的开头被染的颜色顺序一定不同。最后我们就推出如果 str1 和 str2 拼接后等于 str2 和 str1 拼接起来的字符串，那么一定存在符合条件的字符串 X。

![图四](https://assets.leetcode-cn.com/solution-static/1071_fig4.gif)
