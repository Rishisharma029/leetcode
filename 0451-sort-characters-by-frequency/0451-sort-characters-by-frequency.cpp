class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        priority_queue<pair<int, char>> pq;

        for (auto &[c, cnt] : freq)
            pq.push({cnt, c});

        string ans;

        while (!pq.empty()) {
            auto [cnt, c] = pq.top();
            pq.pop();

            ans.append(cnt, c);
        }

        return ans;
    }
};