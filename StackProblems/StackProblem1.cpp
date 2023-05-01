#include "Stack.cpp"

template <class T>
void infix_to_postfix(string &infix)
{
    // remove pran
    string newString = "";
    AStack<char> stack;

    int strSize = infix.length();
    string tempStr = "";

    for (int i = 0; i < strSize; i++)
    {
        if (infix[i] == '+' or infix[i] == '-')
        {
            // if empty
            if(stack.isEmpty())
                stack.push(infix[i]);

            // if high or same
            else if (stack.top() == '*' || stack.top() == '/' || stack.top() == '+' || stack.top() == '-')
            {
                // if there is element or two want to be poped.
                tempStr += stack.pop();
                if (!stack.isEmpty() || stack.top() != ')')
                    tempStr += stack.pop();
                stack.push(infix[i]);
            }
            // if open parenthsis
            else if (stack.top() == '(')
                stack.push(infix[i]);
        }
        else if (infix[i] == '*' || infix[i] == '/')
        {
            // if empty
            if(stack.isEmpty())
                stack.push(infix[i]);
            // if low
            if (stack.top() == '+' || stack.top() == '-')
                stack.push(infix[i]);
            
            // If Same
            else if(stack.top() == '*' || stack.top() == '/'){
                tempStr += stack.pop();
                if (!stack.isEmpty() || stack.top() != ')')
                    tempStr += stack.pop();
                stack.push(infix[i]);
            }
            // if open parenthsis
            else if(stack.top() == '(')
                stack.push(infix[i]);
        }else if(infix[i] == ')'){
            if(stack.isEmpty()){
                // do nothing
            }else if(stack.top() == '*' || stack.top() == '/'){
                tempStr+=stack.pop();
                if(stack.top() == '+' || stack.top() == '-')
                    tempStr+=stack.pop();
            }
            
        }else{
            tempStr+= infix[i];
        }

    }
    infix = tempStr;
}

int main()
{
    string infix1 = "(2+3)*4";
    infix_to_postfix<char>(infix1);
    cout << "infix1: " << infix1 << endl;
    
    string infix2 = "5+2*3";
    infix_to_postfix<char>(infix2);
    cout << "infix2: " << infix2 << endl;
    
    string infix3 = "(3+4)*(5-2)";
    infix_to_postfix<char>(infix3);
    cout << "infix3: " << infix3 << endl;
    
    string infix4 = "6+3*5/2-4";
    infix_to_postfix<char>(infix4);
    cout << "infix4: " << infix4 << endl;
    
    string infix5 = "(1+2)*(3+4)/(5+6)";
    infix_to_postfix<char>(infix5);
    cout << "infix5: " << infix5 << endl;
    
}