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
    void merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [=](const Interval& lhs, const Interval& rhs) {
                return lhs.start < rhs.start;
            }
        );
        int len = intervals.size();
        int temp_start = intervals[0].start;
        int temp_end = intervals[0].end;
        for (int i = 1; i < len; ++i) {
            if (intervals[i].start > temp_end) {
                ret.push_back(Interval(temp_start, temp_end));
                temp_start = intervals[i].start;
                temp_end = intervals[i].end;
            } else {
                if (intervals[i].start <= temp_end) {
                    if (intervals[i].end > temp_end) {
                        temp_end = intervals[i].end;
                    }
                }
            }
        }
        ret.push_back(Interval(temp_start, temp_end));
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        merge(intervals);
        return ret;
    }

private:
    vector<Interval> ret;
};

// 执行用时：28 ms
// 已经战胜 5.98 % 的 cpp 提交记录