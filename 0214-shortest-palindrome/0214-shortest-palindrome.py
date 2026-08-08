class Solution:
    def shortestPalindrome(self, s: str) -> str:
        rev = s[::-1]

        # Find the longest prefix of s that is also a suffix of rev
        combined = s + "#" + rev

        lps = [0] * len(combined)

        for i in range(1, len(combined)):
            j = lps[i - 1]

            while j > 0 and combined[i] != combined[j]:
                j = lps[j - 1]

            if combined[i] == combined[j]:
                j += 1

            lps[i] = j

        # Length of longest palindromic prefix
        pal_len = lps[-1]

        # Characters after the palindromic prefix
        suffix = s[pal_len:]

        return suffix[::-1] + s