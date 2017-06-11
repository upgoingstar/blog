// GUARDS
#ifndef __BLOG_VIEW_H_INCLUDED__
#define __BLOG_VIEW_H_INCLUDED__

// INCLUDES
#include "../domain/_domain.hpp"
#include "../domain/name.hpp"
#include "../domain/email.hpp"

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

#endif
