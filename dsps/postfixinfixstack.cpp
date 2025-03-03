/*
Stack : It is linear data structure which stores data sequentially and follows the last in first (LIFO) or FILO Priciple.
>Operations : push() , pop() , isempty() , isfull() , peek()

->declare size variable 
->declare int array
->declare and initialise int top =-1
-> condition for full : top>=size-1       -stack overflow
-> condition for empty : top<0            -stack underflow
->to print the top/peak element : arrayname[top]

Infix Expression : Arithmetic Expression Consisting of Operator In between the operand (A+B)
Postfix Expression :Arithmetic expression in which operator is next to the operand
*/
#include<iostream>
#include<stack>
#include<string>   //include require header files
using namespace std;
int precedence(char c){       //return value as per precedence
    if(c== '^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

bool isOperand(char c){      //return isalnum(c); //can also be use
    if( (c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9') ){
        return true;
    }
    else{
        return false;
    }
}    //return true if it is alphabet/number or not else false

string infixtopostfix(string s){
stack<char> st;          //declare character stack names 'st'
string result;

for(int i=0;i<s.length();i++){        //for 0 to length of s iterate i
    char c=s[i];

    if(isOperand(c)){     //if char c is operand then put into result
        result +=c;
    }
    else if(c == '('){      //if c is open bracket then push into stack
        st.push(c);
    } 
    else if(c== ')'){        //if c is close bracket then apply while loop
        while(!st.empty() && st.top() != '('){       //while stack not empty and stack top not equal to open bracket
            result+= st.top();                     //store stack top in result using +=
            st.pop();                             //and then pop stack
        }
        if(!st.empty()){                 //if only empty then pop stack
            st.pop();
        }
    }
    else{
        while(!st.empty() && precedence(c)<=precedence(st.top())){    //while stack not empty and precedence of c <= precendence of stack top
            result +=st.top();                   //store stack top into result;
            st.pop();             //pop stack
        }
        st.push(c);             //push
    }
    }
while(!st.empty()){
    result += st.top();
    st.pop();
}
return result;
}



int main(){         //declare string variable and call the function passing string
string exp;
cout<<"Enter Infix Expression : ";
getline(cin,exp);
cout<<"Postfix Expression : "<<infixtopostfix(exp)<<endl;

    return 0;
}



/*
my code 

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char c){
    if(c == '^'){
        return 3;
    }
    else if(c=='*' || c== '/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

bool isoperand(char c){
    if( (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
        return true;
    }
    else{
        return false;
    }
}

string infixtopostfix(string s){
    stack<char> st;
    string result;
    
    for(int i=0;i<s.length();i++){
        char c =s[i];
        
        if(isoperand(c)){
            result+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() && st.top()!='('){
                result+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && precedence(c)<=precedence(st.top())){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
      return result;
}

int main(){
    string exp;
    cout<<"Enter Infix Expression : ";
    getline(cin,exp);
    cout<<"Postfix Expression : "<<infixtopostfix(exp);
    return 0;
}
*/