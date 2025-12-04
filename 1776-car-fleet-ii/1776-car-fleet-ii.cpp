class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();

        // Stores the time at which each car will collide with the next.
        // -1 means it will never collide.
        vector<double> collisionTime(n, -1.0);

        // Monotonic stack of car indices to the right that are possible collision targets.
        stack<int> candidateCars;

        for (int i = n - 1; i >= 0; --i) {

            double currPos = cars[i][0];     // current car's position
            double currSpeed = cars[i][1];   // current car's speed

            // Remove cars that this car cannot catch because they're faster/equal speed.
            while (!candidateCars.empty() &&
                   currSpeed <= cars[candidateCars.top()][1]) {
                candidateCars.pop();
            }

            // Find the first valid collision target
            while (!candidateCars.empty()) {

                int target = candidateCars.top();   // car we might collide with
                double targetPos = cars[target][0];
                double targetSpeed = cars[target][1];

                // Time required to catch the target car
                double timeToCatch = (targetPos - currPos) /
                                     (currSpeed - targetSpeed);

                /*
                   If target car collides earlier than timeToCatch, then
                   target changes speed BEFORE we reach it → invalid target.
                */
                if (collisionTime[target] > 0 &&
                    timeToCatch >= collisionTime[target]) {
                    candidateCars.pop();  // try next candidate
                } else {
                    // Valid collision target found
                    collisionTime[i] = timeToCatch;
                    break;
                }
            }

            // push this car as a future candidate for cars on the left
            candidateCars.push(i);
        }

        return collisionTime;
    }
};
