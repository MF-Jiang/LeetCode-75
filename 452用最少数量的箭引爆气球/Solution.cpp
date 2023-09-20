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

