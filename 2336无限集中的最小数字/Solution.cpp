

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

 class SmallestInfiniteSet {
public:
    int minV = 1;
    set<int> s;
    SmallestInfiniteSet() {
    }

    int popSmallest() {
        int res = minV;
        s.insert(minV);
        while (s.count(++minV)) {}
        return res;
    }
    
    void addBack(int num) {
        if (s.count(num)) s.erase(num);
        minV = min(minV, num);
    }
};


