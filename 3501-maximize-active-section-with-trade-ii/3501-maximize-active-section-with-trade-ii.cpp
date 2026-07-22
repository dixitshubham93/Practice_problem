class SegmentTree {
public:
    vector<int> tree;
    vector<int> arr;

    SegmentTree(vector<int>& arr) {
        this->arr = arr;
        int n = arr.size();
        tree.resize(4 * max(1, n));

        if (n)
            build(0, 0, n - 1);
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * idx + 1, l, mid);
        build(2 * idx + 2, mid + 1, r);

        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    int query(int idx, int l, int r, int left, int right) {
        if (left > right)
            return 0;

        if (r < left || l > right)
            return 0;

        if (left <= l && r <= right)
            return tree[idx];

        int mid = l + (r - l) / 2;

        return max(query(2 * idx + 1, l, mid, left, right),
                   query(2 * idx + 2, mid + 1, r, left, right));
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {

        vector<int> BlockLength;
        vector<int> BlockLeft;
        vector<int> BlockRight;

        int n = s.size();
        int cnt1 = count(s.begin(), s.end(), '1');

        int i = 0;

        while (i < n) {
            int start = i;

            while (i < n && s[i] == s[start])
                i++;

            if (s[start] == '0') {
                BlockLength.push_back(i - start);
                BlockLeft.push_back(start);
                BlockRight.push_back(i - 1);
            }
        }

        int m = BlockLength.size();

        // Fix 1
        if (m < 2)
            return vector<int>(queries.size(), cnt1);

        vector<int> Contri;

        for (int i = 0; i < m - 1; i++)
            Contri.push_back(BlockLength[i] + BlockLength[i + 1]);

        SegmentTree sg(Contri);

        vector<int> ans;

        for (auto& it : queries) {

            int i = lower_bound(BlockRight.begin(), BlockRight.end(), it[0]) -
                    BlockRight.begin();

            int j = upper_bound(BlockLeft.begin(), BlockLeft.end(), it[1]) -
                    BlockLeft.begin() - 1;

            // Fix 2
            if (i > m - 1 || j < 0 || i >= j) {
                ans.push_back(cnt1);
                continue;
            }

            int firstLen =
                BlockRight[i] - max(it[0], BlockLeft[i]) + 1;

            int lastLen =
                min(it[1], BlockRight[j]) - BlockLeft[j] + 1;

            // Fix 3
            if (i + 1 == j) {
                ans.push_back(cnt1 + firstLen + lastLen);
                continue;
            }

            int lef = firstLen + BlockLength[i + 1];
            int re = lastLen + BlockLength[j - 1];

            int mid = sg.query(0, 0, Contri.size() - 1, i + 1, j - 2);

            ans.push_back(cnt1 + max({lef, re, mid}));
        }

        return ans;
    }
};