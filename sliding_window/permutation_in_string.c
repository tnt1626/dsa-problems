// -----------------------------------------------------------------------------
// Problem: Permutation in String
// Source : https://leetcode.com/problems/permutation-in-string/
// Author : Ngoc-Tien To
// -----------------------------------------------------------------------------

// ---------------------------------- DESCRIPTION -------------------------------------
//
// Given two strings s1 and s2, return true if s2 contains a permutation of s1,
// or false otherwise.
// In other words, return true if one of s1's permutations is a substring of s2.
//
// Example:
//   Input:  s1 = "ab", s2 = "eidbaooo"
//   Output: true
//   Explanation: s2 contains "ba" which is a permutation of "ab".
//
// ----------------------------------------------------------------------------------


// ---------------------------------- IDEA -------------------------------------
//
// 1. Use the Sliding Window technique over s2 with window size = len(s1).
// 2. Keep a frequency count of each character (26 lowercase English letters).
// 3. Subtract frequencies when extending the window (right pointer).
// 4. Add back frequencies when moving the left pointer after exceeding window size.
// 5. If at any point all counts are zero → found a permutation → return true.
//
//  Time Complexity  : O(26 * n) ≈ O(n)
//  Space Complexity : O(1)  (since alphabet size is fixed: 26)
//
// -----------------------------------------------------------------------------


bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // 1. If s1 is longer than s2, impossible to have permutation
    if (len1 > len2) {
        return false;
    }

    int *count = (int *)calloc(26, sizeof(int));

    // 2. Count frequency of each char in s1
    for (int i = 0; i < len1; i++) {
        count[s1[i] - 'a']++;
    }

    // 3. Sliding window over s2
    for (int i = 0; i < len2; i++) {
        // 3.1 Include current character (right pointer)
        count[s2[i] - 'a']--;

        // 3.2 Remove leftmost character if window exceeds len1
        if (i >= len1) {
            count[s2[i - len1] - 'a']++;
        }

        // 3.3 Check if all counts are zero → valid permutation
        int j;
        for (j = 0; j < 26; j++) {
            if (count[j] != 0) break;
        }

        if (j == 26) {
            free(count);
            return true;
        }
    }

    free(count);
    return false;
}
