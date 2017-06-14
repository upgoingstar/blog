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

void BlogController::index() {
	vector<Blog> blogs = Stub::get_all_blogs();// get all Blogs from model
	BlogView::index_page(blogs);
	// render page with all blogs
	// return to last page
}

void BlogController::my_blogs() {
	vector<Blog> blogs = Stub::get_blogs(Auth::get_current_user());// get all Blogs from model
	BlogView::my_blogs_page(blogs);
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

void BlogController::show() {
  const int LIST = 1;
  const int MYBLOGS = 2;
	
  int option = BlogView::show_page();;
  
  switch(option){
    case LIST:
        BlogController::index();
        break;
    case MYBLOGS:
      if(Auth::user_logged()){
        BlogController::my_blogs();
        break;
      }
    default:
      throw invalid_argument("Invalid option!");
      break;
  }
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
void UserController::create() {
  bool userAccepted = true;
  bool correctName = true;
  bool correctPassword = true;
  bool correctEmail = true;
  bool registredEmail = false;
  
  string newName;
  string newEmail;
  string newPassword;
  
  UserView::create_page(newName, newEmail, newPassword);
  
  Name userName;
  Email userEmail;
  Password userPassword;
  
  try{
    userName.set(newName);
  } catch(invalid_argument erro) {
    correctName = false;
    userAccepted = false;
  }
  
  try{
    userEmail.set(newEmail);
    try{
      if(UserController::find(userEmail)){
        throw invalid_argument("Email ja em uso.");
      }
    } catch(invalid_argument erro) {
      registredEmail = true;
      userAccepted = false;
    }
  } catch(invalid_argument erro) {
    correctEmail = false;
    userAccepted = false;
  }
  
  try{
    userPassword.set(newPassword);
  } catch(invalid_argument erro) {
    correctPassword = false;
    userAccepted = false;
  }
  
  UserView::finish_create_page(userAccepted, correctName, correctPassword, correctEmail, registredEmail);
  
  if(userAccepted){
    User newUser;
    newUser.set(userName, userEmail, userPassword);
    UserController::insert_new_user(newUser);

  }
}

//------------------------------------------------
// WELCOME CONTROLLER CLASS
//------------------------------------------------
void WelcomeController::home_page() {
  static const int LOGIN = 1;
  static const int LOGOUT = 1;
  static const int REGISTER = 2;
  static const int ACCOUNT = 2;
  static const int LISTBLOGS = 3;
  static const int EXIT = 4;
  
  bool exit = false;
  bool error = false;

  while(!exit){
    int option = WelcomeView::home_page(error);

    try{
      if(Auth::user_logged()){
        switch(option){
          case LOGOUT:
            AuthController::logout();
            break;
          case ACCOUNT:
            UserView::show_page();
            break;
          case LISTBLOGS: 
            BlogController::show();
            break;
          case EXIT:   
            exit = true; 
            break;
          default:
            throw invalid_argument("Invalid option!");
        }
      } else {
        switch(option){
          case LOGIN:
            AuthController::login();
            break;
          case REGISTER:
            UserController::create();
            break;
          case LISTBLOGS: 
            BlogController::show();
            break;
          case EXIT:    
            exit = true; 
            break;
          default:
            throw invalid_argument("Invalid option!");
        }
      }
    } catch(invalid_argument erro){
    	error = true;
    }
  }
}

//------------------------------------------------
// Auth CONTROLLER CLASS
//------------------------------------------------
void AuthController::login(){
  bool error = false;
	
  string emailIn, passwordIn;
  Email email;
  Password password;
  
  AuthView::login_page(emailIn,passwordIn);

  try{
    email.set(emailIn);
  } catch(invalid_argument erro) {
	error = true;
  }

  try{
    password.set(passwordIn);
  } catch(invalid_argument erro) {
	error = true;
  }
  
  error |= !UserController::autenticate(email, password);
  
  AuthView::finish_login_page(error);
  if(not error) {
    Auth::login(UserController::get_user(email)); 
  } 
}

void AuthController::logout(){
  const static int SIM = 1;
  const static int NAO = 2;
  
  int option = AuthView::logout_page();
  
  switch(option){
    case SIM:
      Auth::logout();
    case NAO:
      return;
    default:
	    throw invalid_argument("Invalid option!");
  }
}

