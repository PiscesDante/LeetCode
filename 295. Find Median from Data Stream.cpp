class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto iter = cache.begin();
        for (; iter != cache.end(); ++iter) {
            if (num < *iter) {
                cache.insert(iter, num);
                return;
            }
        }
        if (iter == cache.end()) cache.push_back(num);
    }
    
    double findMedian() {
        int len = cache.size();
        if (len % 2) return cache[len / 2];
        else return (cache[len / 2] + cache[len / 2 - 1]) / 2.0;
    }

private:
    vector<int> cache;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

// 执行用时：384 ms
// 已经战胜 3.45 % 的 cpp 提交记录