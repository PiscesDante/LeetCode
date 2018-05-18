/*
 * 解题思路：
 * 遍历两个数组，找出相等的元素并且将下标和记录在一个vector中
 * 然后按条件将pair中的元素返回即可
 */

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int len1 = list1.size();
        int len2 = list2.size();
        vector<pair<string, int>> cache;
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                if (list1[i] == list2[j]) {
                    if (cache.empty()) {
                        // 如果数组为空，则直接push
                        cache.push_back(make_pair(list1[i], i + j));
                    } else if (i + j == cache.begin()->second) {
                        // 如果当前的下标和和数组内的一样，则直接添加
                        cache.push_back(make_pair(list1[i], i + j));
                    } else if (i + j < cache.begin()->second) {
                        // 如果当前的下标和小于数组内已有的元素，则清空数组存进当前的元素
                        cache.clear();
                        cache.push_back(make_pair(list1[i], i + j));
                    }
                }
            }
        }
        vector<string> res;
        for (auto elem : cache) res.push_back(elem.first);
        return res;
    }
};

// 执行用时：132 ms
// 已经战胜 18.87 % 的 cpp 提交记录