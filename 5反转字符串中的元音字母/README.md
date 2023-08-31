# 345. 反转字符串中的元音字母

给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。

元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。

 

## 示例 1：

输入：s = "hello"
输出："holle"

## 示例 2：

输入：s = "leetcode"
输出："leotcede"
 

## 提示：

1 <= s.length <= 3 * 105
s 由 可打印的 ASCII 字符组成

## 代码：
class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        int start = 0;
        int end = len-1;
        for(start=0;start!=end;start++){
            if(s[start]!='a' && s[start]!='e' && s[start]!='i' && s[start]!='o' && s[start]!='u' && s[start]!='A' && s[start]!='E' && s[start]!='I' && s[start]!='O' && s[start]!='U'){
                continue;
            }
            else
            {
                while(end!=start)
                {
                    if(s[end]!='a' && s[end]!='e' && s[end]!='i' && s[end]!='o' && s[end]!='u' && s[end]!='A' && s[end]!='E' && s[end]!='I' && s[end]!='O' && s[end]!='U'){
                        end--;
                        continue;
                    }
                    else
                    {
                        char temp = s[end];
                        s[end] = s[start];
                        s[start]=temp;
                        end--;
                        break;
                    }
                }
            }
            if(start==end)
            {
                break;
            }
        }
        return s;
    }
};

## 做法：
对这个字符串进行双指针遍历，一个从前往后，一个从后往前。当两个指针都指到了原因，则互换他们。当这两个指针指到同一位置就结束。

## 时间复杂度：
看代码似乎是两层遍历。但实际上只遍历了一次，时间复杂度是O(n)。