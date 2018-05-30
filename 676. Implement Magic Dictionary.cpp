class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() = default;
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string word : dict) {
            container.push_back(word);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        bool res = false;
        for (string local_word : container) {
            if (word.size() == local_word.size()) {
                int defferent_count = 0;
                int len = word.size();
                for (int i = 0; i < len; ++i) {
                    if (word[i] != local_word[i]) defferent_count += 1;
                }
                if (defferent_count == 1) res = true;
            }
        }
        return res;
    }

private:
    vector<string> container;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

// 执行用时：8 ms
// 已经战胜 9.09 % 的 cpp 提交记录