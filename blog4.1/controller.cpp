//------------------------------------------------
// INCLUDE
//------------------------------------------------

#include "controller.hpp"
#include "view.hpp"
#include "domains.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// BLOG CONTROLLER CLASS
//------------------------------------------------

void BlogController::index() throw(invalid_argument){
  // get all Blogs from model
  vector<Blog> blogs = Stub::get_all_blogs();
  // render page with all blogs
  BlogView::index_page(blogs)
}

// TODO: change name to user_blogs
void BlogController::my_blogs() throw(invalid_argument) {
  // get Blogs of the current User from model
  vector<Blog> user_blogs = Stub::get_blogs(Auth::get_current_user()); 
  // render page with all blogs
  BlogView::index_page(blogs);
}

void BlogController::edit(Blog blog, const bool master){
  // render page of editing
  // TODO: make this view return the Blog modified
  BlogView::edit_page(blog, master);
  // Save in the model
	// TODO: stub for what is in the line above
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
// TODO: change this to menu (show page is to show a individual blog)
// TODO: this should recieve an argument (The blog it will show)
void BlogController::show() {
  // render page with the info of the Blog (this should also recieve an argument)
  BlogView::show_page();
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
// TODO: change this to index
void PostController::show(Blog blog){
  // get all post in a blog
	vector<Post> posts = Stub::get_posts(blog);
  // render all posts
	PostView::show_page(posts, error);
}

//------------------------------------------------
// USER CONTROLLER CLASS
//------------------------------------------------
void UserController::create() {
  // render page of create
  // TODO: make this return something
  UserView::create_page(newName, newEmail, newPassword);
  // Send to model to save it
  // TODO: make stub for what is in the line above
}

void UserController::edit() {
}
//------------------------------------------------
// WELCOME CONTROLLER CLASS
//------------------------------------------------
void WelcomeController::home_page() {
  // render home page
  WelcomeView::home_page();
}

//------------------------------------------------
// Auth CONTROLLER CLASS
//------------------------------------------------
void AuthController::login(){
  // render page of login
  AuthView::login_page(emailIn,passwordIn);
  // If login succefull, mark in the Auth that user is logged
  // TODO: exactly what is written above

}

void AuthController::logout(){
  // render page of confirmation of logout
  AuthView::logout_page();
  // if the user intends to logout, mark as logout
  // TODO: exactly what is written above
}

