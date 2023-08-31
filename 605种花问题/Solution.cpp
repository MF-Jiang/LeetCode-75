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