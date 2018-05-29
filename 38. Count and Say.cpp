class Solution {
public:
    string countAndSay(const string& s) {
        string ret;
        int curr_time = 1;
        int curr_char = s[0];
        int len = s.size();
        for (int i = 1; i < len; ++i) {
            if (s[i] == curr_char) {
                ++curr_time;
            } else {
                ret += to_string(curr_time);
                ret.push_back(curr_char);
                curr_char = s[i];
                curr_time = 1;
            }
        }
        ret += to_string(curr_time);
        ret.push_back(curr_char);
        return ret;
    }

    string countAndSay(int n) {
        string ret = "1";
        if (n == 1) return ret;
        for (int i = 1; i < n; ++i) ret = countAndSay(ret);
        return ret;
    }
};

// 执行用时：4 ms
// 已经战胜 73.81 % 的 cpp 提交记录