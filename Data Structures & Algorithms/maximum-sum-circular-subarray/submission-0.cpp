#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    // Maximum sum of a non-empty circular subarray.
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int num : nums) {
            total += num;

            curMax = std::max(curMax, 0) + num;
            maxSum = std::max(maxSum, curMax);

            curMin = std::min(curMin, 0) + num;
            minSum = std::min(minSum, curMin);
        }

        if (maxSum > 0) total -= minSum;

        return std::max(maxSum, total);
    }
};
