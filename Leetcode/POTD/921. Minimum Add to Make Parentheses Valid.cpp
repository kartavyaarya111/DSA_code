//1st approach Easy

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto&x:s){
            if(!st.empty() && st.top()=='(' && x==')'){
                st.pop();
            }else{
                st.push(x);
            }
        }
        return st.size();
    }
};


//Revise 2nd apprach 
//without stack

class Solution {
public:
    int minAddToMakeValid(string s) {
        int  left=0,right=0;
        for(auto&x:s){
            if(x=='('){
                left++;
            }else{
                if(left)    left--;
                else    right++;
            }
        }
        return left+right;
    }
};