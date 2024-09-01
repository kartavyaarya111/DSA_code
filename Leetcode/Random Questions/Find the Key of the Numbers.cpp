//Biweekly contest 31/8/24
//Easy question

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int n=4,ans=0,p=1000;
        while(n--){
            int z=min({num1/p, num2/p, num3/p});
            num1%=p;
            num2%=p;
            num3%=p;
            ans=(ans*10) + z;
            p/=10;
        }
        return ans;
    }
};