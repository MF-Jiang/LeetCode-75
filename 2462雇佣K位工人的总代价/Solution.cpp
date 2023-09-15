class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> frontq;
        priority_queue<int,vector<int>,greater<int>> backq;
        int n=costs.size();
        for(int i=0;i<candidates;++i) frontq.push(costs[i]);
        for(int i=n-1;i>=n-candidates&&i>=candidates;--i) backq.push(costs[i]);
        int lcursor=candidates,rcursor=n-candidates-1;
        long long sum=0;
        while(k){
            long long lMin=INT_MAX,rMin=INT_MAX;
            if(!frontq.empty())lMin=frontq.top();
            if(!backq.empty()) rMin=backq.top();
            if(lMin<=rMin){
                frontq.pop();
                if(lcursor<=rcursor) frontq.push(costs[lcursor++]);
                sum+=lMin;
            }else{
                backq.pop();
                if(rcursor>=lcursor) backq.push(costs[rcursor--]);
                sum+=rMin;
            } 
            --k;
        }
        return sum;
    }
};
