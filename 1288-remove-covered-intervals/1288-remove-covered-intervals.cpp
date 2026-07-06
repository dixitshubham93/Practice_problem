class Solution {
public:
    static bool comparator (const vector<int>&a , const vector<int>&b){
          if(a[0]==b[0]){return a[1]>b[1];}
          return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , comparator);
        
        int n = intervals.size();
        int count = 1;
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i = 1;i<n;i++){
            if(end>=intervals[i][1]&&start<=intervals[i][0]){
            }else{
                start = intervals[i][0];
                end = intervals[i][1];
                count++;
            }
        }
      return count;
    }
};