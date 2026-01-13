class Solution {
public:
bool isEnoughBelow(vector<vector<int>>& squares, double mid, double half) {
    double below = 0;

    for (auto &s : squares) {
        double y = s[1];
        double side = s[2];
        double bottom = y;
        double top = y + side;

        if (top <= mid) {
            below += side * side;
        }
        else if (bottom < mid) {
            below += (mid - bottom) * side;
        }
    }
    return below >= half;
}



double separateSquares(vector<vector<int>>& squares) {
    double totalArea = 0;
    for (auto &s : squares)
        totalArea += 1.0 * s[2] * s[2];

    double half = totalArea / 2.0;

    double low = 0, high = 2e9;
    double eps = 1e-5;

    while (high - low > eps) {
        double mid = (low + high) / 2.0;
        if (isEnoughBelow(squares, mid, half))
            high = mid;
        else
            low = mid;
    }
    return (low + high) / 2.0;
}

};
