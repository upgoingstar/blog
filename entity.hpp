// TODO: finish the new style of documentation (only methods set missing)
// TODO: implement the validation of blog
// TODO: make Auth::logout set currentUser to an empty User

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
     * @name    Valid
     * @brief   Validate the User
     *
     * Validate User by verifying if the name, email or password are empty. If any of them are empty, it will not create.
     */
    void valid(Name, Email, Password) throw(invalid_argument);

  public:
    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    User();

    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~User();

    /**
     * @name    Get Name
     * @brief   Get the name of the user
     *
     * Get the name of the user if it is not empty.
     *
     * @return Name The name of the user
     */
    Name get_name() throw(invalid_argument);

    /**
   * A public method
   * Modify the value of the Name, Email and Password of this User.
   */
    void set(Name, Email, Password);

  /**
     * Modify the value of the Password of this User.
     */
    void set_password(Password);
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
    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    Blog();

    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~Blog();

    /**
     * @name    Get Author
     * @brief   Get the name of the author of the blog
     *
     * Get the name of the author of the blog if it is not empty.
     *
     * @return Name The name the author of the blog
     */
    Name get_author() throw(invalid_argument);

    /**
     * @name    Get Name
     * @brief   Get the name of the blog
     *
     * Get the name of the blog if it is not empty.
     *
     * @return Name The name of the blog
     */
    Name get_name() throw(invalid_argument);

    /**
     * @name    Get Posts
     * @brief   Get the posts of the blog
     *
     * Get the posts of the blog if it is not empty.
     *
     * @return vector<Post> the posts of the blog
     */
    vector<Post> get_posts() throw(invalid_argument);

     /**
   * A public method
   * Modify the Name of the author and the Name of the blog.
   */
    void set(Name, Name) throw(invalid_argument);

   /**
   * A public method
     * Add a new post to this blog. Does not add a post of a person different than the one who created the blog be added.
   */
    void set_name(Name) throw(invalid_argument);
    
    /**
   * A public method
     * Add a new post to this blog. Does not add a post of a person different than the one who created the blog be added.
   */
    void set_post(Post) throw(invalid_argument);
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
class Post {
  private:
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
   
    /**
     * @name    Valid
     * @brief   Validate the Post
     *
     * Validate Post by verifying if the text is empty. If it is, it will not create.
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
    
    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    Post();

    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~Post();

    /**
     * @name    Get Author
     * @brief   Get the name of the author of the post
     *
     * Get the name of the author of the post if it is not empty.
     *
     * @return Name The name the author of the post
     */
    Name get_author();

    /**
     * @name    Get Content
     * @brief   Get the content of the post
     *
     * Get the content of the post if it is not empty.
     *
     * @return Text The content of the post
     */
    Text get_content();

    /**
     * @name    Get Avaliation
     * @brief   Get the avaliation of the post
     *
     * Get the avaliation of the post if it is not empty.
     *
     * @return Avaliation The avaliation of the post
     */
    Avaliation get_avaliation();

    /**
     * @name    Get Comments
     * @brief   Get the comments of the post
     *
     * Get the comments of the post if it is not empty.
     *
     * @return vector<Comment> the comments of the post
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
     * @name    Allow Comments
     * @brief   Allow comments int this post
     *
     * Allow comments in this post
     */
    void allow_comments();

    /**
     * @name    Disallow Comments
     * @brief   Disallow comments int this post
     *
     * Disallow comments in this post. It will clear all comments already made.
     */
    void disallow_comments();
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
  private:
    /// The author of the Comment
    Name author;

    /// The content of the Comment
    Text content;

    /// The name of every User that avaliated
    map<Name, bool> has_avaliated;

    /// All the avaliations given to this content
    vector<Avaliation> avaliations;

    /**
     * @name    Valid
     * @brief   Validate the Comment
     *
     * Validate Comment by verifying if the text is empty. If it is, it will not create.
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
    
    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    Comment();

    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~Comment();

    /**
     * @name    Get Author
     * @brief   Get the name of the author of the comment
     *
     * Get the name of the author of the comment if it is not empty.
     *
     * @return Name The name the author of the comment
     */
    Name get_author();

    /**
     * @name    Get Content
     * @brief   Get the content of the post
     *
     * Get the content of the post if it is not empty.
     *
     * @return Text The content of the post
     */
    Text get_content();

    /**
     * @name    Get Avaliation
     * @brief   Get the avaliation of the comment
     *
     * Get the avaliation of the comment if it is not empty.
     *
     * @return Avaliation The avaliation of the comment
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
    
    /// If there is or not a user logged
    static bool userLogged;
    
    /// The current user logged
    static User currentUser;

    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    Auth();

    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~Auth();
    
  public:

    /**
     * @name    User Logged
     * @brief   Can tell if the user is logged
     *
     * See if there is a user logged.
     *
     * @return bool If the user is logged return TRUE, else FALSE.
     */
    static bool user_logged();
    
    /**
     * @name    Get Current User
     * @brief   Get the current User
     *
     * If there is a user logged, return the current user
     *
     * @return bool If the user is logged return TRUE, else FALSE.
     */
    static User get_current_user() throw(invalid_argument);
    
    /**
     * @name    Login
     * @brief   Login the current user
     *
     * Make atribute userLogged true and currentUser equal the user received
     *
     * @param user The user to log in
     */
    static void login(User);
    
    /**
     * @name    Login
     * @brief   Login the current user
     *
     * Make atribute userLogged false and currentUser equal a empty User
     *
     * @param user The user to log in
     */
    static void logout();
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif

