// Local test driver. The build tasks #include the selected submission-N.cpp before this file,
// so `Solution` is already in scope (std headers + ListNode/TreeNode come from .vscode/neetcode.h).

struct TestCase {
    vector<int> nums;
    int k;
    vector<int> expected;  // any order is accepted
};

int main() {
    Solution sol;

    vector<TestCase> tests = {
        {{1, 2, 2, 3, 3, 3}, 2, {2, 3}},
        {{7, 7}, 1, {7}},
        {{5}, 1, {5}},                                     // single element
        {{4, 4, 4, 4, 4}, 1, {4}},                         // all the same
        {{1, 2, 3, 4}, 4, {1, 2, 3, 4}},                   // k == distinct count, all tied
        {{1, 1, 2, 2, 3}, 2, {1, 2}},                      // tie inside the top k
        {{-1, -1, -2, -2, -2, 3}, 2, {-2, -1}},            // negative values
        {{0, 0, 0, 1000, 1000, -1000}, 2, {0, 1000}},      // zero and range limits
        {{9, 8, 9, 7, 8, 9, 6, 7, 8, 9}, 3, {9, 8, 7}},    // unsorted, interleaved
        {{3, 3, 3, 3, 1, 2, 4, 5, 6}, 1, {3}},             // one dominant value
        {{10, 20, 20, 30, 30, 30, 40, 40, 40, 40}, 4, {10, 20, 30, 40}},
    };

    int passed = 0;
    for (const auto& t : tests) {
        vector<int> input = t.nums;
        vector<int> res = sol.topKFrequent(input, t.k);

        vector<int> got = res;
        vector<int> expected = t.expected;
        sort(got.begin(), got.end());
        sort(expected.begin(), expected.end());

        bool ok = got == expected;
        passed += ok;

        cout << "nums:     " << t.nums << ", k = " << t.k << '\n'
             << "output:   " << res << '\n'
             << "expected: " << t.expected << '\n'
             << (ok ? "PASS" : "FAIL") << "\n\n";
    }
    cout << passed << '/' << tests.size() << " passed\n";
}
