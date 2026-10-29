# Find all Anagrams in a String

- An anagram is a rearrangement of the characters of a string. Two string are anagrams if they contain the same characters with the same frequencies, regardless of their order.
- Give two string s and p, find all the starting indices of substring sin s that are anagrams of p.
- The result should be an array containing all valid starting indices.

## Example 1

```text
Input: s = "cbaebabacd", p = "abc" 
Output: [0, 6]
```

Explanation:

- at index 0, the substring "cba" is an anagram of "abc"
- at index 6, the substring "bac" is an anagram of "abc"

## Example 2

```text
Input: s = "abab", p = "ab" 
Output: [0, 1, 2]
```

Explanation:

- at index 0, the substring "ab" is an anagram of "ab"
- at index 1, the substring "ba" is an anagram of "ab"
- at index 2, the substring "ab" is an anagram of "ab"
