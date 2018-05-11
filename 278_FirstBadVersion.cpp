// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = n;
        for (; isBadVersion(i); --i);
        return i + 1;
    }
};

// 执行用时：1336 ms