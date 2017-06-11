// GUARDS
#ifndef __USER_VIEW_H_INCLUDED__
#define __USER_VIEW_H_INCLUDED__

// INCLUDES
#include "../domain/_domain.hpp"
#include "../domain/name.hpp"
#include "../domain/email.hpp"
#include "../domain/password.hpp"

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

#endif
