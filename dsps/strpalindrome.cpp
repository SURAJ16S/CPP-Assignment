/*
Palindrome : when a string is equal to its reverse version ,for ex. nayan = nayan

Stack : It is linear data structure which stores data sequentially and follows the last in first (LIFO) or FILO Priciple.
>Operations : push() , pop() , isempty() , isfull() , peek()

-> declare size variable 
-> declare int array
-> declare and initialise int top =-1
-> condition for full : top>=size-1        -stack overflow
-> condition for empty : top=-1            -stack underflow
-> to print the top/peak element : arrayname[top]

problem statement:A palindrome is a string of characters that is the same forward and backward.Typically, punctuation, capitalization, and spaces are ignored.For example, 
"Poor Dan is in a droop" is a palindrome, as can be seen by examining the characters "poordanisinadroop" and observing that they are the same forward and backward.One way 
to check for a palindrome is to reverse the characters in the string and then compare with the original—in a palindrome, the sequence will be identical.Write a C++ 
program with functions to check whether a given string is a palindrome or not that uses a stack to determine whether a string is a palindrome.
*/

#include<iostream>
using namespace std;

int main(){
 string str,revstr;
 int i=0,top=-1,flag=0;

 cout<<"Enter String : ";
 getline(cin,str);
//store reverse version of 'str' into the 'revstr'
 while(str[i]!='\0'){
    if(str[i]==' ' || str[i]==','){    //to check non alphabet
        i++;            //i for str increment 
        continue;       //to skip the interation
    }
    else{
        top++;
        revstr[top]=str[i];
        i++;                        //dont forget this 
    }
 }
 i=0;         
 //do it zero to start iteration from zero
 //now comparison between str and revstr
 while(str[i]!='\0'){
    if(str[i]==' ' || str[i]==','){    //to check non alphabet
        i++;            //i for str increment 
        continue;       //to skip the interation
    }
    else{
        if(str[i]!=revstr[top]){
            flag=1;
            break;
        }
        top--;          //dont forget it 
        i++;            //dont forget to increment
    }
 }

 if(flag==1){
    cout<<"String Is Not Palindrome"<<endl;
 }
 else{
    cout<<"String Is Palindrome"<<endl;
 }
    return 0;
}

