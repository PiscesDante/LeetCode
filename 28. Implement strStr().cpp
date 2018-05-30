class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        if (haystack == needle) return 0;

        int haystack_len = haystack.size();
        int needle_len = needle.size();
        char needle_head = *needle.begin();

        for (int i = 0; i < haystack_len - needle_len + 1; ++i) {
            if (haystack[i] == needle_head) {
                int ret_index = i;
                bool is_match = true;
                for (int j = 0, temp_i = i; j < needle_len; ++j, ++temp_i) {
                    if (needle[j] != haystack[temp_i]) {
                        is_match = false;
                        break;
                    }
                }
                if (is_match) return ret_index;
            }
        }

        return -1;
    }
};

// 执行用时：4 ms
// 已经战胜 100.00 % 的 cpp 提交记录