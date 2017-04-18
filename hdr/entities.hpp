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

public:
  User();
	~User();
	void set(Name, Email, Password);
  Name get_name();
  void check_user(Email, Password);
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
private:
	// how much comments each user did (see later how to use map with classes)

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
