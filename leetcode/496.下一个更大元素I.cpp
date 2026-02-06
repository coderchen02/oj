class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res(nums1.size(),-1);
        stack<int>st;

        unordered_map<int,int> umap;//key 下标元素 value 下标
        for(int i=0;i<nums1.size();i++)
            umap[nums1[i]]=i;
        st.push(0);
        for(int i=1;i<nums2.size();i++){
            while(!st.empty()&&nums2[i]>nums2[st.top()]){
                if(umap.count(nums2[st.top()])>0){//看map里面是否有这个元素
                    int index=umap[nums2[st.top()]];
                    res[index]=nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};