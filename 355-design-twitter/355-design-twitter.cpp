class Twitter {
public:
    
    unordered_map<int,unordered_set<int>>follw;
    unordered_map<int,int>tweet;
    priority_queue<pair<int,int>>pq;
    int time;
    
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[tweetId]=userId;
        pq.push({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int>res;
        int k=10;
        stack<pair<int,int>>st;
        
        while(k && !pq.empty()){
              
             st.push(pq.top());
             pair<int,int>mp=pq.top();
             pq.pop();
             
             int user=tweet[mp.second];
             
             if(user==userId || follw[userId].find(user)!=follw[userId].end())
             {
                res.push_back(mp.second); 
                k--;   
             }
          }
        
        while(!st.empty())
        {
            pq.push(st.top());
            st.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
           follw[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
           follw[followerId].erase(followeeId);
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