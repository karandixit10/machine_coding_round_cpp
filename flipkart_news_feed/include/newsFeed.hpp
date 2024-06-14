#ifndef NEWSFEED_HPP
#define NEWSFEED_HPP

#include <unordered_map>
#include <vector>
#include "user.hpp"
#include "post.hpp"

class NewsFeed {
public:
                NewsFeed        ();

    void        signup          (const std::string& email);
    void        login           (const std::string& email);
    void        logout          ();
    void        post            (const std::string& content);
    void        follow          (const std::string& email);
    void        reply           (const std::string& postId, const std::string& comment);
    void        upvote          (const std::string& postId);
    void        downvote        (const std::string& postId);
    void        showNewsFeed    () const;

private:
    std::unordered_map<std::string, User*>  users;
    std::vector<Post*>                      posts;
    User*                                   currentUser;

    Post*       findPostById     (const std::string& postId) const;
};

#endif