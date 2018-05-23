class Solution {
public:
    void inStack(string& s, int begin, int end) {
        if (begin >= end) return;
        string temp;
        for (int i = begin; i < end; ++i) {
            temp.push_back(s[i]);
        }
        if (!temp.empty()) cache.push(temp);
    }
    
    void reverseWords(string &s) {
        string ret;
        int head = 0;
        int tail = 0;
        int len = s.size();
        while (head < len && tail < len) {
            while (head < len && s[head] == ' ') ++head;
            tail = head;
            while (tail < len && s[tail] != ' ') ++tail;
            // Now : head != ' ' && tail == ' ';
            inStack(s, head, tail);
            head = tail;
        }
        if (!cache.empty()) {
            ret += cache.top();
            cache.pop();
        }
        while (!cache.empty()) {
            ret += " ";
            ret += cache.top();
            cache.pop();
        }
        s = ret;
    }
    
private:
    stack<string> cache;
};

// Runtime: 12 ms
// Your runtime beats 15.25 % of cpp submissions.
// 此题国区的编译器有问题