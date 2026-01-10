class KthLargest {
public:
    priority_queue<int , vector<int> , greater<>>q;
    int r ;
    KthLargest(int k, vector<int>& nums) {
        r = k;
        for(int i : nums){
            q.push(i);
            if(q.size()>k){q.pop();}
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>r){
        q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */