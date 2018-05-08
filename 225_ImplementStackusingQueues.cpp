class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() = default;
    
    /** Push element x onto stack. */
    void push(int x) {
        if (queue_one.empty() && !queue_two.empty()) queue_two.push(x);
        else queue_one.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (!queue_one.empty()) {
            while (queue_one.size() > 1) {
                queue_two.push(queue_one.front());
                queue_one.pop();
            }
            int ret = queue_one.front();
            queue_one.pop();
            return ret;
        } else {
            while (queue_two.size() > 1) {
                queue_one.push(queue_two.front());
                queue_two.pop();
            }
            int ret = queue_two.front();
            queue_two.pop();
            return ret;
        }
    }
    
    /** Get the top element. */
    int top() {
        if (queue_one.empty()) return queue_two.back();
        else return queue_one.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue_one.empty() && queue_two.empty();
    }
    
private:
    queue<int> queue_one;
    queue<int> queue_two;
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

// 执行用时：0 ms
// 已经战胜 100.00 % 的 cpp 提交记录