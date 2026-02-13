class Solution {
public:
    int n;
    vector<int> segment;

    void build(vector<int>& heights, int idx, int s, int e) {
        if (s == e) {
            segment[idx] = s;
            return;
        }

        int mid = (s + e) / 2;

        build(heights, 2 * idx + 1, s, mid);
        build(heights, 2 * idx + 2, mid + 1, e);

        int leftIdx = segment[2 * idx + 1];
        int rightIdx = segment[2 * idx + 2];

        if (heights[leftIdx] >= heights[rightIdx])
            segment[idx] = leftIdx;
        else
            segment[idx] = rightIdx;
    }

    int Rmiq(vector<int>& heights, int idx, int left, int right, int l, int r) {
        if (r < left || right < l) return -1;

        if (l <= left && right <= r)
            return segment[idx];

        int mid = (left + right) / 2;

        int L = Rmiq(heights, 2 * idx + 1, left, mid, l, r);
        int R = Rmiq(heights, 2 * idx + 2, mid + 1, right, l, r);

        if (L == -1) return R;
        if (R == -1) return L;

        return heights[L] >= heights[R] ? L : R;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {

        n = heights.size();
        segment.assign(4 * n, 0);
        build(heights, 0, 0, n - 1);

        int q = queries.size();
        vector<int> ans(q, -1);

        for (int i = 0; i < q; i++) {

            int a = queries[i][0];
            int b = queries[i][1];

            if (a == b) {
                ans[i] = a;
                continue;
            }


            if (a > b) swap(a, b);
            // If right building already taller
            if (heights[b] > heights[a]) {
                ans[i] = b;
                continue;
            }
            

            int val = heights[a];
            int s = b + 1;
            int e = n - 1;

            int res = -1;

            while (s <= e) {
                int mid = (s + e) / 2;

                int idx = Rmiq(heights, 0, 0, n - 1, s, mid);

                if (idx != -1 && heights[idx] > val) {
                    res = idx;
                    e = mid - 1;   // search left half
                } else {
                    s = mid + 1;   // search right half
                }
            }

            ans[i] = res;
        }

        return ans;
    }
};
