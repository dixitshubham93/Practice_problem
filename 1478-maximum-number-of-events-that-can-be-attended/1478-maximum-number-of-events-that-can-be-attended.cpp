class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); 
        int x = events.size();
        int n = 0;
        for (auto& event : events) {
            n = max(n, event[1]);
        }

        int it = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int count = 0;

        for (int d = 1; d <= n; d++) {
            while (it < x && events[it][0] <= d) {
                q.push({events[it][1], events[it][0]});
                it++;
            }

            while (!q.empty() && q.top().first < d) {
                q.pop();
            }

            if (!q.empty()) {
                q.pop();
                count++;
            }
        }

        return count;
    }
};
