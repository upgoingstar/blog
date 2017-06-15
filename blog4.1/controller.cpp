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
	const int EXIT = 0;
	bool exit = false;
	bool error = false;
	
	while(!exit){
		vector<Blog> blogs = Stub::get_all_blogs();// get all Blogs from model
		int option = BlogView::index_page(blogs, error);
		error = false;
		
		if(option > blogs.size()){
			error = true;
			continue;
		}
		switch(option){
			case EXIT:
				exit = true;
				break;
			default:
				BlogController::edit(blogs[option - 1], false);
		}
	}	// render page with all blogs
	// return to last page
}

void BlogController::my_blogs() throw(invalid_argument) {
	const int EXIT = 0;
	bool exit = false;
	bool error = false;
	
	while(!exit){
		vector<Blog> blogs = Stub::get_blogs(Auth::get_current_user());// get all Blogs from model
		int option = BlogView::index_page(blogs, error);
		error = false;
		
		if(option > blogs.size()){
			error = true;
			continue;
		}
		switch(option){
			case EXIT:
				exit = true;
				break;
			default:
				BlogController::edit(blogs[option - 1], true);
		}
	}
	// render page with all blogs
	// return to last page
}

void BlogController::edit(Blog blog, const bool master){
	const int EXIT = 0;
	const int VIEWPOST = 1;
	const int NEWPOST = 2;
	const int DELETEPOST = 3;
	const int DELETEBLOG = 4;
	bool exit = false;
	bool error = false;
	
	while(!exit){
		int option = BlogView::edit_page(blog, master, error);
		error = false;
		
		if(master){
			switch(option){
				case EXIT:
					exit = true;
					break;
				case VIEWPOST:
					PostController::show(blog);
					break;
				case NEWPOST:
					break;
				case DELETEPOST:
					break;
				case DELETEBLOG:
					break;
				default:
					error = true;
					break;
			}
		}
		else{
			switch(option){
				case EXIT:
					exit = true;
					break;
				case VIEWPOST:
					PostController::show(blog);
					break;
				default:
					error = true;
					break;
			}
		}
	}	
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
  const int EXIT = 0;
  const int LIST = 1;
  const int MYBLOGS = 2;
  const int CREATEBLOG = 3;	
  bool error = false;
  bool exit = false;
  
  while(!exit){
    int option = BlogView::show_page(error);;
    error = false;
  
    switch(option){
  		case EXIT:
  			exit = true;
  			break;
	    case LIST:
	        BlogController::index();
	        break;
	    case MYBLOGS:
	      if(Auth::user_logged()){
	        BlogController::my_blogs();
	        break;
	      }
	    case CREATEBLOG:
	      if(Auth::user_logged()){
	        BlogController::create();
	        break;
	      }
	    default:
	      error = true;
	      break;
	}
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
void PostController::show(Blog blog){
  const int EXIT = 0;
  const int LIST = 1;
  const int MYBLOGS = 2;
  const int CREATEBLOG = 3;	
  bool error = false;
  bool exit = false;
  
  while(!exit){
	vector<Post> posts = Stub::get_posts(blog);
	int option = PostView::show_page(posts, error);
 	
 	error = false;
 	
 	if(option > posts.size()){
 		error = true;
 		continue;
	 }
 	switch(option){
 		case EXIT:
 			exit = true;
 			break;
 		default:
 			error = true;
	 }
  }
}

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
      if(Stub::user_find(userEmail)){
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
    UserController::new_user(newUser);

  }
}

void UserController::edit() {
}
//------------------------------------------------
// WELCOME CONTROLLER CLASS
//------------------------------------------------
void WelcomeController::home_page() {
  static const int EXIT = 0;
  static const int LOGIN = 1;
  static const int LOGOUT = 1;
  static const int REGISTER = 2;
  static const int ACCOUNT = 2;
  static const int LISTBLOGS = 3;
  
  bool exit = false;
  bool error = false;

  while(!exit){
    int option = WelcomeView::home_page(error);
	error = false;
	
    try{
      if(Auth::user_logged()){
        switch(option){
          case LOGOUT:
            AuthController::logout();
            break;
          case ACCOUNT:
            UserController::edit();
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
  
  error |= !Stub::user_autenticate(email, password);;
  
  AuthView::finish_login_page(error);
  if(not error) {
    Auth::login(Stub::get_user(email)); 
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

