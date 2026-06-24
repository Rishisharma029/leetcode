class Solution {
public:
    struct cmp {
        bool operator()(pair<string,int>& a, pair<string,int>& b) {
            if (a.second == b.second)
                return a.first < b.first;   // lexicographically smaller is better
            return a.second > b.second;     // higher frequency is better
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;

        for (auto &word : words)
            freq[word]++;

        priority_queue<
            pair<string,int>,
            vector<pair<string,int>>,
            cmp
        > pq;

        for (auto &[word, count] : freq) {
            pq.push({word, count});
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};