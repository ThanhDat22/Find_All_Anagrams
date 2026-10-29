#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/** Prints the elements of a vector.
    @param vec: The vector to print.
 */
void print_vector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec.at(i); // Print each element of the vector
        if (i != vec.size() - 1) {
            cout << ", "; // Add a comma and space between elements
        }
    }
    cout << "]" << endl << endl;;
}

/** Finds all anagrams of a given string in another string using a brute force approach.
    @param s: The string to search for anagrams in.
    @param p: The string to find anagrams of.
    @return: A vector containing the starting indices of all anagrams of p in s.
 */
vector<int> find_anagrams_brute_force(const string& s, const string& p) {
    vector<int> result;
    size_t s_length = s.size();
    size_t p_length = p.size();

    if (s_length < p_length) {
        return result; // If s is shorter than p, return an empty result
    }

    string sorted_p = p; // Create a copy of p to sort
    sort(sorted_p.begin(), sorted_p.end()); // Sort the characters of p
    cout << "s: " << s << endl; // Debug: Print the original string s
    cout << "p: " << p << endl; // Debug: Print the original string p
    cout << "Sorted p: " << sorted_p << endl; // Debug: Print the sorted version of p
    for (size_t i = 0; i <= s_length - p_length; ++i) {
        cout << "Index: " << i << endl; // Debug: Print the current index being checked
        string substring = s.substr(i, p_length); // Get the substring of s
        cout << "Checking substring: " << substring << endl; // Debug: Print the current substring being checked
        string sorted_substring = substring; // Create a copy of the substring to sort
        sort(sorted_substring.begin(), sorted_substring.end()); // Sort the characters of the substring
        cout << "Sorted substring: " << sorted_substring << endl; // Debug: Print the substring after sorting
        if (sorted_substring == sorted_p) { // Compare sorted substring with sorted p
            result.push_back(i); // If they match, add the starting index to the result
            cout << "Anagram found at index: " << i << endl; // Debug: Print the index where an anagram is found
        }
    }
    return result;
} // Time Complexity: O(n * m log m), where n is the length of s and m is the length of p.
  // Space Complexity: O(m) for storing the sorted version of p and the substring.

/** Creates a feature vector for a given string.
    @param str: The string to create a feature vector for.
    @param length: The length of the string to consider.
    @return: A vector representing the count of each character in the string.
 */
vector<int> create_feature_vector(const string& str, size_t length) {
    vector<int> feature_vector(26, 0); // Initialize a vector inluding 26 zeros for each letter.
    for (size_t i = 0; i < length; ++i) {
        feature_vector.at(str.at(i) - 'a')++; // Increment the count for the character in the feature vector
    }
    return feature_vector;
} // Time Complexity: O(n), Space Complexity: O(1).

/** Finds all anagrams of a given string in another string using the sliding window technique.
    @param s: The string to search for anagrams in.
    @param p: The string to find anagrams of.
    @return: A vector containing the starting indices of all anagrams of p in s.
 */
vector<int> find_anagrams_sliding_window(const string& s, const string& p) {
    vector<int> result;
    size_t s_length = s.size();
    size_t p_length = p.size();

    if (p.empty() ||s_length < p_length) {
        return result; // If s is shorter than p, return an empty result
    }

    // Implementation for the sliding window approach
    vector<int> feature_vector_p = create_feature_vector(p, p_length); // Create the feature vector for p
    vector<int> current_window = create_feature_vector(s, p_length); // Create the feature vector for the first window of s


    // Compare the counts of the first window
    if (feature_vector_p == current_window) {
        result.push_back(0); // If they match, add index 0 to the result
    }

    // Slide the window to the right
    for (size_t i = p_length; i < s_length; ++i) {
        current_window.at(s.at(i) - 'a')++; // Add the new character to the current window
        current_window.at(s.at(i - p_length) - 'a')--; // Remove the character that is no longer in the window

        if (feature_vector_p == current_window) {
            result.push_back(i - p_length + 1); // If they match, add the starting index of the current window to the result
        }
    }
    return result;
} // Time Complexity: O(n), where n is the length of s.
  // Space Complexity: O(1), since the size of the count arrays is constant (26 letters).

#endif // ALGORITHMS_H