class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        if (s.size() == 0) return true;

        map<char, char> relation = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
            else {
                if (stk.empty()) return false;
                if (relation[stk.top()] != s[i]) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
