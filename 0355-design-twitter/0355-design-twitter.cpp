class Twitter {
public:
    struct tweetTime {
        int time_stamp;
        int tweet_id;
    };
    int time_stamp = 0;
    int limit = 10;
    
    unordered_map<int, vector<tweetTime>> tweet_mp;

    unordered_map<int, unordered_set<int>> follow_mp;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweet_mp[userId].push_back({time_stamp, tweetId});
        this->time_stamp += 1;
    }
    
    vector<int> getNewsFeed(int userId) {
        
        auto lmd = [&](auto& a, auto& b) {
            return a.time_stamp > b.time_stamp;
        };
        priority_queue<tweetTime, vector<tweetTime>, decltype(lmd)> min_heap(lmd);
        
        
        vector<tweetTime> vec;
        
        // get user's own tweets
        for (auto& a : tweet_mp[userId]) {
            // min_heap.push(a);
            // if (min_heap.size() > limit) min_heap.pop();
            vec.push_back(a);
        }

        
        // get the tweets of users who this user follows
        for (auto& a : follow_mp[userId]) {
            for (auto& b : tweet_mp[a]) {
                // min_heap.push(b);
                // if (min_heap.size() > limit) min_heap.pop();
                vec.push_back(b);
            }
        }
        
        sort(vec.begin(), vec.end(), lmd);
        vector<int> res;
        
        // while (!min_heap.empty()) {
        //     res.push_back(min_heap.top().tweet_id);
        //     min_heap.pop();
        // }
        for (auto& a : vec) {
            res.push_back(a.tweet_id);
            if (res.size() == limit) break;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follow_mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follow_mp[followerId].find(followeeId) != follow_mp[followerId].end()) {
            follow_mp[followerId].erase(followeeId);
        }
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