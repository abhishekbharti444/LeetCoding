class Solution {
public:
    
    int evaluate(int first, int second, char oper) {
        if (oper == '+') return first + second;
        if (oper == '-') return first - second;
        if (oper == '*') return first * second;
        if (oper == '/') return first / second;
        return -1;
    }
    
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(evaluate(first, second, tokens[i][0]));
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};