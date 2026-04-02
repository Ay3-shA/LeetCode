#include<iostream>
#include<stack>
using namespace std;

class solution{
    public:

    bool isValid(string str){
        stack<char> st;

        for (int i=0; i<str.size(); i++){
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){//opening
                st.push(str[i]);
            }
            else{//closing
                if(st.size()==0){
                    return false;
                }

                if ((st.top() == '(') && (str[i] == ')') || 
                (st.top() == '{') && (str[i] == '}') || 
                (st.top() == '[') && (str[i] == ']')){
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};

int main(){
    
    solution s;

    string str = "{[()]}";
    
    if(s.isValid(str)){
        cout << "Valid parentheses" << endl;
    } else {
        cout << "Invalid parentheses" << endl;
    }
    return 0;
}