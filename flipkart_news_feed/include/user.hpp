#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <unordered_set>
#include "../include/post.hpp"

class User { 
public:
                                        User                 (const std::string& email);
    const std::string&                  getEmail            () const;
    void                                addPost             (Post* post);
    const std::vector<Post*>&           getPosts            () const;
    void                                follow              (User* user);
    const std::unordered_set<User*>&    getFollowedUsers    () const;
    void                                login               ();
    void                                logout              ();
    void                                displayLastSession  () const;

private:
    std::string                 email;
    std::vector<Post*>          posts;
    std::unordered_set<User*>   followedUsers;
    time_t                      lastLoginTime;
    time_t                      lastLogoutTime;
    int                         postCountInLastSession;
    double                      sessionDuration;
};

#endif // USER_HPP
