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
  User();
	~User();
  // set anonymous to false
	void set(Name, Password, Email);
  Name get_name();
  bool check_user(Email, Password);
};

//------------------------------------------------
// Class Content
//------------------------------------------------

class Content {
protected:
	Name author;
	Text content;
	vector<Avaliation> avaliations;
public:
	Name get_author();
  Text get_content();
	Avaliation get_avaliation();
	// Name of the user who is adding a post
  void set(Name, Text);
  // Name of the user who is adding a avaliation
  void add_avaliation(Avaliation);
};

//------------------------------------------------
// Class Comment
//------------------------------------------------

class Comment : public Content {
private:
	// how much comments each user did
	map<Name, int> authorCnt;

public:
  Comment();
	~Comment();
};

//------------------------------------------------
// Class Post
//------------------------------------------------

class Post : public Content {
private:
  vector<Comment> comments;

public:
  Post();
	~Post();
  vector<Comment> get_comments();
  // Name of the user who is adding a comment
  void add_comment(Comment);
};


#endif
