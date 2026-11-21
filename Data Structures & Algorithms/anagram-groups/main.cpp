// Local test driver. The build tasks #include the selected submission-N.cpp before this file,
// so `Solution` is already in scope (std headers + ListNode/TreeNode come from .vscode/neetcode.h).
int main() {
    Solution sol;

    vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};
    auto res = sol.groupAnagrams(strs);
    cout << res << '\n';
}
