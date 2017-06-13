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

  private:
    static const int LIST = 1;
    static const int MYBLOGS = 2;
    
    static void list_blogs_page();
    static void my_blogs_page();

    
  public:
    
		/*
     * Render all blogs names
     * Receives the id of blog and a boolean (if boolean true, show all blogs)
     */
    static void index(vector<Blog>);
		/*
     * Render create blog page
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void create_page();
    /*
     * Render show page
     * Receives the id of blog and a boolean (if boolean true, show all blogs)
     */
    static void show_page();
    /*
     * Render edit profile page
     * Receives the id of blog
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void edit_page(unsigned int);
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
    void show_page(bool, unsigned int);
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
    /*
     * Render sign up page
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static void create_page();
    /*
     * Render profile page
     * Receives the id of user
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static void show_page();
    /*
     * Render edit profile page
     * Receives the id of user
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void edit_page(unsigned int);
    /*
     * Render edit profile page
     * Receives the id of user
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    void delete_page(unsigned int);
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
    static void home_page(); 
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
    static void login_page();
    /*
     * Renderiza tela de logout(so uma confimarcao pro usuario)
     * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
     */
    static void logout_page();
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif
