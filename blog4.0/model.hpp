//------------------------------------------------
// GUARD
//------------------------------------------------

#ifndef __MODEL_H_INCLUDED__
#define __MODEL_H_INCLUDED__

//------------------------------------------------
// INCLUDE
//------------------------------------------------

#include "domains.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// BLOG MODEL CLASS
//------------------------------------------------

/**
 * @class BlogModel
 *
 * @brief Defines interface with persistence.
 *
 * This class get data from the persistence module. It selects the data that will be returned. 
 *
 * @note General functions are static, a more specific one is not. All of them are private
 */
class BlogModel : public Blog {

  friend class BlogController;

  private:
    /**
     * @name    All
     * @brief   Get all Blogs
     *
     * Return all Blogs saved in persistence
     */
    static vector<Blog> all();
    /**
     * @name    From User
     * @brief   Get all Blogs that belongs to a specific User.
     *
     * Return all Blogs that belongs to a specific User saved in persistence.
     *
     * @param user The User thar has the Blogs
     *
     * @retval vector<Blog> If empty, not a single Blog from that User. Else, all the blogs that the User has.
     */ 
    static vector<Blog> from_user(User user);
};

//------------------------------------------------
// COMMENT MODEL CLASS
//------------------------------------------------

/**
 * @class CommentModel
 *
 * @brief Defines interface with persistence.
 *
 * This class get data from the persistence module. It selects the data that will be returned. 
 *
 * @note General functions are static, a more specific one is not. All of them are private
 */
class CommentModel : public Comment {

  friend class CommentController;

  private:
    /**
     * @name    All
     * @brief   Get all Comments
     *
     * Return all Comments saved in persistence
     */
    static vector<Comment> all();
    /**
     * @name    From User
     * @brief   Get all Blogs that belongs to a specific User.
     *
     * Return all Comments that belongs to a specific User saved in persistence.
     *
     * @param user The User thar has the Comments
     *
     * @retval vector<Comment> If empty, not a single Comment from that User. Else, all the Comments that the User has.
     */ 
    static vector<Comment> from_user(User user);
};

//------------------------------------------------
// CONTENT MODEL CLASS
//------------------------------------------------

/**
 * @class ContentModel
 *
 * @brief Defines interface with persistence.
 *
 * This class get data from the persistence module. It selects the data that will be returned. 
 *
 * @note General functions are static, a more specific one is not. All of them are private
 */
class ContentModel : public Content {
  friend class ContentController;
};

//------------------------------------------------
// POST MODEL CLASS
//------------------------------------------------

/**
 * @class PostModel
 *
 * @brief Defines interface with persistence.
 *
 * This class get data from the persistence module. It selects the data that will be returned. 
 *
 * @note General functions are static, a more specific one is not. All of them are private
 */
class PostModel : public Post {

  friend class PostController;

  private:
    /**
     * @name    All
     * @brief   Get all Posts
     *
     * Return all Posts saved in persistence
     */
    static vector<Post> all();
    /**
     * @name    From User
     * @brief   Get all Posts that belongs to a specific User.
     *
     * Return all Posts that belongs to a specific User saved in persistence.
     *
     * @param user The User thar has the Posts
     *
     * @retval vector<Post> If empty, not a single Post from that User. Else, all the Posts that the User has.
     */ 
    static vector<Post> from_user(User user);
};

//------------------------------------------------
// USER MODEL CLASS
//------------------------------------------------

/**
 * @class UserModel
 *
 * @brief Defines interface with persistence.
 *
 * This class get data from the persistence module. It selects the data that will be returned. 
 *
 * @note General functions are static, a more specific one is not. All of them are private
 */
class UserModel : public User {

  friend class UserController;

  private:
    /**
     * @name    All
     * @brief   Get all Users
     *
     * Return all Users saved in persistence
     */
    static vector<User> all();
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif
