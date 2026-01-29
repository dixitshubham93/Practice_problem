class StockSpanner {
public:
    vector<int>temp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        temp.push_back(price);
        int i = temp.size()-1;
        int count =0;
        while(i>=0&&temp.back()>=temp[i]){
         count++;
         i--;
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */