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
     * @name    Index
     * @brief   Show to User all Blogs.
     *
     * Render a page that show all Blogs. If there is no Blogs to show, it will tell the current user that there is no Blogs
     */
    static void index() throw(invalid_argument);
  
    static void user_blogs() throw(invalid_argument);
      
    static void edit(Blog, const bool);
    /**
     * @name    Create
     * @brief   Create a new Blog
     *
     * Render a page to fill the information needed to create a new Blog and then save in the persistence.
     *
     * @return The blog created
     */
    static Blog create() throw(invalid_argument);

    /**
     * @name    Create
     * @brief   Show a specific Blog
     *
     * Render a page with the Blog we want to read.
     *
     * @param blog The Blog that we want to read.
     */
    static void read(Blog blog) throw(invalid_argument);

    /**
     * @name    Update
     * @brief   Permit edit a Blog
     *
     * Render a page with the information it can edit.
     *
     * @param blog The Blog that we want to update.
     */
    static void update(Blog blog) throw(invalid_argument);

    /**
     * @name    Destroy
     * @brief   Delete a Blog
     *
     * Render a page of confirmation for erasing from persistence a specif Blog.
     *
     * @param blog The Blog that we want to delete.
     */
    static void destroy(Blog blog) throw(invalid_argument);
  
  public:
    static void show();
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
  
  public:
  	
  	static void create();
  	
	static void show(Comment);
	
	static void edit(Comment);
	
	static void destroy(Comment);
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
  
  public:
    static void show(Blog);
};

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
  
  public:
  	
  	static void create();
  	
	static void show();
	
	static void edit();
	
	static void destroy();
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
  
  public:
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
  
  public:
    static void login();
    static void logout();
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif
