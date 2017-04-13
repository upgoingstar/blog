//------------------------------------------------
// GUARDS
//------------------------------------------------

#ifndef __POSTS_H_INCLUDED__
#define __POSTS_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include "domains.hpp"
using namespace std;

//------------------------------------------------
// Class User
//------------------------------------------------

class User{
private:
	Name name;
	Password password;
	Email email;
	bool anonymous;

public:
  // set anonymous to true
  User(){};
	~User(){};
  // set anonymous to false
	void set(Name, Password, Email){};
  Name get_name(){};
  bool check_user(Email, Password){};
};

//------------------------------------------------
// Class Post
//------------------------------------------------

class Post {
private:
  Name author;
	Text content;
  vector<Avaliation> avaliations;
  vector<Comment> comments;

public:
  Post(){};
	~Post(){};
  Post get(){};
  Name get_author(){};
  Text get_content(){};
  Avaliation get_final_avaliation(){};
  vector<Comment> get_comments();
  // Name of the user who is adding a post
  void set(Name, Text){};
  // Name of the user who is adding a avaliation
  void add_avaliation(Avaliation){};
  // Name of the user who is adding a comment
  void add_comment(Comment){};
};

//------------------------------------------------
// Class Comment
//------------------------------------------------

//TODO: herdar Post
class Comment {
private:
  Name author;
	Text content;
  vector<Avaliation> avaliations;

public:
  Comment(){};
	~Comment(){};
  Name Post::get_author(){};
  Text Post::get_content(){};
  Avaliation Post::get_final_avaliation(){};
  // Name of the user who is adding a post
  void Post::set(Name, Text){};
  // Name of the user who is adding a avaliation
  void Post::add_avaliation(Avaliation){};
};

#endif
