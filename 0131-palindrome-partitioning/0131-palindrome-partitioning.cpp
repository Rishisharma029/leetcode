class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

    void dfs(string &s, int start) {

        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            if (isPalindrome(s, start, end)) {

                path.push_back(s.substr(start, end - start + 1));

                dfs(s, end + 1);

                path.pop_back();   // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {

        dfs(s, 0);

        return ans;
    }
};