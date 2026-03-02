// 3.2 21点54分
class Solution {
public:
    int maxArea(vector<int>& height) {
        //双指针从两端开始，因为此时已经是宽度最大，如果还想得到更大的容量，只能依赖于“高度”变高
        int l=0,r=height.size()-1;
        int result=0;
        while(l!=r){
            result=max(result,min(height[l],height[r])*(r-l));
            //每次只移动较小高度的指针
            if(height[l]>height[r]) r--;
            else l++;
        }
        return result;
    }
};