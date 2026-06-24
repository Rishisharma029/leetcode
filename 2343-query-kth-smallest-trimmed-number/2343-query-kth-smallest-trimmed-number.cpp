class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>> orders(m + 1);
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        orders[0] = order;

        for (int pos = m - 1, trim = 1; pos >= 0; pos--, trim++) {
            vector<vector<int>> bucket(10);

            for (int idx : order) {
                int digit = nums[idx][pos] - '0';
                bucket[digit].push_back(idx);
            }

            order.clear();

            for (int d = 0; d < 10; d++)
                for (int idx : bucket[d])
                    order.push_back(idx);

            orders[trim] = order;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int k = q[0], trim = q[1];
            ans.push_back(orders[trim][k - 1]);
        }

        return ans;
    }
};