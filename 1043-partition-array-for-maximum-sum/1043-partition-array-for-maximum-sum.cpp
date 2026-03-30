class Solution {
public:
    vector<int>tree;
    int size;
    int dp[502][502];
   void segment(vector<int>&arr , int n){
    this->size = n;
    tree.assign(4*n,0);
    build(arr , 0 , 0 , n-1);
    return ;
   }

   void build(vector<int>&arr , int node , int start , int end){

    if(start==end){
        tree[node] =  arr[start];
        return ;
        }  
    int mid = (start+end)/2;
    build(arr , 2*node+1 , start , mid);
    build(arr , 2*node+2 , mid+1 , end);
    tree[node] = max(tree[2*node+1] , tree[2*node+2]);
    
   }
   int query(int node, int start, int end, int l, int r){
    if(end < l || start > r) return INT_MIN;

    if(l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;

    int left = query(2*node+1, start, mid, l, r);
    int right = query(2*node+2, mid+1, end, l, r);

    return max(left, right);
    }

    int Getmax(int l , int r){
        return query(0 ,0, size-1 , l , r);
    }

       int solve(vector<int>& arr, int i , int j, int k)
    {
     int cur = Getmax( i , j);
     if(j==arr.size()-1) return dp[i][j]=(j-i+1)*(cur);
     if(dp[i][j]!=-1)return dp[i][j];
      if(j-i+1==k){return dp[i][j]=(j-i+1)*(cur)+ solve(arr, j+1,j+1,k);}
      int ans = max((j-i+1)*(cur)+solve(arr,j+1,j+1,k),solve(arr,i,j+1,k));
       
      return dp[i][j]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k){
       memset(dp , -1 , sizeof(dp));
       segment(arr , arr.size());
       return  solve(arr , 0 , 0 , k);
    }
};