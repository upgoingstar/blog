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
* A view class that controls interface with blog
*/
class BlogView {
private:
	/*
	 * Render field page
	 * Just print 'Preencha seu nome:' and return
	 */
	Name field_name_page();
	/*
	 * Render field page
	 * Just print 'Preencha seu email:' and return
	 */
	Email field_email_page();
	
public:
	/*
	 * Render create blog page
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	void create_page();
	/*
	 * Render show page
	 * Receives the id of blog and a boolean (if boolean true, show all blogs)
	 */
	void show_page(bool, unsigned int);
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
* A view class that controls interface with comment
*/
class CommentView {
private:
	/*
	 * Render field page
	 * Just print 'O que vc está pensando:' and return
	 */
	Content field_content_page();

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
* A view class that controls interface with post
*/
class PostView {
private:
	/*
	 * Render field page
	 * Just print 'O que vc está pensando:' and return
	 */
	Content field_content_page();

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
* A view class that controls interface with user
*/
class UserView {
private:
	/*
	 * Render field page
	 * Just print 'Preencha seu nome:' and return
	 */
	Name field_name_page();
	/*
	 * Render field page
	 * Just print 'Preencha seu email:' and return
	 */
	Email field_email_page();
	/*
	 * Render field page
	 * Just print 'Preencha sua senha:' and return
	 */
	Password field_password_page();

public:
	/*
	 * Render sign up page
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	void create_page();
	/*
	 * Render profile page
	 * Receives the id of user
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	void show_page(bool, unsigned int);
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
* A view class that show home page
*/
class WelcomeView {]
private:
	static const int LOGIN = 1;
	static const int LOGOUT = 1;
	static const int REGISTER = 2;
	static const int ACCOUNT = 2;
	static const int LISTBLOGS = 3;
	static const int EXIT = 4;
	
	const static int SIM = 1;
	const static int NAO = 2;
public:
	/*
	 * Render home page
	 */
 	static void home_page(); 


};

//------------------------------------------------
// AUTH VIEW CLASS
//------------------------------------------------

class AuthView {
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
