//------------------------------------------------
// GUARDS
//------------------------------------------------

#ifndef __POSTS_H_INCLUDED__
#define __POSTS_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
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
  void set();
  // set anonymous to false
	void set(Name, Password, Email){};
  Name getName(){};
  bool checkUser(Email, Password){};
};

//------------------------------------------------
// Class Post
//------------------------------------------------

class Post {
private:
  Name author;
	Text postContent;
  vector<Avaliation> avaliations;
  vector<Comment> comments;

public:
  Post(){};
  Post get(){};
  Name getAuthor(){};
  Text getPostContent(){};
  Avaliation getFinalAvaliation(){};
  vector<Comment> getComments();
  // Name of the user who is adding a post
  void set(Name, Text){};
  // Name of the user who is adding a avaliation
  void addAvaliation(Name, Avaliation){};
  // Name of the user who is adding a comment
  void addComment(Name, Comment){};
};

//------------------------------------------------
// Class Comment
//------------------------------------------------

class Comment {
private:
  Name author;
	Text commentContent;
  vector<Avaliation> avaliations;

public:
  Comment(){};
  Comment get(){};
  Name getAuthor(){};
  Text getPostContent(){};
  Avaliation getFinalAvaliation(){};
  // Name of the user who is adding a post
  void set(Name, Text){};
  // Name of the user who is adding a avaliation
  void addAvaliation(Name, Avaliation){};
};

#endif
