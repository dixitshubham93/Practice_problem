class Solution {
public:
    int dp[100001][4];

    int solve(vector<pair<int, int>>& arr, vector<int>& walls, int idx, int l) {
        if (idx >= arr.size())
            return 0;

        if (dp[idx][l+1]!=-1)
            return dp[idx][l+1];

        int curr = upper_bound(walls.begin(), walls.end(), arr[idx].first) -
                   walls.begin();

        int left_range = lower_bound(walls.begin(), walls.end(),
                                     arr[idx].first - arr[idx].second) -
                         walls.begin();

        int left_robot = 0;

        if (idx > 0) {
            if (l == 0) {
                left_robot =
                    upper_bound(walls.begin(), walls.end(),
                                arr[idx - 1].first + arr[idx - 1].second) -
                    walls.begin();
            } else if (l == 1) {
                left_robot = upper_bound(walls.begin(), walls.end(),
                                         arr[idx - 1].first) -
                             walls.begin();
            }
        }

        int left_walls = curr - max(left_range, left_robot);

        int first = left_walls + solve(arr, walls, idx + 1, 1);

        int next_robot = walls.size();

        if (idx != arr.size() - 1) {
            next_robot =
                lower_bound(walls.begin(), walls.end(), arr[idx + 1].first) -
                walls.begin();
        }

        int start = lower_bound(walls.begin(), walls.end(), arr[idx].first) -
                    walls.begin();
        int shoot = upper_bound(walls.begin(), walls.end(),
                                arr[idx].first + arr[idx].second) -
                    walls.begin();

        int right_walls = min(shoot, next_robot) - start;

        int second = right_walls + solve(arr, walls, idx + 1, 0);

        return dp[idx][l+1] =max(second, first);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        memset(dp , - 1, sizeof(dp));
        vector<pair<int, int>> arr;
        int n = robots.size();

        for (int i = 0; i < n; i++) {
            arr.push_back({robots[i], distance[i]});
        }

        sort(arr.begin(), arr.end());
        sort(walls.begin(), walls.end());

        return solve(arr, walls, 0, -1);
    }
};