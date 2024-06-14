#include "../include/post.hpp"

Post::Post(const std::string& author, const std::string& content)
    : author(author), content(content), upvotes(0), downvotes(0), timestamp(std::time(nullptr)) {}

void Post::addComment(Post* comment){
    comments.push_back(comment);
}

void Post::upVotes(){
    upvotes++;
}

void Post::downVotes(){
    downvotes++;
}

int Post::getScore() const{
    return upvotes - downvotes;
}

const std::string& Post::getAuthor() const{
    return author;
}

const std::string& Post::getContent() const{
    return content;
}

const std::vector<Post*>& Post::getComments() const{
    return comments;
}

time_t Post::getTimestamp() const{
    return timestamp;
}