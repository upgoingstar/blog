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
* A class that controls Blog
* Defines persistence methods
*/
class BlogModel : public Blog {
  friend class BlogController;
};

//------------------------------------------------
// COMMENT MODEL CLASS
//------------------------------------------------

/**
* A class that controls Comment
* Defines persistence methods
*/
class CommentModel : public Comment {
  friend class CommentController;
};

//------------------------------------------------
// CONTENT MODEL CLASS
//------------------------------------------------

/**
* A class that controls Content
* Defines persistence methods
*/
class ContentModel : public Content {
  friend class ContentController;
};

//------------------------------------------------
// POST MODEL CLASS
//------------------------------------------------

/**
* A class that controls Post
* Defines persistence methods
*/
class PostModel : public Post {
  friend class PostController;
};

//------------------------------------------------
// USER MODEL CLASS
//------------------------------------------------

/**
* A class that controls User
* Defines persistence methods
*/
class UserModel : public User {
  friend class UserController;
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif
