//------------------------------------------------
// INCLUDE
//------------------------------------------------

#include "controller.hpp"
#include "view.hpp"
#include "entity.hpp"
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
  BlogView::index_page(blogs);
}

void BlogController::user_blogs() throw(invalid_argument) {
  // get Blogs of the current User from model
  vector<Blog> blogs = Stub::get_blogs(Auth::get_current_user()); 
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
	try {
		Blog blog = BlogView::create_page();						// render create page and receive a new blog
		// BlogModel::save(user);									// Send to model to save it             // TODO: put a stub in here (later implement)
	} catch(invalid_argument erro) {}
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

// TODO: add to the Post an id to identify to which blog is he refering to
// TODO: add to the Comment an id to identify to which post is he refering to

void CommentController::create() {
	try {
	Comment comment = CommentView::create_page();						// render create page and receive a new comment
	// CommentModel::save(Comment);									// Send to model to save it             // TODO: put a stub in here (later implement)
	} catch(invalid_argument erro) {}
}

void CommentController::show(Comment comment) {
	CommentView::show_page(comment);									// render show page
}

void CommentController::edit(Comment comment) {
	try{
		comment = CommentView::edit_page(comment);							// render edit page and get new comment
		// CommentModel::update(comment);									// safe using the model                 // TODO: put a stub in here (later implement)	
	} catch(invalid_argument erro) {}
}

void CommentController::destroy(Comment comment) {
 	bool decision = CommentView::delete_page();                    // render delete page and get confirmation
	if(decision == true) {
		// CommentModel::delete(comment)								// safe using the model                 // TODO: put a stub in here (later implement)	
	}
}

//------------------------------------------------
// POST CONTROLLER CLASS
//------------------------------------------------
// TODO: change this to index
void PostController::show(Blog blog){
  // get all post in a blog
  vector<Post> posts = Stub::get_posts(blog);
  // render all posts
  PostView::show_page(posts);
}

//------------------------------------------------
// USER CONTROLLER CLASS
//------------------------------------------------

void UserController::create() {
	try {
	User user = UserView::create_page();						// render create page and receive a new user
	// UserModel::save(user);									// Send to model to save it             // TODO: put a stub in here (later implement)
	} catch(invalid_argument erro) {}
}

void UserController::show() {
	User user = Auth::get_current_user();						// get the current user
	UserView::show_page(user);									// render show page
}

void UserController::edit() {
	try{
		User user = Auth::get_current_user();						// get the current user						
		user = UserView::edit_page(user);							// render edit page and get new user
		// UserModel::update(user);									// safe using the model                 // TODO: put a stub in here (later implement)	
	} catch(invalid_argument erro) {}
}

void UserController::destroy() {
	User user = Auth::get_current_user();  	                    // get the current user
	bool decision = UserView::delete_page();                    // render delete page and get confirmation
	if(decision == true) {
		// Auth::forced_logout()								// logout current user                  // TODO: implement
		// UserModel::delete(user)								// safe using the model                 // TODO: put a stub in here (later implement)	
	}
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
  AuthView::login_page();
  // If login succefull, mark in the Auth that user is logged
  // TODO: exactly what is written above
}

void AuthController::logout(){
  // render page of confirmation of logout
  AuthView::logout_page();
  // if the user intends to logout, mark as logout
  // TODO: exactly what is written above
}

