// Local test driver. The build tasks #include the selected submission-N.cpp before this file,
// so `Solution` is already in scope (std headers come from .vscode/neetcode.h).
#include <vector>
// #include "submission-1.cpp"

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {},
        {1},
        {2, 4, 6, 8, 3},
        {5, 4, 3, 2, 1},
        {2, 7, 1, 7, 3, 2},
        {-3, 0, -1, 8, 8, -10},
    };

    for (auto nums : tests) {
        vector<int> expected = nums;
        sort(expected.begin(), expected.end());

        vector<int> input = nums;
        sol.insertionSort(input);

        cout << "input:    " << nums << '\n'
             << "output:   " << input << '\n'
             << "expected: " << expected << '\n'
             << (input == expected ? "PASS" : "FAIL") << "\n\n";
    }
}
