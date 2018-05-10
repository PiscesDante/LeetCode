class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        if (slen != tlen) return false;

        for (int i = 0; i < slen; ++i) {
            auto siter = s2t.find(s[i]);
            auto titer = t2s.find(t[i]);
            if (siter == s2t.end() && titer != t2s.end()) return false;
            if (siter != s2t.end() && titer == t2s.end()) return false;
            if (siter == s2t.end() && titer == t2s.end()) {
                s2t.insert(pair<char, char>(s[i], t[i]));
                t2s.insert(pair<char, char>(t[i], s[i]));
            }
            if (siter != s2t.end() && titer != t2s.end()) {
                if (siter->second != t[i] || titer->second != s[i]) return false;
            }
        }
        return true;
    }
    
private:
    map<char, char> s2t;
    map<char, char> t2s;
};

// 执行用时：8 ms
// 已经战胜 77.68 % 的 cpp 提交记录