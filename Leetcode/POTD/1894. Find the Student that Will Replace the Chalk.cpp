//done by myself

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long> chalk1;
        chalk1.push_back(chalk[0]);
        for(int i=1;i<n;i++){
            chalk1.push_back(chalk[i]+chalk1[i-1]);
        }
        k%=chalk1[n-1];
        if(chalk[0]>k)  return 0;
        else if(chalk[0]==k)  return 1;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(chalk1[mid]==k)
                return mid+1;
            else if(chalk1[mid]<k)
                l=mid+1;
            else
                r=mid-1;
        }
        return r+1;
    }
};