class Twitter {
public:
    vector<vector<int>> user_tweet;    
    vector<vector<bool>> followers;
    vector<pair<int, int>> tweets;
    Twitter() 
    {
        // vector<vector<int>> user_tweet(1001, vector<int>(10, 0));    
        // vector<vector<int>> followers(1001, vector<int>(1001, false));
        user_tweet = vector<vector<int>>(10001);
        followers = vector<vector<bool>>(10001, vector<bool>(10001, false));
        // tweets = vector<pair<int, int>>(10001);

    }
    
    void postTweet(int userId, int tweetId) 
    {
        user_tweet[userId].push_back(tweetId);
        tweets.push_back(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> ans;
        // cout << tweets.size() << " ";
        int k = 0;
        for(int i=tweets.size()-1;i>=0 && k < 10;i--)
        {
            int follower = tweets[i].first;
            // cout << tweets[i].first << " " << tweets[i].second << endl;
            if((follower == userId || followers[userId][follower]))
            {
                // cout << tweets[i].first << " " << tweets[i].second << endl;
                ans.push_back(tweets[i].second);
                k++;
            }
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) 
    {
        followers[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        followers[followerId][followeeId] = false;    
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
