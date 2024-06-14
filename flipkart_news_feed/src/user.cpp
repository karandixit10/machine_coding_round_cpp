#include "../include/user.hpp"
#include <iostream>

User::User(const std::string& email) : email(email), lastLoginTime(0), lastLogoutTime(0), postCountInLastSession(0), sessionDuration(0.0) {}

const std::string& User::getEmail() const {
    return email;
}

void User::addPost(Post* post) {
    posts.push_back(post);
    postCountInLastSession++;
}

const std::vector<Post*>& User::getPosts() const {
    return posts;
}

void User::follow(User* user) {
    followedUsers.insert(user);
}

const std::unordered_set<User*>& User::getFollowedUsers() const {
    return followedUsers;
}

void User::login() {
    lastLoginTime = std::time(nullptr);
    postCountInLastSession = 0;
}

void User::logout() {
    lastLogoutTime = std::time(nullptr);
    sessionDuration = difftime(lastLogoutTime, lastLoginTime);
}

void User::displayLastSession() const {
    std::cout << "Last session details:" << std::endl;
    std::cout << "Number of posts: " << postCountInLastSession << std::endl;
    std::cout << "Session duration: " << sessionDuration << " seconds" << std::endl;
} // displayLastSession
