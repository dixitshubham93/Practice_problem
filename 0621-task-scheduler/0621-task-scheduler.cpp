class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char c : tasks) freq[c]++;

        priority_queue<int> pq;
        for (auto &it : freq) pq.push(it.second);

        queue<pair<int, int>> cooldown; 
      

        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;

            if (!pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                cnt--;

                if (cnt > 0) {
                    cooldown.push({cnt, time + n});
                }
            }

            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};
