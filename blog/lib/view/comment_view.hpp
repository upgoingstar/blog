// GUARDS
#ifndef __COMMENT_VIEW_H_INCLUDED__
#define __COMMENT_VIEW_H_INCLUDED__

// INCLUDES
#include "../domain/_domain.hpp"
#include "../entity/content.hpp"

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

#endif
