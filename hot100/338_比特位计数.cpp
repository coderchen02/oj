// 2026.1.22 14点31分
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> nums;
        for(int i=0;i<=n;i++){//n+1次循环
            //计算二进制1的个数
            int tmp=i;
            int cnt=0;
            while(tmp){
                if(tmp%2==1) cnt++;
                tmp/=2;
            }
            nums.push_back(cnt);
        }
        return nums;
    }
};