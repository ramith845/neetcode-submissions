// Local test driver. The build tasks #include the selected submission-N.cpp before this file,
// so `DynamicArray` is already in scope (std headers come from .vscode/neetcode.h).
#ifdef __INTELLISENSE__
#include "submission-1.cpp"
#endif

using Token = variant<string, int>;

int main() {
    // The NeetCode test case, with [] swapped for {}. A method's arguments follow its name.
    vector<Token> ops = {
        "Array", 1, "getSize", "getCapacity",
        "pushback", 1, "pushback", 2, "pushback", 3, "pushback", 4, "pushback", 5,
        "pushback", 6, "pushback", 7, "pushback", 8, "pushback", 9,
        "getSize", "getCapacity",
        "popback", "popback", "popback", "popback", "popback",
        "popback", "popback", "popback", "popback",
        "getSize", "getCapacity"};

    // One entry per call, including the constructor.
    vector<string> expected = {
        "null", "0", "1",
        "null", "null", "null", "null", "null", "null", "null", "null", "null",
        "9", "16",
        "9", "8", "7", "6", "5", "4", "3", "2", "1",
        "0", "16"};

    unique_ptr<DynamicArray> arr;
    vector<string> output;
    size_t pos = 0;
    int failed = 0;

    auto nextArg = [&] { return get<int>(ops.at(pos++)); };

    while (pos < ops.size()) {
        const string op = get<string>(ops[pos++]);
        string call = op + "()";
        string result = "null";

        if (op == "Array") {
            int capacity = nextArg();
            call = op + "(" + to_string(capacity) + ")";
            arr = make_unique<DynamicArray>(capacity);
        } else if (op == "get") {
            int i = nextArg();
            call = op + "(" + to_string(i) + ")";
            result = to_string(arr->get(i));
        } else if (op == "set") {
            int i = nextArg();
            int n = nextArg();
            call = op + "(" + to_string(i) + ", " + to_string(n) + ")";
            arr->set(i, n);
        } else if (op == "pushback") {
            int n = nextArg();
            call = op + "(" + to_string(n) + ")";
            arr->pushback(n);
        } else if (op == "popback") {
            result = to_string(arr->popback());
        } else if (op == "resize") {
            arr->resize();
        } else if (op == "getSize") {
            result = to_string(arr->getSize());
        } else if (op == "getCapacity") {
            result = to_string(arr->getCapacity());
        } else {
            cout << "unknown operation: " << op << '\n';
            return 1;
        }

        const size_t step = output.size();
        const string want = step < expected.size() ? expected[step] : "?";
        const bool ok = result == want;
        failed += !ok;
        output.push_back(result);

        cout << (ok ? "PASS  " : "FAIL  ") << call << " -> " << result;
        if (!ok) cout << " (expected " << want << ")";
        cout << '\n';
    }

    cout << "\noutput:   " << output << '\n'
         << "expected: " << expected << '\n';

    if (failed == 0 && output.size() == expected.size())
        cout << "ALL PASSED\n";
    else
        cout << failed << " step(s) failed\n";
}
