/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    class User{
        public:
        int uid;
        vector<int> tweets;
        set<int> following;
    };
    vector<User> userstack;
    vector<pair<int, int>> tweetlog;
    Twitter() {
        vector<User> random(501);
        userstack = random;
        for(int i = 0 ; i<userstack.size(); i++){
            userstack[i].uid = i;
        }
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        userstack[userId].tweets.push_back(tweetId);
        tweetlog.push_back({userId, tweetId});

    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int count = 0;
        for(int i = tweetlog.size()-1; i>=0; i--){
            int usrid = tweetlog[i].first, twtid = tweetlog[i].second;
            //cout<<usrid<<" "<<twtid<<endl;
            if(count < 10 && (userstack[userId].following.count(usrid)||usrid == userId)) {
                //cout<<"found"<<endl;
                ans.push_back(twtid);
                ++count;
            }
            if(count >=10) break;
        }
        //cout<<endl;
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        //set<int> random = userstack[followerId].following;
        if(userstack[followerId].following.count(followeeId)) return;
        else{
            userstack[followerId].following.insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(userstack[followerId].following.count(followeeId)){
            userstack[followerId].following.erase(followeeId);
        }
        else return;
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
// @lc code=end

