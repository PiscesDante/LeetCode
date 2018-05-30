/*
 * 解题思路：
 * 首先建立一个数组中的值和下标数组的map
 * 建立完毕之后将每一个元素的下标数组排序，并忽略掉数组长度只有1的元素
 * 如果下标数组中有任何相邻下标的差值小于等于k，那么直接返回true
 * 否则等所有步骤执行完之后返回false
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        for (int k = 0; k < len; ++k) value_indexs[nums[k]].push_back(k);
        for (auto& vipair : value_indexs) {
            int indexs_len = vipair.second.size();
            if (indexs_len == 1) continue;
            sort(vipair.second.begin(), vipair.second.end());
            for (int i = 0; i < indexs_len - 1; ++i) {
                if (vipair.second[i + 1] - vipair.second[i] <= k) return true;
            }
        }
        return false;
    }
    
private:
    map<int, vector<int>> value_indexs;
    
};

// 执行用时：36 ms
// 已经战胜 24.14 % 的 cpp 提交记录