#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Twitter {
public:
    Twitter() {
        timestamp = 0; // Initialize timestamp to 0
    }

    // Function to post a tweet
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({tweetId, timestamp++});
    }

    // Function to get the news feed for a user
    vector<int> getNewsFeed(int userId) {
        // Min heap to store top 10 recent tweets
        auto cmp = [](const Tweet& a, const Tweet& b) {
            return a.time < b.time;
        };
        priority_queue<Tweet, vector<Tweet>, decltype(cmp)> minHeap(cmp);

        // Add the user's tweets to the heap
        for (const auto& tweet : userTweets[userId]) {
            minHeap.push(tweet);
        }

        // Add tweets of followed users to the heap
        if (followers.count(userId)) {
            for (int followeeId : followers[userId]) {
                for (const auto& tweet : userTweets[followeeId]) {
                    minHeap.push(tweet);
                }
            }
        }

        // Extract top 10 tweets from the heap
        vector<int> newsFeed;
        while (!minHeap.empty() && newsFeed.size() < 10) {
            newsFeed.push_back(minHeap.top().tweetId);
            minHeap.pop();
        }

        return newsFeed;
    }

    // Function to follow a user
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    // Function to unfollow a user
    void unfollow(int followerId, int followeeId) {
        if (followers.count(followerId)) {
            followers[followerId].erase(followeeId);
        }
    }

private:
    struct Tweet {
        int tweetId;
        int time;
    };

    int timestamp; // Class member to keep track of the time
    unordered_map<int, vector<Tweet>> userTweets; // Map of user ID to their tweets
    unordered_map<int, unordered_set<int>> followers; // Map of user ID to the set of followees
};

int main() {
    Twitter twitter;

    // Test case: Post tweets
    twitter.postTweet(1, 5);  // User 1 posts tweet 5
    twitter.postTweet(1, 3);  // User 1 posts tweet 3
    twitter.postTweet(2, 101); // User 2 posts tweet 101
    twitter.postTweet(2, 102); // User 2 posts tweet 102

    // Test case: Follow and get news feed
    twitter.follow(1, 2); // User 1 follows User 2
    vector<int> feed = twitter.getNewsFeed(1); // Get news feed for User 1

    // Print the news feed
    cout << "News Feed for User 1: ";
    for (int tweetId : feed) {
        cout << tweetId << " ";
    }
    cout << endl;

    // Test case: Unfollow and get news feed
    twitter.unfollow(1, 2); // User 1 unfollows User 2
    feed = twitter.getNewsFeed(1); // Get news feed for User 1 after unfollowing

    // Print the news feed
    cout << "News Feed for User 1 after unfollowing User 2: ";
    for (int tweetId : feed) {
        cout << tweetId << " ";
    }
    cout << endl;

    return 0;
}
