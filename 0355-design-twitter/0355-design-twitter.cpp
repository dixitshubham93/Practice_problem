class Twitter {
public:

    int tweet = 0;
    unordered_map<int, set<pair<int, int>, greater<pair<int, int>>>>ut;
    unordered_map<int , unordered_set<int>>uu;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        ut[userId].insert({tweet, tweetId});
        tweet++;
    }
    
    vector<int> getNewsFeed(int userId) {
        uu[userId].insert(userId);
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<>>pq;

        for(auto& u:uu[userId]){
           int cnt = 0;
            for(auto& t:ut[u]){
              pq.push(t);
              if(pq.size()>10)pq.pop();
              if(++cnt==10)break;
            }
        }
        vector<int>ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        uu[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
         uu[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */