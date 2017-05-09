//------------------------------------------------
// GUARDS
//------------------------------------------------

#ifndef __ENTITIES_H_INCLUDED__
#define __ENTITIES_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------

	#include "domains.hpp"
	#include <bits/stdc++.h>
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
	void valid(Name, Email, Password) throw(invalid_argument);

public:
  User();
  ~User();
  void set(Name, Email, Password);
  Name get_name() throw(invalid_argument);
  void check_user(Email, Password) throw(invalid_argument);
};

//------------------------------------------------
// Class Content
//------------------------------------------------

class Content {
private:
	void valid(Name,Text) throw(invalid_argument);
protected:
	Name author;
	Text content;
	vector<Avaliation> avaliations;
public:
	Content();
	~Content();
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
public:
  Comment(Name,Text);
  ~Comment();
};

//------------------------------------------------
// Class Post
//------------------------------------------------

class Post : public Content {
private:
  static const int comments_limit = 5;
  map<Name,int> number_comments;
  vector<Comment> comments;
  bool comments_allowed;

public:
  Post(Name,Text,bool default_value = false);
  ~Post();
  void allow_comments();
  vector<Comment> get_comments();
  // Name of the user who is adding a comment
  void add_comment(Comment) throw(invalid_argument);
};


#endif
