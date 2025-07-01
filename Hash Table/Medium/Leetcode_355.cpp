class Twitter {
public:
    // To store userId and tweetId
    vector<vector<int>> user_tweet;    
    // To store follower and followee Ids
    vector<vector<bool>> followers;
    // To store all the userIds and tweetIds
    vector<pair<int, int>> tweets;
    Twitter() 
    {
        user_tweet = vector<vector<int>>(10001);
        followers = vector<vector<bool>>(10001, vector<bool>(10001, false));
    }
    
    void postTweet(int userId, int tweetId) 
    {
        user_tweet[userId].push_back(tweetId);
        tweets.push_back(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> ans;
        int k = 0;
        for(int i=tweets.size()-1;i>=0 && k < 10;i--)
        {
            int follower = tweets[i].first;
            if((follower == userId || followers[userId][follower]))
            {
                ans.push_back(tweets[i].second);
                k++;
            }
        }
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
