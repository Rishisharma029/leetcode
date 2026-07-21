class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;

        unordered_set<int> stoneSet(stones.begin(), stones.end());

        dp[0].insert(0);

        for (int stone : stones) {
            for (int k : dp[stone]) {

                for (int jump = k - 1; jump <= k + 1; jump++) {

                    if (jump <= 0) continue;

                    int nextStone = stone + jump;

                    if (stoneSet.count(nextStone))
                        dp[nextStone].insert(jump);
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};