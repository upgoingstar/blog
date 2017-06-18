// TODO: finish the new style of documentation

//------------------------------------------------
// GUARDS
//------------------------------------------------

#ifndef __ENTITY_H_INCLUDED__
#define __ENTITY_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include "domains.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// USER CLASS
//------------------------------------------------

/**
 * @class User
 *
 * @brief Defines the User
 *
 * Defines what information User has and how you can access it.
 */
class User{
  private:
    /// The name of the User
    Name name;

    /// The password of the User
    Password password;

    /// The email of the User
    Email email;

    /// If the current user is anonymous
    bool anonymous;

    /**
     * A private method.
     * Validate User by verifying if any of the arguments (name, email and password) already exists, so that there are no two users with the same name or email or password.
     */
    void valid(Name, Email, Password) throw(invalid_argument);

  public:
    /// Create a User
    User();

    /// Destroy a User
    ~User();

    /**
   * A public method
   * Modify the value of the Name, Email and Password of this User.
   */
    void set(Name, Email, Password);

	/**
     * Modify the value of the Password of this User.
     */
    void set_password(Password);

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
// COMMENT CLASS
//------------------------------------------------

/**
 * @class Comment
 *
 * @brief Defines how a Comment should be.
 *
 * Inherit of class Content. Defines what information a Comment has and how you can access it.
 */
class Comment {
  protected:
    /// The author of the Comment
    Name author;

    /// The content of the Comment
    Text content;

    /// The name of every User that avaliated
    map<Name, bool> has_avaliated;

    /// All the avaliations given to this content
    vector<Avaliation> avaliations;

  private:
  	/**
     * A private method
     * Checks if any of the value is empty.
     */
    void valid(Text) throw(invalid_argument);
    
    /**
     * @name    Empty
     * @brief   Warn if the Name or Text is empty.
     *
     * @retval TRUE At least one of the strings is empty
     * @retval FALSE None of the strings is not empty
     */
    bool empty();

  public:
    /// Create a Comment
    Comment();

    /// Destroy a Comment
    ~Comment();

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
    void set_author(Name);

	/**
     * A public method
     * It receives the name of the author of the content and the content and valid them.
     */
    void set_content(Text);

    /**
     * A public method.
     * Add an avaliation, making sure that no user do more than one avaliation.
     * It receives a the name of the current user and the avaliation.
     */
    void set_avaliation(Name, Avaliation) throw(invalid_argument);
};

//------------------------------------------------
// POST CLASS
//------------------------------------------------

/**
 * @class Post
 *
 * @brief Defines how a Post should be.
 *
 * Inherit of class Content. Defines what information a Post has and how you can access it.
 */
// TODO: validate if the Content is empty.
class Post {
  protected:
    /// The author of the Post
    Name author;

    /// The content of the Post
    Text content;

    /// The name of every User that avaliated
    map<Name, bool> has_avaliated;

    /// All the avaliations given to this content
    vector<Avaliation> avaliations;
      
    /// Maximum number of times that a person can comment.
    static const int comments_limit = 5;

    /// The name of every User that has commented
    map<Name, int> number_comments;

    /// All the Comments made for this Post
    vector<Comment> comments;

    /// If comments are allowed
    bool comments_allowed;
    
  private:    
	/**
	 * A private method
	 * Checks if any of the value is empty.
	 */
    void valid(Text) throw(invalid_argument);	
    
    /**
     * @name    Empty
     * @brief   Warn if the Name or Text is empty.
     *
     * @retval TRUE At least one of the strings is empty
     * @retval FALSE None of the strings is not empty
     */
    bool empty();

  public:
    /// Create a Post
    Post();

    /// Destroy a Post
    ~Post();

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
     * @return all the comments.
     */
    vector<Comment> get_comments();

    /**
     * A public method
     * It receives the name of the author of the content and the content and valid them.
     */
    void set_author(Name);

	/**
     * A public method
     * It receives the name of the author of the content and the content and valid them.
     */
    void set_content(Text);

    /**
     * A public method.
     * Add an avaliation, making sure that no user do more than one avaliation.
     * It receives a the name of the current user and the avaliation.
     */
    void set_avaliation(Name, Avaliation) throw(invalid_argument);

	/**
     * A public method
     * Add a comment if possible (no user can comment more than 5 times and the post has to autorize comments).
     */
    void set_comment(Comment) throw(invalid_argument);

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
};

//------------------------------------------------
// BLOG CLASS
//------------------------------------------------

/**
 * @class Blog
 *
 * @brief Defines how a Blog should be.
 *
 * Inherit of class Domain. Defines what information a Blog has and how you can access it.
 *
 * @note The size is small for some reasons.
 */
class Blog {
  private:
    /// The author of the Blog
    Name author;

    /// The name of the Blog
    Name blog_name;

    /// All Posts made in this Blog
    vector<Post> posts;

  public:
    /// Create a Blog
    Blog();

    /// Destroy a Blog
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
// AUTH CLASS
//------------------------------------------------

/**
 * @class Auth
 *
 * @brief Defines info needed in authenication
 *
 * Keeps informaition of the current user and can tell if someone is logged or not.
 */
class Auth {
	private:
		static bool userLogged;
		static User currentUser;
		
	public:
		static bool user_logged();
		static User get_current_user() throw(invalid_argument);
		static void login(User);
	    static void logout();
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif

