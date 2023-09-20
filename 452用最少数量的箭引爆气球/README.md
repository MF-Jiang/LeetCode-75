# 452. 用最少数量的箭引爆气球

有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

 
## 示例 1：

输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：气球可以用2支箭来爆破:
-在x = 6处射出箭，击破气球[2,8]和[1,6]。
-在x = 11处发射箭，击破气球[10,16]和[7,12]。
## 示例 2：

输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
解释：每个气球需要射出一支箭，总共需要4支箭。
## 示例 3：

输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2
解释：气球可以用2支箭来爆破:
- 在x = 2处发射箭，击破气球[1,2]和[2,3]。
- 在x = 4处射出箭，击破气球[3,4]和[4,5]。
 

## 提示:

1 <= points.length <= 105
points[i].length == 2
-231 <= xstart < xend <= 231 - 1

## 代码：
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==1){
            return 1;
        }
        sort(points.begin(),points.end(),[](const auto& a,const auto& b){
            return a[0]<b[0];
        });

        int i=0;
        int j=1;
        int cnt=1;
        while(j<points.size()){
            //如果当前的[][1]大于从第i项到第j-1项的[][1]，则说明当前的气球与前面的气球无交集
            //左指针移到右指针的位置，同时箭矢数量++
            if(func(points,i,j)<points[j][0]){
                cnt++;
                i=j;
            }
            j++;
        }
        return cnt;
    }

    //函数作用：在points二维数组中，从第i项到第j-1项，获取[][1]的最小值
    int func(vector<vector<int>>& points,int i,int j){
        int MIN=INT_MAX;
        for(int k=i;k<j;k++){
            MIN=min(MIN,points[k][1]);
        }
        return MIN;
    }
};


## 做法：
贪心双指针
## 时间复杂度：
O(n^2)