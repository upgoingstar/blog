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
	void show_page(bool, int);
	/*
	 * Render edit profile page
	 * Receives the id of post
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	void edit_page(int);
	/*
	 * Render edit profile page
	 * Receives the id of post
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	void delete_page(int);
};