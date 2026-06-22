class Solution {
public:
    vector<string> ans;

    void backtrack(string &s, int idx, int parts, string curr) {
        // If 4 parts formed and entire string used
        if (parts == 4 && idx == s.size()) {
            curr.pop_back(); // remove last '.'
            ans.push_back(curr);
            return;
        }

        // Invalid cases
        if (parts == 4 || idx == s.size())
            return;

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string segment = s.substr(idx, len);

            // Leading zero not allowed
            if (segment.size() > 1 && segment[0] == '0')
                break;

            int num = stoi(segment);

            if (num <= 255) {
                backtrack(s, idx + len, parts + 1, curr + segment + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return ans;
    }
};