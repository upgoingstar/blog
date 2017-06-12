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
// USER CLASS
//------------------------------------------------

class User{
private:
  /**
 * A private variable of class Name.
 * Keeps the name of the User.
 */
  Name name;

  /**
 * A private variable of class Password.
 * Keeps the password of the User.
 */
  Password password;

  /**
   * A private variable of class Email.
   * Keeps the email of the User.
   */
  Email email;

  /**
 * A private bolean variable.
 * Keeps the name of the User.
 */
  bool anonymous;

  /**
   * A private method.
   * Validate User by verifying if any of the arguments (name, email and password) already exists, so that there are no two users with the same name or email or password.
   */
  void valid(Name, Email,Password) throw(invalid_argument);

public:
  /**
 * A public constructor.
 */
  User();

  /**
 * A public destructor.
 */
  ~User();

  /**
 * A public method
 * Modify the value of the Name, Email and Password of this User.
 */
  void set(Name, Email, Password);

  /**
 * A public method
 * @return Value of the Name of the User.
 */
  Name get_name() throw(invalid_argument);

  /**
 * A public method.
   * Check if the email and password given correspond to a real User.
   * TODO: Need refactoring!
 */
  void check_user(Email, Password) throw(invalid_argument);
};

//------------------------------------------------
// CONTENT CLASS
//------------------------------------------------

class Content {
private:
  /**
 * A private method
 * Checks if any of the value is empty.
 */
  void valid(Name, Text) throw(invalid_argument);

protected:
  /**
 * A protected variable of class Name.
 * Keeps the name of the author of the content.
 */
  Name author;

  /**
 * A protected variable of class Text.
 * Keeps the content.
 */
  Text content;

  /**
 * A protected variable of class Map.
 * Keeps the name that everyone that has already avaliated.
 */
  map<Name, bool> has_avaliated;

  /**
 * A protected variable of class Vector.
 * Keeps the avaliations.
 */
  vector<Avaliation> avaliations;

public:
  /**
 * A public constructor.
 */
  Content();

  /**
 * A public destructor.
 */
  ~Content();

  /**
 * A public method
 * @return Value of the author of the content.
 */
  Name get_author();

  /**
 * A public method
 * @return Value of the content.
 */
  Text get_content();

  /**
 * A public method
 * @return The arithmetic mean of all avaliations given the to content in question.
 */
  Avaliation get_avaliation();

  /**
 * A public method
 * It receives the name of the author of the content and the content and valid them.
 */
  void set(Name, Text);

  /**
   * A public method.
   * Add an avaliation, making sure that no user do more than one avaliation.
   * It receives a the name of the current user and the avaliation.
   */
  void add_avaliation(Name, Avaliation) throw(invalid_argument);
};

//------------------------------------------------
// COMMENT CLASS
//------------------------------------------------

class Comment : public Content {
public:
  /**
 * A public constructor.
 */
  Comment(Name,Text);

  /**
 * A public destructor.
 */
  ~Comment();
};

//------------------------------------------------
// POST CLASS
//------------------------------------------------

class Post : public Content {
private:
  /**
 * A private static constant integer variable.
 * Limits the number of times that a person can comment.
 */
  static const int comments_limit = 5;

  /**
 * A private variable of class Map.
 * Keeps the name that everyone that has already posted.
 */
  map<Name, int> number_comments;

  /**
 * A private variable of class Vector.
 * Keep all the comments made for this post.
 */
  vector<Comment> comments;

  /**
 * A private boolean variable.
 * Defines if comments are allowed.
 */
  bool comments_allowed;

public:
  /**
 * A public constructor.
 */
  Post(Name, Text);

  /**
 * A public destructor.
 */
  ~Post();
  /**
 * A public method
 * Allow comments to be made by other users.
 */
  void allow_comments();

  /**
 * A public method
 * Disallow comments. This excludes all current comments.
 */
  void disallow_comments();

  /**
 * A public method
 * @return all the comments.
 */
  vector<Comment> get_comments();

  /**
 * A public method
 * Add a comment if possible (no user can comment more than 5 times and the post has to autorize comments).
 */
  void add_comment(Comment) throw(invalid_argument);
};

//------------------------------------------------
// BLOG CLASS
//------------------------------------------------

class Blog {
private:
  /**
 * A private variable of class Name.
 * Keeps the name of the author.
 */
  Name author;

  /**
 * A private variable of class Name.
 * Keeps the name of the blog.
 */
  Name blog_name;

  /**
 * A private variable of class Name.
 * Keeps all the posts.
 */
  vector<Post> posts;

public:
  /**
 * A public constructor.
 */
  Blog();

  /**
 * A public destructor.
 */
  ~Blog();

  /**
 * A public method
 * Modify the Name of the author and the Name of the blog.
 */
  void set(Name, Name) throw(invalid_argument);

  /**
 * A public method
 * @return The name of the author of the blog.
 */
  Name get_author();

  /**
 * A public method
 * @return The name of the blog.
 */
  Name get_blog_name();

  /**
 * A public method
 * @return All the posts in this blog.
 */
  vector<Post> get_posts();

  /**
 * A public method
   * Add a new post to this blog. Does not add a post of a person different than the one who created the blog be added.
 */
  void add_post(Post) throw(invalid_argument);
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif

