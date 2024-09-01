//Weekly contest 1/9/24
//no need of revision

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int st = 0, st1=0;
        int c1x = coordinate1[0]-'a';
        if(c1x%2)   st=1;
        int c1y = coordinate1[1]-'0';
        if(!(c1y%2))    st = st==1?0:1;
        // cout<<c1x<<" "<<c1y<<" "<<st;

        c1x = coordinate2[0]-'a';
        if(c1x%2)   st1=1;
        c1y = coordinate2[1]-'0';
        if(!(c1y%2))    st1 = st1==1?0:1;
        // cout<<endl<<c1x<<" "<<c1y<<" "<<st1;
        if(st == st1)   return true;
        return false;
    }
};