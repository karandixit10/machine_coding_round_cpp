#ifndef POST_HPP
#define POST_HPP

#include <string>
#include <vector>

class Post {
public:

                                Post            (const std::string& author, const std::string& content);
    
    void                        addComment      (Post* comment);
    void                        upVotes         ();
    void                        downVotes       ();
    int                         getScore        () const;
    const std::string&          getAuthor       () const;
    const std::string&          getContent      () const;
    const std::vector<Post*>&   getComments     () const;
    time_t                      getTimestamp    () const;



private:

    std::string         author;
    std::string         content;
    int                 upvotes;
    int                 downvotes;
    time_t              timestamp;
    std::vector<Post*>  comments;


};

#endif