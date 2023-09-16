class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (int pile : piles) {
            high = max(high, pile);
        }
        int k = high;
        while (low < high) {
            int speed = (high - low) / 2 + low;
            long time = getTime(piles, speed);
            if (time <= h) {
                k = speed;
                high = speed;
            } else {
                low = speed + 1;
            }
        }
        return k;
    }

    long getTime(const vector<int>& piles, int speed) {
        long time = 0;
        for (int pile : piles) {
            int curTime = (pile + speed - 1) / speed;
            time += curTime;
        }
        return time;
    }
};

