class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(string &s, int start) {

        if (memo.count(start))
            return memo[start];

        vector<string> res;

        if (start == s.size()) {
            res.push_back("");
            return res;
        }

        for (int end = start; end < s.size(); end++) {

            string word = s.substr(start, end - start + 1);

            if (dict.count(word)) {

                vector<string> suffixes = dfs(s, end + 1);

                for (string suffix : suffixes) {

                    if (suffix.empty())
                        res.push_back(word);
                    else
                        res.push_back(word + " " + suffix);
                }
            }
        }

        return memo[start] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        dict = unordered_set<string>(wordDict.begin(), wordDict.end());

        return dfs(s, 0);
    }
};