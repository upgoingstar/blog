// TODO: finish the new style of documentation

//------------------------------------------------
// GUARDS
//------------------------------------------------
#ifndef VIEW_H_INCLUDED__
#define VIEW_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------
#include "domains.hpp"
#include "entity.hpp"

//------------------------------------------------
// BLOG VIEW CLASS
//------------------------------------------------

/**
 * @class BlogView
 *
 * @brief Controls interface for blog with the user of the system 
 *
 * Has all the pages of CRUD
 */
class BlogView {

  /// Permits CommentController to be aware of this class and use everything.
  friend class BlogController;
    
  public:
	/*
     * Render all blogs names
     * Receives the all the blogs
     */
    static int index_page(vector<Blog>, bool);
		/*
     * Render create blog page
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static Blog create_page() throw(invalid_argument);
    /*
     * Render edit profile page
     * Receives the id of blog
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static int show_page(Blog, bool, bool);
    /*
     * Render a page to change password
     * Receives the Comment
     * Return the updated Comment
     */
    static Blog edit_page(Blog) throw(invalid_argument);
    /*
     * Render edit profile page
     * Receives the id of blog
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static bool delete_page();
    /*
     * Render menu page
     * Receives a boolean for error
     */
    static int menu_page(bool);
};

//------------------------------------------------
// COMMENT VIEW CLASS
//------------------------------------------------

/**
 * @class CommentView
 *
 * @brief Controls interface for Comment with the user of the system 
 *
 * Has all the pages of CRUD
 */
class CommentView {

  /// Permits CommentController to be aware of this class and use everything.
  friend class CommentController;

  public:
    // TODO: Existe um espaco entre as opcoes onde virao as mensagens de erro em vermelho.
    /*
     * Render create page to serve as a sign up page
     * Return the new Comment 
     */
    static int index_page(vector<Comment>, bool) throw(invalid_argument);
    /*
     * Render create page to serve as a sign up page
     * Return the new Comment 
     */
    static Comment create_page() throw(invalid_argument);
    /*
     * Render profile page
     * Receives the Comment
     */
    static int show_page(Comment, bool);
    /*
     * Render a page to change password
     * Receives the Comment
     * Return the updated Comment
     */
    static Comment edit_page(Comment) throw(invalid_argument);
    /*
     * Render delete page to confirm the Comment intention to delete his account
     */
    static bool delete_page();
};

//------------------------------------------------
// POST VIEW CLASS
//------------------------------------------------

/**
 * @class PostView
 *
 * @brief Controls interface for Post with the user of the system 
 *
 * Has all the pages of CRUD
 */
class PostView {

  /// Permits PostController to be aware of this class and use everything.
  friend class PostController;

  public:
  	/*
     * Render create page to serve as a sign up page
     * Return the new Comment 
     */
    static int index_page(vector<Post>, bool) throw(invalid_argument);
    /*
     * Render create post page
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static Post create_page() throw(invalid_argument);
    /*
     * Render show page
     * Receives the id of post and a boolean (if boolean true, show all posts)
     */
    static int show_page(Post, bool);
    /*
     * Render edit profile page
     * Receives the id of post
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static Post edit_page(Post) throw(invalid_argument);
    /*
     * Render edit profile page
     * Receives the id of post
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static bool delete_page();
};

//------------------------------------------------
// USER VIEW CLASS
//------------------------------------------------

/**
 * @class UserView
 *
 * @brief Controls interface for User with the user of the system 
 *
 * Has all the pages of CRUD
 */
class UserView {

  /// Permits UserController to be aware of this class and use everything.
  friend class UserController;

  public:
    // TODO: Existe um espaco entre as opcoes onde virao as mensagens de erro em vermelho.
    /*
     * Render create page to serve as a sign up page
     * Return the new user 
     */
    static User create_page() throw(invalid_argument);
    /*
     * Render profile page
     * Receives the user
     */
    static int show_page(User, bool);
    /*
     * Render a page to change password
     * Receives the user
     * Return the updated user
     */
    static User edit_page(User) throw(invalid_argument);
    /*
     * Render delete page to confirm the user intention to delete his account
     */
    static bool delete_page();
};

//------------------------------------------------
// WELCOME VIEW CLASS
//------------------------------------------------

/**
 * @class WelcomeView
 *
 * @brief Controles the home page
 *
 * Includes Home Page with menu for the program
 */
class WelcomeView {
  
  /// Permits WelcomeController to be aware of this class and use everything.
  friend class WelcomeController;
  	
  public:
    /*
     * Render home page
     */
    static int home_page(bool); 
};

//------------------------------------------------
// AUTH VIEW CLASS
//------------------------------------------------

/**
 * @class AuthView
 *
 * @brief Controls the interface of authentication
 *
 * Includes Login Page and Logout Page
 */
class AuthView : public Auth {

  /// Permits AuthController to be aware of this class and use everything.
  friend class AuthController;

  public:
    // TODO: Existe um espaco entre as opcoes onde virao as mensagens de erro em vermelho.
    /*
     * Renderiza tela de login
     */ 
    static void login_page(Email&, Password&);
    static void finish_login_page(bool);
    /*
     * Renderiza tela de logout (so uma confimarcao pro usuario)
     */
    static int logout_page();
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif
