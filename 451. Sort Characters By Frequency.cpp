#include <algorithm>
#include <map>
#include <string>

class Solution {
public:
    
    string frequencySort(string s) {
        for (char letter : s) {
            if (store.find(letter) == store.end()){
                store.insert(pair<char, int>(letter, 1));
            } else {
                store[letter] += 1;
            }
        }
        while (!store.empty()) {
            char max_char = 'a';
            int max_time = 0;
            for (auto elem : store) {
                if (elem.second > max_time) {
                    max_time = elem.second;
                    max_char = elem.first;
                }
            }
            for (int i = 0; i < store[max_char]; ++i) res += max_char;
            store.erase(max_char);
        }
        return res;
    }
    
private:
    map<char, int> store;
    string res;
};

// 执行用时：16 ms
// 已经战胜 85.71 % 的 cpp 提交记录