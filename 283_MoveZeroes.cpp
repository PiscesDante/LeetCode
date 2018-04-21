// 给定一个数组 nums, 编写一个函数将所有 0 移动到它的末尾，同时保持非零元素的相对顺序。
// 例如， 定义 nums = [0, 1, 0, 3, 12]，调用函数之后， nums 应为 [1, 3, 12, 0, 0]。

// 注意事项:
// 1.必须在原数组上操作，不要为一个新数组分配额外空间。
// 2.尽量减少操作总数。

// ================================================================================

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        for (int i = len - 1; i >= 0; --i) {
            if (nums[i] == 0) {
                int j = i;
                while (nums[j] != nums[j + 1] && (j + 1) < len) {
                    std::swap(nums[j], nums[j + 1]);
                    ++j;
                }
            }
        }
    }
};

// 执行用时：24 ms
// 已经战胜 19.41 % 的 cpp 提交记录

// 执行用时为 12 ms 的范例
// ================================================================================

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int a = 0;
        for (int i = 0; i < len; i++){
            if (nums[i] != 0) {
                nums[a] = nums[i];
                a++;
            }
        }
        for(int i=a; i<len; i++){
            nums[i]=0;
        }
    }
};