#include <map>

class Solution {
public:
    void init() {
        store.insert(pair<char, int>('I', 1));
        store.insert(pair<char, int>('V', 5));
        store.insert(pair<char, int>('X', 10));
        store.insert(pair<char, int>('L', 50));
        store.insert(pair<char, int>('C', 100));
        store.insert(pair<char, int>('D', 500));
        store.insert(pair<char, int>('M', 1000));
    }

    int romanToInt(string s) {
        init();
        int len = s.size();
        int sum = store.at(s[len - 1]);
        int curr = len - 1;
        int next = len - 2;
        while (next >= 0) {
            if (store.at(s[next]) >= store.at(s[curr])) sum += store.at(s[next]);
            else sum -= store.at(s[next]);
            curr -= 1;
            next -= 1;
        }
        return sum;
    }
    
private:
    map<char, int> store;
};

// 执行用时：96 ms
// 已经战胜 32.06 % 的 cpp 提交记录