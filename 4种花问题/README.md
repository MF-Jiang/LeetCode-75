# 种花问题
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。

 

## 示例 1：

输入：flowerbed = [1,0,0,0,1], n = 1
输出：true

## 示例 2：

输入：flowerbed = [1,0,0,0,1], n = 2
输出：false
 

## 提示：

1 <= flowerbed.length <= 2 * 104
flowerbed[i] 为 0 或 1
flowerbed 中不存在相邻的两朵花
0 <= n <= flowerbed.length

## 我的代码：
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size()==1)
        {
            return (flowerbed[0]==0 && n<=1) || (flowerbed[0]==1 && n==0);
        }

        int couldPlace = 0;
        for(int i=0; i<flowerbed.size(); i++)
        {
            if(i==0 && flowerbed[i]!=1)
            {
                if(flowerbed[i+1]==0){
                    couldPlace++;
                    flowerbed[i]=1;
                    i++;
                }
                continue;
            }
            if(i==flowerbed.size()-1 && flowerbed[i]!=1)
            {
                if(flowerbed[i-1]==0)
                {
                    couldPlace++;
                    flowerbed[i]=1;
                    i++;
                }
                continue;
            }
            if(flowerbed[i]!=1 && flowerbed[i-1]!=1 && flowerbed[i+1]!=1)
            {
                couldPlace++;
                flowerbed[i]=1;
                i++;
            }

        }
        if (couldPlace>=n){return true;}
        else return false;
    }
};

## 我的做法：
傻瓜遍历法，从左到右遍历一遍每一次都确定右边一项没有1即可。(上面代码写的是左右两边都没有1，可以简化，会在时间和内存上有更好的表现)，需要注意数组长度为1的情况。

## 时间复杂度
遍历了一次数组，时间复杂度为O(n),每次遍历到一个能种花的位置后自动往后多跳了以为，实际遍历长度是小于等于数组长度的，这里做了一点优化。

## 标答代码：
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 1) {
                if (prev < 0) {
                    count += i / 2;
                } else {
                    count += (i - prev - 2) / 2;
                }
                if (count >= n) {
                    return true;
                }
                prev = i;
            }
        }
        if (prev < 0) {
            count += (m + 1) / 2;
        } else {
            count += (m - prev - 1) / 2;
        }
        return count >= n;
    }
};


## 时间复杂度
O(n)，运行表现略好于我的代码。
https://leetcode.cn/problems/can-place-flowers/solutions/542556/chong-hua-wen-ti-by-leetcode-solution-sojr/?envType=study-plan-v2&envId=leetcode-75


