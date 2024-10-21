//revise
//done by me
//used two for loop for comparing each digit with it's forwrd digits

class Solution {
public:
    int maximumSwap(int num) {
        string s;
        while(num){
            s= (to_string(num%10))+s;
            num/=10;
        }
        int n=s.length();
        for(int i=0;i<n-1;i++){
            int maxi=i;
            for(int j=i+1;j<n;j++){
                if(s[j]>s[maxi])    maxi=j;
                if(maxi!=i && s[j]==s[maxi])    maxi=j; 
            }
            if(i!=maxi){
                swap(s[i],s[maxi]);
                break;
            }
        }
        return stoi(s);
    }
};