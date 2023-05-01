#include "Stack.cpp"

template<class T>
int LongestValidParenthsis(string& str){
    AStack<char> stack;
    int strSize = str.length();
    int validParenthsis = 0;
    for(int i = 0; i < strSize; i++){
        if(str[i] == '('){
            stack.push(str[i]);
        }else if(str[i] == ')'){
            if(stack.top() == '('){
                stack.pop();
                validParenthsis+= 2;
            }else if(!stack.isEmpty()){
                stack.pop();
            }else{
                continue;
            }
        }
    }
    return validParenthsis;
}

int main(){
    // ‘)()())’
    string test1 = ")()())";
    cout << test1 << ": "<< LongestValidParenthsis<char>(test1) << endl;;

    string test2 = "',";
    cout << test2 << ": "<< LongestValidParenthsis<char>(test2) << endl;;

    string test3 = "(()";
    cout << test3 << ": "<< LongestValidParenthsis<char>(test3) << endl;;
    
    string test4 = "((()))";
    cout << test4 << ": "<< LongestValidParenthsis<char>(test4) << endl;;
    
    string test5 = "(()()(()))";
    cout << test5 << ": "<< LongestValidParenthsis<char>(test5) << endl;;
}