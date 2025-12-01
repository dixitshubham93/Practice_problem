class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength,int mid){
        multiset<int>st(workers.end()-mid , workers.end());
        for(int i=mid-1;i>=0;i--){
            auto it = st.lower_bound(tasks[i]);
            if(it!=st.end()){
                st.erase(it);
                continue;
            }
            int need = tasks[i] - strength;
            it = st.lower_bound(need);
            if(it==st.end()||pills==0){
                return false;
            }
            pills--;
            st.erase(it);
        }
        return true;
    }
    
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength){
        sort(tasks.begin()   ,  tasks.end());
        sort(workers.begin() , workers.end());

        int ans = 0;
        int low = 0;
        int high = min(tasks.size() , workers.size());

        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(tasks , workers , pills , strength , mid)){
                low = mid+1;
                ans = max(mid , mid);
            }else{
                high = mid-1;
            }
        }
         return ans;
    }
};