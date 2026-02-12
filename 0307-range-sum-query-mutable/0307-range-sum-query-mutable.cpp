class NumArray {
public:
    vector<int>Segment;
    int n ;
    void build(vector<int>& nums , int idx , int s , int e){
        if(s==e){
            Segment[idx] = nums[s];
            return;
        }
        int mid = (s+e)/2;

        build(nums , idx*2+1 , s , mid);
        build(nums , idx*2+2 , mid+1 , e);
        Segment[idx] = Segment[idx*2+1] + Segment[idx*2 + 2];
        return ;
    }
    NumArray(vector<int>& nums) {
         n = nums.size();
        Segment.assign(4*n , 0);
        build(nums , 0 , 0 , n-1);
    }
    void getUpdate(int idx ,int s, int e,  int index , int val){
        if(s==e){
            Segment[idx] = val;
            return;
        }

        int mid  = (s+e)/2;

        if(index<=mid){
            getUpdate(idx*2 + 1 , s , mid , index , val);
        }else{
            getUpdate(idx*2 + 2 , mid+1 , e , index , val);
        }
        Segment[idx] = Segment[2 * idx + 1] + Segment[2 * idx + 2];
       return;
    }
    void update(int index, int val) {
        getUpdate(0 , 0 , n-1 , index , val);
    }
    int getSum(int idx , int si , int sj , int left , int right){
        if(sj<left||si>right){
            return 0 ;
        }
        if(left <= si && sj <= right){
            return Segment[idx];
        }
        int mid = (si+sj)/2;
        int l  = getSum(idx*2+1 , si , mid , left , right);
        int r = getSum(idx*2+2 , mid+1 , sj , left , right);
      return l + r;
    }
    int sumRange(int left, int right) {
       return getSum( 0 , 0 ,n-1 , left , right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */