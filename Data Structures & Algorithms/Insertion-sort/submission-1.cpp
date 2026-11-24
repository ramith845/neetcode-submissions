class Solution {
   public:
    // Sorts nums in ascending order in place.
    void insertionSort(vector<int>& nums) {
        // TODO: implement insertion sort
        for (size_t i = 1; i < nums.size(); i++) {
            int j = i;
            while (j > 0 && nums[j] < nums[j - 1]) {
                std::swap(nums[j], nums[j - 1]);
                j--;
            }
        }
    }
};
