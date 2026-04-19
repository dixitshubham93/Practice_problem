class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.size();
        vector<long long> candidates;

        // Edge cases
        long long high = 1;
        for(int i = 0; i < len; i++) high *= 10;
        candidates.push_back(high + 1);      
        long long low = 1;
        for(int i = 0; i < len-1; i++) low *= 10;
        candidates.push_back(low - 1);    

        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        for (long long i : {-1, 0, 1}) {
            string p = to_string(prefix + i);
            string candidateStr = p;

            string suffix = p;
            reverse(suffix.begin(), suffix.end());

            if (len % 2 == 0) candidateStr += suffix;
            else candidateStr += suffix.substr(1);

            candidates.push_back(stoll(candidateStr));
        }

        long long bestCandidate = -1;
        long long minDiff = LLONG_MAX;

        for (long long cand : candidates) {
            if (cand == num) continue;

            long long diff = llabs(cand - num);

            if (diff < minDiff || (diff == minDiff && cand < bestCandidate)) {
                minDiff = diff;
                bestCandidate = cand;
            }
        }

        return to_string(bestCandidate);
    }
};