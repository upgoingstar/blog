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

  friend class BlogController;
    
  public:
		/*
     * Render all blogs names
     * Receives the id of blog and a boolean (if boolean true, show all blogs)
     */
    static int index_page(vector<Blog>, bool);
		/*
     * Render create blog page
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void create_page();
    /*
     * Render show page
     * Receives the id of blog and a boolean (if boolean true, show all blogs)
     */
    static int show_page(bool);
    /*
     * Render edit profile page
     * Receives the id of blog
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static int edit_page(Blog, bool, bool);
    /*
     * Render edit profile page
     * Receives the id of blog
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void delete_page(unsigned int);
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

  friend class CommentController;

  public:
    /*
     * Render create comment page
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void create_page();
    /*
     * Render show page
     * Receives the id of comment and a boolean (if boolean true, show all comments)
     */
    void show_page(bool, unsigned int);
    /*
     * Render edit profile page
     * Receives the id of comment
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void edit_page(unsigned int);
    /*
     * Render edit profile page
     * Receives the id of comment
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void delete_page(unsigned int);
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

  friend class PostController;

  public:
    /*
     * Render create post page
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void create_page();
    /*
     * Render show page
     * Receives the id of post and a boolean (if boolean true, show all posts)
     */
    static int show_page(vector<Post>, bool);
    /*
     * Render edit profile page
     * Receives the id of post
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void edit_page(unsigned int);
    /*
     * Render edit profile page
     * Receives the id of post
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void delete_page(unsigned int);
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

  friend class UserController;

  public:
    // TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
    /*
     * Render sign up page
     */
    static void create_page(string&, string&, string&);
    /*
     * Complement of create_page
     */
    static void finish_create_page(bool, bool, bool, bool, bool);
    /*
     * Render profile page
     * Receives the user
     */
    static void show_page();
    /*
     * Render a page to change password
     * Receives the user
     */
    void edit_page(unsigned int);
    /*
     * Render delete page
     * Receives the id of user?
     */
    void delete_page();
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
// TODO: put all this static const int inside the function where it is needed.
class WelcomeView {	
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
    /*
     * Renderiza tela de login
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */ 
    static void login_page(string&, string&);
    static void finish_login_page(bool);
    /*
     * Renderiza tela de logout(so uma confimarcao pro usuario)
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static int logout_page();
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif
