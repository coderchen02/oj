//3.17 20点48分
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 平方最大值肯定在数组两边
        vector<int> result(nums.size(), 0);
        int index = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                result[index--] = nums[i] * nums[i];
                i++;
            } else {
                result[index--] = nums[j] * nums[j];
                j--;
            }
        }

        return result;
    }
};