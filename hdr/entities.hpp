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
		void valid(Name, Email) throw(invalid_argument);

	public:
	  User();
	  ~User();
	  void set(Name, Email, Password);
	  Name get_name() throw(invalid_argument);
	  void check_user(Email, Password) throw(invalid_argument);
	};

//------------------------------------------------
// Class Content
// TODO: this is confuse
//------------------------------------------------

	class Content {
	private:
		void valid(Name, Text) throw(invalid_argument);

	protected:
		Name author;
		Text content;
		map<Name, bool> has_avaliated;
		vector<Avaliation> avaliations;

	public:
		Content();
		~Content();
		Name get_author();
	 	Text get_content();
		Avaliation get_avaliation();
	  void set(Name, Text);
	  void add_avaliation(Name, Avaliation) throw(invalid_argument);
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
	  map<Name, int> number_comments;
	  vector<Comment> comments;
	  bool comments_allowed;

	public:
	  Post(Name, Text);
	  ~Post();
	  void allow_comments();
		void disallow_comments();
	  vector<Comment> get_comments();
	  void add_comment(Comment) throw(invalid_argument);
	};


//------------------------------------------------
// Class Post
//------------------------------------------------

	class Blog {
	private:
		Name author;
		Name blog_name;
	  vector<Post> posts;

	public:
	  Blog(Name, Name);
	  ~Blog();
		Name get_author();
		Name get_blog_name();
		void set(Name, Name);
	  vector<Post> get_posts();
	  void add_post(Name, Post) throw(invalid_argument);
	};

#endif
