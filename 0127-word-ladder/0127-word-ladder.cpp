class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {

            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord)
                return steps;

            for (int i = 0; i < word.size(); i++) {

                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    temp[i] = ch;

                    if (st.count(temp)) {

                        q.push({temp, steps + 1});

                        // Mark visited
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};