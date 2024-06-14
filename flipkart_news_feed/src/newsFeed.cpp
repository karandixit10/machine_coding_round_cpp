#include "../include/newsFeed.hpp"
#include <iostream>
#include <algorithm>
NewsFeed::NewsFeed() : currentUser(nullptr) {}

void NewsFeed ::signup(const std::string &email)
{
    if (users.find(email) == users.end())
    {
        users[email] = new User(email);
        std::cout << email << " signed up successfully." << std::endl;
    }
    else
    {
        std::cout << email << " User Already Exists." << std::endl;
    }
}

void NewsFeed ::login(const std::string &email)
{
    if (users.find(email) != users.end())
    {
        currentUser = users[email];
        std::cout << email << " logged in successfully." << std::endl;
    }
    else
    {
        std::cout << email << " User does not exist." << std::endl;
    }
}

void NewsFeed ::logout()
{
    if (currentUser)
    {
        currentUser->logout();
        currentUser->displayLastSession();
        currentUser = nullptr;
    }
    else
    {
        std::cout << "You are not logged in." << std::endl;
    }
}

void NewsFeed ::post(const std::string &content)
{
    if (currentUser)
    {
        Post *newPost = new Post(currentUser->getEmail(), content);
        posts.push_back(newPost);
        currentUser->addPost(newPost);
    }
    else
    {
        std::cout << "You are not logged in." << std::endl;
    }
}

void NewsFeed ::follow(const std::string &email)
{
    if (currentUser)
    {
        if (users.find(email) != users.end())
        {
            currentUser->follow(users[email]);
        }
        else
        {
            std::cout << email << " User does not exist." << std::endl;
        }
    }
    else
    {
        std::cout << "You are not logged in." << std::endl;
    }
}

void NewsFeed ::reply(const std::string &postId, const std::string &comment)
{
    if (currentUser)
    {
        Post *post = findPostById(postId);
        if (post)
        {
            Post *newComment = new Post(currentUser->getEmail(), comment);
            post->addComment(newComment);
        }
        else
        {
            std::cout << postId << " Post does not exist." << std::endl;
        }
    }
    else
    {
        std::cout << "User must be logged in to comment." << std::endl;
    }
}

void NewsFeed ::upvote(const std::string &postId)
{
    if (currentUser)
    {
        Post *post = findPostById(postId);
        if (post)
        {
            post->upVotes();
        }
        else
        {
            std::cout << postId << " Post does not exist." << std::endl;
        }
    }
    else
    {
        std::cout << "User must be logged in to upvote." << std::endl;
    }
}

void NewsFeed ::downvote(const std::string &postId)
{
    if (currentUser)
    {
        Post *post = findPostById(postId);
        if (post)
        {
            post->downVotes();
        }
        else
        {
            std::cout << postId << " Post does not exist." << std::endl;
        }
    }
    else
    {
        std::cout << "User must be logged in to downvote." << std::endl;
    }
}

void NewsFeed ::showNewsFeed() const
{
    if (currentUser)
    {
        std ::vector<Post *> feedPosts;

        for (User *followedUser : currentUser->getFollowedUsers())
        {
            const std::vector<Post *> &userPosts = followedUser->getPosts();
            feedPosts.insert(feedPosts.end(), userPosts.begin(), userPosts.end());
        }
        std::sort(feedPosts.begin(), feedPosts.end(), [](Post* a, Post* b) {
            if (a->getScore() != b->getScore()) {
                return a->getScore() > b->getScore();
            }
            if (a->getComments().size() != b->getComments().size()) {
                return a->getComments().size() > b->getComments().size();
            }
            return a->getTimestamp() > b->getTimestamp();
        });

        for (const Post* post : feedPosts) {
            std::cout << "id: " << post->getTimestamp() << std::endl;
            std::cout << "(" << post->getScore() << " upvotes, " << post->getComments().size() << " comments)" << std::endl;
            std::cout << post->getAuthor() << std::endl;
            std::cout << post->getContent() << std::endl;
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "User must be logged in to see news feed." << std::endl;
    }
}

Post* NewsFeed::findPostById(const std::string& postId) const {
    for (Post* post : posts) {
        if (std::to_string(post->getTimestamp()) == postId) {
            return post;
        }
    }
    return nullptr;
}