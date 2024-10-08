//revise
//Approach 1:
// count number of opening and closing brackets whose adjacent does not form a closing bracket
//answer will (count+1)/2
class Solution {
public:
    int minSwaps(string s) {
        int count=0,n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()=='[' && s[i]==']'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        count= st.size()/2;
        return (count+1)/2;
    }
};



//Approach 2: Just count the number of opening brackets, no need to count closing brackets.
class Solution {
public:
    int minSwaps(string s) {
        int count=0,n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]==']'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return (st.size()+1)/2;
    }
};



//Approach 3: Just count number of opening bracket without stack.
class Solution {
public:
    int minSwaps(string s) {
        int count=0,n=s.length();
        for(int i=0;i<n;i++){
            if(count && s[i]==']'){
                count--;
            }else{
                count++;
            }
        }
        return (count+1)/2;
    }
};