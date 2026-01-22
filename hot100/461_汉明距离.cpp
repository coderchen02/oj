// 2026.1.22 13点17分
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s=x^y,cnt=0;
        while(s){
            if(s%2==1) cnt++;
            s/=2;
        }
        return cnt;
    }
};