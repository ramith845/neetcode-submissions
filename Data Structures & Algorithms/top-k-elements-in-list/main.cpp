// Local test driver. The build tasks #include the selected submission-N.cpp before this file,
// so `Solution` is already in scope (std headers + ListNode/TreeNode come from .vscode/neetcode.h).
#ifdef __INTELLISENSE__
#include "submission-2.cpp"
#endif
#include <vector>

int main() {
    Solution sol;

    vector<int> nums = {1,2,2,3,3,3};
    auto res = sol.topKFrequent(nums, 2);
    cout << res << '\n';
}
