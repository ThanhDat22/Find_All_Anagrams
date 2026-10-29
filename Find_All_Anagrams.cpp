#include "Algorithms.h"
#include <iostream>

using namespace std;

int main() {

    // Test cases
    struct TestCase {
        string s;
        string p;
        vector<int> expected;
    };

    vector<TestCase> tests = {
        {"cbaebabacd", "abc", {0, 6}},
        {"abab", "ab", {0, 1, 2}},
        {"abcdef", "xyz", {}},
        {"abc", "abcd", {}},
        {"abc", "abc", {0}},
        {"cba", "abc", {0}},
        {"aaaaa", "aa", {0, 1, 2, 3}},
        {"aabbab", "aab", {0}},
        {"abcdef", "f", {5}},
        {"abc", "", {}},
        {"", "abc", {}},
        {"", "", {}}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        vector<int> actual =
            find_anagrams_sliding_window(tests[i].s, tests[i].p);

        if (actual == tests[i].expected) {
            cout << "Test " << i + 1 << ":" << tests.at(i).s << ", " << tests.at(i).p << " => PASSED\n";
        } else {
            cout << "Test " << i + 1 << ": FAILED\n";
        }
    }

    // Prompt the user for input
    string s;
    string p;

    cout << "Enter the string s: ";
    getline(cin, s); // Read the input string s from the user
    cout << "Enter the string p shorter than s: ";
    getline(cin, p); // Read the input string p from the user

    vector<int> anagram_indices = find_anagrams_sliding_window(s, p); // Find all anagrams of p in s
    print_vector(anagram_indices); // Print the resulting indices

    return 0;
}