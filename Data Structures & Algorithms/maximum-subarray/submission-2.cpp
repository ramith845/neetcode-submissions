class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;

        for (auto num : nums) {
            currSum = std::max(0, currSum);
            currSum += num;
            maxSum = std::max(maxSum, currSum);
        }

        return maxSum;
    }
};
