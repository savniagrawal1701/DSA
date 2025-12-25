//Operands: If the character is an operand (A, B, 1, 2), append it directly to the result (postfix expression).
//Opening Parenthesis (: Push it onto the operator stack.
//Closing Parenthesis ): Pop operators from the stack and append to the result until an opening parenthesis ( is found. Pop (discard) the (.
//Operators (+, -, *, /, ^):
//While the stack is not empty, the top isn't (, and the operator at the stack's top has higher or equal precedence than the current operator: Pop from stack to result.
//Push the current operator onto the stack
//End of Expression: Pop any remaining operators from the stack to the result. 
#include<bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')  // Exponent operator has highest precedence
        return 3;
    else if (c == '/' || c == '*')  // Multiplication and division have higher precedence than addition
        return 2;
    else if (c == '+' || c == '-')  // Addition and subtraction have lowest precedence
        return 1;
    else
        return -1;
}

// The main function to convert infix expression to postfix expression
void infixToPostfix(string s) {
    stack<char> st; 
    string result;  

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');

  
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();  
        }

        else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);  
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << result << endl;  
}

int main() {
    string exp = "(p+q)*(m-n)"; 
    cout << "Infix expression: " << exp << endl;
    infixToPostfix(exp); 
    return 0;
}
