/**
* A view class that controls interface with blog
*/
class BlogView {
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
	void show_page(bool, int);
	/*
	 * Render edit profile page
	 * Receives the id of blog
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	void edit_page(int);
	/*
	 * Render edit profile page
	 * Receives the id of blog
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	void delete_page(int);
};