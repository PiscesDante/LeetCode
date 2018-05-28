/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return ret;
        sort(intervals.begin(), intervals.end(),
            [=](const Interval& lhs, const Interval& rhs) {
                return lhs.start < rhs.start;
            }
        );
        int len = intervals.size();
        int new_start = intervals[0].start;
        int new_end = intervals[0].end;
        for (int i = 1; i < len; ++i) {
            if (intervals[i].start > new_end) {
                ret.push_back(Interval(new_start, new_end));
                new_start = intervals[i].start;
                new_end = intervals[i].end;
            } else {
                if (intervals[i].end > new_end) {
                    new_end = intervals[i].end;
                }
            }
        }
        ret.push_back(Interval(new_start, new_end));
        return ret;
    }

private:
    vector<Interval> ret;
};

// 执行用时：12 ms
// 已经战胜 97.64 % 的 cpp 提交记录