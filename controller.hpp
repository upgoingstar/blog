//------------------------------------------------
// GUARD
//------------------------------------------------

#ifndef __CONTROLLER_H_INCLUDED__
#define __CONTROLLER_H_INCLUDED__

//------------------------------------------------
// INCLUDE
//------------------------------------------------

#include "domains.hpp"
#include "entity.hpp"
#include "stubs.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// USER CONTROLLER CLASS
//------------------------------------------------

/**
 * @class UserController
 *
 * @brief Defines the CRUD (Create, Read, Update, Destroy)
 *
 * This class defines the logic necessary for CRUD to work properly in the system.
 *
 * @note It is aware of both UserView and UserModel (but neither of them are aware of UserController).
 */
class UserController : public User {

  /// Permits UserView to be aware of this class and use everything.
  friend class UserView;
  
  private:

    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    UserController();
    
    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~UserController();
    
    /**
     * @name    Edit
     * @brief   Controls the logic of editing a user
     *
     * Render a page to fill the information needed to update the user if you are the owner of the user
     * @param user The user that we want to edit.
     */
    static void edit();
  
    /**
     * @name    Destroy
     * @brief   Controls the logic of deleting a user
     *
     * Render a page of confirmation to confirm if that is what the owner wants. Then erase from persistence this specific user.
     *
     * @param user The user that the owner wants to delete.
     * 
     * @return bool If the user was deleted or not
     */
    static bool destroy(User);

  public:

    /**
     * @name    Create
     * @brief   Controls the logic for creating a new User
     *
     * Render a page to fill the information needed to create a new User and then save in the persistence.
     */
    static void create();
    
    /**
     * @name    Show
     * @brief   Controls the logic of showing the current user
     *
     * Render a page with information of the current user. This page is used as a profile page.
     */
    static void show();
};

//------------------------------------------------
// BLOG CONTROLLER CLASS
//------------------------------------------------

/**
 * @class BlogController
 *
 * @brief Defines the CRUD (Create, Read, Update, Destroy)
 *
 * This class defines the logic necessary for CRUD to work properly in the system.
 *
 * @note It is aware of both BlogView and BlogModel (but neither of them are aware of BlogController).
 */
class BlogController : public Blog {

  /// Permits BlogView to be aware of this class and use everything.
  friend class BlogView;
  
  private:

    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    BlogController();

    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~BlogController();

    /**
     * @name    Index
     * @brief   Controls the logic of showing all blogs
     *
     * Render a page that show all blogs. If there is no blogs to show, it will tell the current user that there are no blogs.
     */
    static void index() throw(invalid_argument);
  
    /**
     * @name    User Blogs
     * @brief   Controls the logic of showing to the current user all blogs he created.
     *
     * Render a page that show all blogs current user created. If there is no blogs to show, it will tell the current user that there is no Blogs
     */
    static void user_blogs() throw(invalid_argument);
      
    /**
     * @name    Create
     * @brief   Controls the logic for creating a new Blog
     *
     * Render a page to fill the information needed to create a new Blog and then save in the persistence.
     */
    static void create() throw(invalid_argument);
    
    /**
     * @name    Show
     * @brief   Controls the logic of showing a Blog
     *
     * Render a page with information of a blog. This page is used to see a blog.
     * 
     * @param blog This blog this controller will show
     */
    static void show(Blog);
    
    /**
     * @name    Edit
     * @brief   Controls the logic of editing a blog
     *
     * Render a page to fill the information needed to update the blog if you are the owner of the blog
     * @param blog The blog that we want to edit.
     */
    static void edit(Blog);

    /**
     * @name    Destroy
     * @brief   Controls the logic of deleting a blog
     *
     * Render a page of confirmation to confirm if that is what the owner wants. Then erase from persistence this specific blog.
     *
     * @param blog The blog that the owner wants to delete.
     * 
     * @return bool If the blog was deleted or not
     */
    static bool destroy(Blog) throw(invalid_argument);

  public:

    /**
     * @name    Menu
     * @brief   Controls the logic of a menu for blogs
     *
     * Render a page of menu for blogs
     */
    static void menu();
};

//------------------------------------------------
// POST CONTROLLER CLASS
//------------------------------------------------

/**
 * @class PostController
 *
 * @brief Defines the CRUD (Create, Read, Update, Destroy)
 *
 * This class defines the logic necessary for CRUD to work properly in the system.
 *
 * @note It is aware of both PostView and PostModel (but neither of them are aware of PostController).
 */
class PostController : public Post {
  
  /// Permits PostView to be aware of this class and use everything.
  friend class PostView;
  
  private:

    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    PostController();
    
    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~PostController();

    /**
     * @name    Show
     * @brief   Controls the logic of showing a Post
     *
     * Render a page with information of a post. This page is used to see a post.
     * 
     * @param post This post this controller will show
     */
    static void show(Post);
  
    /**
     * @name    Edit
     * @brief   Controls the logic of editing a post
     *
     * Render a page to fill the information needed to update the post if you are the owner of the post
     * @param post The post that we want to edit.
     */
    static void edit(Post);
  
    /**
     * @name    Destroy
     * @brief   Controls the logic of deleting a post
     *
     * Render a page of confirmation to confirm if that is what the owner wants. Then erase from persistence this specific post.
     *
     * @param post The post that the owner wants to delete.
     * 
     * @return bool If the post was deleted or not
     */
    static bool destroy(Post);

  public:

    /**
     * @name    Index
     * @brief   Controls the logic of showing all posts
     *
     * Render a page that show all posts. If there is no posts to show, it will tell the current user that there are no blogs.
     *
     * @param blog The blog from where to extract the posts.
     */
    static void index(Blog);
    
    /**
     * @name    Create
     * @brief   Controls the logic for creating a new Post
     *
     * Render a page to fill the information needed to create a new Post and then save in the persistence.
     */
    static void create();
};


//------------------------------------------------
// COMMENT CONTROLLER CLASS
//------------------------------------------------

/**
 * @class CommentController
 *
 * @brief Defines the CRUD (Create, Read, Update, Destroy)
 *
 * This class defines the logic necessary for CRUD to work properly in the system.
 *
 * @note It is aware of both CommentView and CommentModel (but neither of them are aware of CommentController).
 */
class CommentController : public Comment {
  
  /// Permits CommentView to be aware of this class and use everything.
  friend class CommentView;
  
  private:

    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    CommentController();

    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~CommentController();

    /**
     * @name    Show
     * @brief   Controls the logic of showing a comment
     *
     * Render a page with information of a comment. This page is used to see a comment.
     * 
     * @param comment This comment this controller will show
     */
    static void show(Comment);
    
    /**
     * @name    Edit
     * @brief   Controls the logic of editing a comment
     *
     * Render a page to fill the information needed to update the comment if you are the owner of the comment
     * @param comment The comment that we want to edit.
     */
    static void edit(Comment);
    
    /**
     * @name    Destroy
     * @brief   Controls the logic of deleting a comment
     *
     * Render a page of confirmation to confirm if that is what the owner wants. Then erase from persistence this specific comment.
     *
     * @param comment The comment that the owner wants to delete.
     * 
     * @return bool If the comment was deleted of not
     */
    static bool destroy(Comment);

  public:

    /**
     * @name    Index
     * @brief   Controls the logic of showing all comments
     *
     * Render a page that show all comments. If there is no comments to show, it will tell the current user that there are no blogs.
     *
     * @param post The post from where to extract the comments.
     */
    static void index(Post);
    
    /**
     * @name    Create
     * @brief   Controls the logic for creating a new Comment
     *
     * Render a page to fill the information needed to create a new Comment and then save in the persistence.
     */
    static void create();
};

//------------------------------------------------
// WELCOME CONTROLLER CLASS
//------------------------------------------------

/**
 * @class WelcomeController
 *
 * @brief Authenticate the User
 *
 * This class is responsible for verifying if the User exists.
 *
 * @note It is aware of both AuthView and AuthModel (but neither of them are aware of AuthController).
 */
class WelcomeController {

  /// Permits WelcomeView to be aware of this class and use everything.
  friend class WelcomeView;
  
  private:

    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    WelcomeController();

    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~WelcomeController();

  public:

    /**
     * @name    Home Page
     * @brief   Controls the logic of the home page
     *
     * Render the home page of the application that changes if the user is logged and take the user to different parts of the application.
     */
    static void home_page();
};

//------------------------------------------------
// AUTH CONTROLLER CLASS
//------------------------------------------------

/**
 * @class AuthController
 *
 * @brief Authenticate the User
 *
 * This class is responsible for verifying if the User exists.
 *
 * @note It is aware of both AuthView and AuthModel (but neither of them are aware of AuthController).
 */
class AuthController : public Auth {

  /// Permits AuthView to be aware of this class and use everything.
  friend class AuthView;
  
  private:

    /**
     * @name    Constructor
     * @brief   Inicialize an object of the Class
     */
    AuthController();

    /**
     * @name    Destructor
     * @brief   Destroy an object of the Class
     */
    ~AuthController();

  public:

    /**
     * @name    Login
     * @brief   Control the logic of login
     *
     * Render the page of login and verify if the user typed is real. If it is, the user is now logged.
     */
    static void login();

    /**
     * @name    Logout
     * @brief   Control the logic of logout
     *
     * Render the page of logout to verify if the current user really wants to logout. If the current user really wants it, the user is logged out.
     */
    static void logout();
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif
