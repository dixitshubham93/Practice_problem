class Solution {
public:
    unordered_map<int, unordered_set<int>> dp; // dp[index][k] => true if it's been tried and failed

    bool solve(vector<int>& stones, int index, int k, unordered_map<int, int>& stoneIndex) {
        if (index == stones.back()) return true;
        if (dp[index].count(k)) return false;

        for (int jump = k - 1; jump <= k + 1; ++jump) {
            if (jump <= 0) continue;
            int nextPos = index + jump;
            if (stoneIndex.count(nextPos)) {
                if (solve(stones, nextPos, jump, stoneIndex)) return true;
            }
        }

        dp[index].insert(k); // mark this state as failed
        return false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;

        unordered_map<int, int> stoneIndex;
        for (int stone : stones) {
            stoneIndex[stone] = 1;
        }

        return solve(stones, 1, 1, stoneIndex);
    }
};
