//------------------------------------------------
// INCLUDE
//------------------------------------------------

#include "controller.hpp"
#include "view.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// BLOG CONTROLLER CLASS
//------------------------------------------------

void BlogController::index() throw(invalid_argument) {
	cout << "Blog Index Page" << endl;
	
	vector<Blog> blogs = Stub::get_all_blogs();// get all Blogs from model
	BlogView::index(blogs);
	// render page with all blogs
	// return to last page
}

Blog BlogController::create() throw(invalid_argument) {
	cout << "Blog Create Page" << endl;
	// render a page to fill everything
	// use the model to save in persistence
	// return the blog created and back to the last page (reloaded)
}

void BlogController::read(Blog blog) throw(invalid_argument) {
	cout << "Blog Read Page" << endl;
	// get all info from this blog from model
	// render a page all the info of blog
}

void BlogController::update(Blog blog) throw(invalid_argument) {
	cout << "Blog Update Page" << endl;
	// render a menu with information that can be edited and get the new info
	// merge the blog returned with the blog recieved in the params
	// use the model to update
	// return to last page
}

void BlogController::destroy(Blog blog) throw(invalid_argument) {
	cout << "Blog Destroy Page" << endl;
	// render confirmation and get the answer
	// if yes
		//find blog in persistence
		// delete blog from persistence
	// return to last page
}

//------------------------------------------------
// COMMENT CONTROLLER CLASS
//------------------------------------------------

//------------------------------------------------
// CONTENT CONTROLLER CLASS
//------------------------------------------------

//------------------------------------------------
// POST CONTROLLER CLASS
//------------------------------------------------

//------------------------------------------------
// USER CONTROLLER CLASS
//------------------------------------------------

