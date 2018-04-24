/*
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    void func(vector<Employee*> employees, int id) {
        int index = 0;
        for (Employee* target : employees) {
            if (target->id == id) break;
            index++;
        }
        Employee* present = employees[index];
        if (present == nullptr) return;
        sum += present->importance;
        for (int sub_id : present->subordinates) {
            func(employees, sub_id);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        func(employees, id);
        return sum;
    }

private:
    int sum = 0;
};

// 执行用时：32 ms
// 已经战胜 19.28 % 的 cpp 提交记录