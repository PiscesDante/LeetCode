// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // if (isBadVersion(1)) return 1;
        // if (isBadVersion(n) && !isBadVersion(n - 1)) return n;
        int head = 1;
        int tail = n;
        while (head <= tail) {
            int mid = head + (tail - head) / 2;
            if (isBadVersion(mid)) {
                if (!isBadVersion(mid - 1)) return mid;
                else tail = mid - 1;
            } else {
                head = mid + 1;
            }
        }
        if (isBadVersion(head) && !isBadVersion(tail)) return head;
        else return tail;
    }
};

// 执行用时：12 ms
// 已经战胜 9.20 % 的 cpp 提交记录