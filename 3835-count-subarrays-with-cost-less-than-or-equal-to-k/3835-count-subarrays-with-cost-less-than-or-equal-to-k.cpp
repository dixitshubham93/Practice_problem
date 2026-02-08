class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int>maxQ;
        deque<int>minQ;
        int n = nums.size();
        int left = 0;
        ll count = 0;
        for(int right = 0;right<n;right++){
            while(!maxQ.empty()&&nums[maxQ.back()]<=nums[right]){
            maxQ.pop_back();
            }
            maxQ.push_back(right);
             while(!minQ.empty()&&nums[minQ.back()]>=nums[right]){
            minQ.pop_back();
            }
            minQ.push_back(right);

            while(left<=right){
                int mn = nums[minQ.front()];
                int mx = nums[maxQ.front()];
                ll diff  = mx - mn;
                if(diff*(right - left + 1)<=k){break;}
                left++;
                if(!minQ.empty()&&minQ.front()<left){
                    minQ.pop_front();
                }
                if(!maxQ.empty()&&maxQ.front()<left){
                    maxQ.pop_front();
                }
            }
            count += (right - left + 1);
        }
        return count;
    }
};