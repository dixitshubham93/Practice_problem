class Solution {
public:
    
    struct Robot {
        int pos;
        int health;
        char dir;
        int idx;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        vector<Robot> robots;

        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end(), [](Robot &a, Robot &b) {
            return a.pos < b.pos;
        });

        stack<Robot> st;

      
        for (auto &cur : robots) {

         
            if (cur.dir == 'R') {
                st.push(cur);
            } 
            else { 
                
                while (!st.empty() && st.top().dir == 'R') {
                    
                    if (st.top().health < cur.health) {
                        cur.health--;
                        st.pop();
                    } 
                    else if (st.top().health == cur.health) {
                        st.pop();
                        cur.health = 0;
                        break;
                    } 
                    else {
                        st.top().health--;
                        cur.health = 0;
                        break;
                    }
                }

                if (cur.health > 0) {
                    st.push(cur);
                }
            }
        }

 
        vector<pair<int,int>> temp; 

        while (!st.empty()) {
            temp.push_back({st.top().idx, st.top().health});
            st.pop();
        }

  
        sort(temp.begin(), temp.end());

        vector<int> ans;
        for (auto &p : temp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};