// 3.4 19点26分
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> height(n);
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            result=max(result,maxArea(height));
        }
        return result;
    }
    int maxArea(vector<int>& heights){
        int n=heights.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            //右边界
            while(!st.empty()&&heights[i]<heights[st.top()]){
                int index=st.top();
                st.pop();
                right[index]=i;
            }
            //左边界
            if(!st.empty()){//height[i]>height[st.top()]
                left[i]=st.top();
            }
            st.push(i);
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int area=width*heights[i];
            maxarea=max(maxarea,area);
        }
        return maxarea;

    }
};