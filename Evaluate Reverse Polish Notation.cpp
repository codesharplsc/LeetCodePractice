class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int oper1, oper2;
        stack<int> myStack;
        
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                oper1 = myStack.top();
                myStack.pop();
                oper2 = myStack.top();
                myStack.pop();
                myStack.push(oper1 + oper2);
                continue;
            }
                
            if (tokens[i] == "-") {
                oper1 = myStack.top();
                myStack.pop();
                oper2 = myStack.top();
                myStack.pop();
                myStack.push(oper2 - oper1);
                continue;
            }
            if (tokens[i] == "/") {
                oper1 = myStack.top();
                myStack.pop();
                oper2 = myStack.top();
                myStack.pop();
                myStack.push(oper2 / oper1);
                continue;
            }
            if (tokens[i] == "*"){
                oper1 = myStack.top();
                myStack.pop();
                oper2 = myStack.top();
                myStack.pop();
                myStack.push(oper2 * oper1);
                continue;
            }
            
            myStack.push(stoi(tokens[i]));
        }
        
        return myStack.top();
        
    }
};