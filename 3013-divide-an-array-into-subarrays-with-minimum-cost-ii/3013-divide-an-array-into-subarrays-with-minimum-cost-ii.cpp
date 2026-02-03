class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<int> p1, p2;
        long long sum = 0, mn = LLONG_MAX;
        int n = nums.size();

        int s = 1;
        int e = min(n - 1, 1 + dist);

       
        for (int i = s; i <= e; i++) p2.insert(nums[i]);

        
        while (p1.size() < k - 1) {
            auto it = p2.begin();
            sum += *it;
            p1.insert(*it);
            p2.erase(it);
        }

        mn = sum;

        while (e + 1 < n) {
            // slide window
            int out = nums[s++];
            int in = nums[++e];

            // remove outgoing
            if (auto it = p1.find(out); it != p1.end()) {
                sum -= *it;
                p1.erase(it);
            } else {
                auto it2 = p2.find(out);
                if (it2 != p2.end()) p2.erase(it2);
            }

            // add incoming
            p2.insert(in);

            // rebalance
            while (p1.size() < k - 1) {
                auto it = p2.begin();
                sum += *it;
                p1.insert(*it);
                p2.erase(it);
            }

            while (!p2.empty() && !p1.empty() && *p2.begin() < *p1.rbegin()) {
                auto small = p2.begin();
                auto large = prev(p1.end());

                sum += *small - *large;
                p1.insert(*small);
                p2.insert(*large);

                p1.erase(large);
                p2.erase(small);
            }

            mn = min(mn, sum);
        }

        return mn + nums[0];
    }
};
