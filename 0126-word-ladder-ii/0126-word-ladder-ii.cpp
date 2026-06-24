class Solution {
public:
    unordered_map<string, vector<string>> parent;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string beginWord) {
        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        else {
            for (auto &p : parent[word])
                dfs(p, beginWord);
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, int> level;
        level[beginWord] = 0;

        int len = beginWord.size();

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int currLevel = level[word];

            string temp = word;

            for (int i = 0; i < len; i++) {

                char original = temp[i];

                for (char c = 'a'; c <= 'z'; c++) {

                    temp[i] = c;

                    if (!st.count(temp))
                        continue;

                    if (!level.count(temp)) {
                        level[temp] = currLevel + 1;
                        q.push(temp);
                        parent[temp].push_back(word);
                    }
                    else if (level[temp] == currLevel + 1) {
                        parent[temp].push_back(word);
                    }
                }

                temp[i] = original;
            }
        }

        if (!level.count(endWord))
            return {};

        dfs(endWord, beginWord);

        return ans;
    }
};