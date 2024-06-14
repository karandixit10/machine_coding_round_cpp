#include <iostream>
#include <vector>
#include <ctime> // For timestamp
#include "../include/newsFeed.hpp" 

using namespace std;

int main() {
    // Create a NewsFeed instance
    NewsFeed newsFeed;

    // Create some users
    User hermione("hermione@hogwarts.com");
    User ron("ron@hogwarts.com");
    User harry("harry@hogwarts.com");

    // Sign up users
    newsFeed.signup(hermione.getEmail());
    newsFeed.signup(ron.getEmail());
    newsFeed.signup(harry.getEmail());

    // Log in as Harry
    newsFeed.login(harry.getEmail());

    // Post some messages as Harry
    newsFeed.post("I solemnly swear that I am up to no good!");
    newsFeed.post("Expecto Patronum!");

    // Log out Harry
    newsFeed.logout();

    // Log in as Hermione
    newsFeed.login(hermione.getEmail());

    // Follow Harry
    newsFeed.follow(harry.getEmail());

    // Reply to Harry's post (postId assumed to be known)
    newsFeed.reply("001", "I miss our adventures at Hogwarts!");

    // Upvote Harry's first post (postId assumed to be known)
    newsFeed.upvote("001");

    // Log out Hermione
    newsFeed.logout();

    // Log in as Ron
    newsFeed.login(ron.getEmail());

    // Post a message as Ron
    newsFeed.post("Why do all my spells backfire?");

    // Follow Harry
    newsFeed.follow(harry.getEmail());

    // Reply to Harry's second post (postId assumed to be known)
    newsFeed.reply("002", "Maybe you need more practice!");

    // Upvote Harry's second post (postId assumed to be known)
    newsFeed.upvote("002");

    // Post another message as Ron
    newsFeed.post("Quidditch practice was great today!");

    // Log out Ron
    newsFeed.logout();

    // Log in as Hermione again
    newsFeed.login(hermione.getEmail());

    // Post a message as Hermione
    newsFeed.post("The importance of magical creatures in wizarding society cannot be overstated.");

    // Follow Harry again
    newsFeed.follow(harry.getEmail());

    // Upvote Harry's latest post (postId assumed to be known)
    newsFeed.upvote("004");

    // Show Hermione's news feed
    std::cout<<"Showing NEWS FEED"<< std::endl;
    newsFeed.showNewsFeed();

    return 0;
}
