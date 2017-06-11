// GUARDS
#ifndef __BLOG_CONTROLLER_H_INCLUDED__
#define __BLOG_CONTROLLER_H_INCLUDED__

// INCLUDES
#include "../domain/_domain.hpp"
#include "../entity/blog.hpp"
#include <bits/stdc++.h>
using namespace std;

/**
* A class that controls Blog
* Defines CRUD
*/
class BlogController : public Blog {
private:
	/*
	 * Coloca todas os Blogs em alguma variável visivel a BlogView.index() para renderizar a página
	 */
	vector<Blog> index();
	/*
	 * Chama BlogView.create(Blog()), usuário preenche as informações e ele pega devolta e returna o Blog
	 */
	Blog         create()  throw(invalid_argument);
	/*
	 * Chama BlogView.edit(Blog) como o Blog q recebeu, usuário preenche as informações e ele pega devolta envia para o update que válida e returna o Blog editado
	 */
	Blog         edit(Blog)    throw(invalid_argument);
	/*
	 * Chama BlogView.update() para adicionar um novo Post
	 */
	Blog         update()  throw(invalid_argument);
	/*
	 * Recebe um objeto Blog e manda o BlogModel destruir
	 */
	void         destroy(Blog) throw(invalid_argument);
};

#endif
