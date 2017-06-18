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
  const int EXIT = 0;

  bool exit = false;
  bool error = false;
  
  vector<Blog> blogs = Stub::get_all_blogs();                  // get all Blogs from model

  while(!exit){
    int option = BlogView::index_page(blogs, error);           // render page with all blogs
    
    if(option > blogs.size()){
      error = true;
      continue;
    }

    switch(option){
      case EXIT:
        exit = true;
        break;
      default:
        // TODO: this wasn't suppose to be a show?
        BlogController::edit(blogs[option - 1], false);
    }
  }
}

Blog BlogController::create() throw(invalid_argument) {
  try {
    Blog blog = BlogView::create_page();            // render create page and receive a new blog
    // BlogModel::save(user);                 // Send to model to save it             // TODO: put a stub in here (later implement)
  } catch(invalid_argument erro) {}
}

void BlogController::user_blogs() throw(invalid_argument) {
  const int EXIT = 0;
  
  bool exit = false;
  bool error = false;

  // TODO: this should not be here
  vector<Blog> blogs = Stub::get_blogs(Auth::get_current_user());// get all Blogs from model

  while(!exit){
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
}

void BlogController::edit(Blog blog, const bool master){
  const int EXIT = 0;
  const int VIEWPOST = 1;
  const int NEWPOST = 2;
  const int DELETEBLOG = 3;
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
          PostController::show(blog, master);
          break;
        case NEWPOST:
          PostController::create(blog);
          break;
        case DELETEBLOG:
          exit = BlogController::destroy(blog);
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
          PostController::show(blog, master);
          break;
        default:
          error = true;
          break;
      }
    }
  } 
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
  try {
    bool decision = BlogView::delete_page();                    // render delete page and get confirmation
    if(decision == true) {
      // BlogModel::delete(comment)                // safe using the model                 // TODO: put a stub in here (later implement) 
    }
  } catch(invalid_argument erro);
}
// TODO: change this to menu (show page is to show a individual blog)
// TODO: this should recieve an argument (The blog it will show)
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
          BlogController::user_blogs();
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

// TODO: IMPORTANT! add to the Comment an id to identify to which post is he refering to

// TODO: make Post show call this funtion, but in a form CommentController::index(vector<Comment> comments)
void CommentController::index(Post post){
  const int EXIT = 0;

  bool error = false;
  bool exit = false;
  
  vector<Comment> comments = Stub::get_comments(post);

  while(!exit){
    int option = CommentView::index_page(comments, error);

    error = false;

    if(option > comments.size()){
      error = true;
      continue;
    }
    switch(option){
      case EXIT:
        exit = true;
        break;
      default:
        CommentController::show(comment[option - 1]);
        break;
    }
  }
}

void CommentController::create() {
  try {
    Comment comment = CommentView::create_page();           // render create page and receive a new comment
    // CommentModel::save(Comment);                 // Send to model to save it             // TODO: put a stub in here (later implement)
  } catch(invalid_argument erro) {}
}

void CommentController::show(Comment comment) {
  static const int EXIT = 0;
  static const int EDIT = 1;
  static const int DELETE = 2;

  bool exit = false;
  bool error = false;

  while(!exit) {
    int option = CommentView::show_page(comment, error);                  // render show page

    try {
      switch(option) {
        case EXIT:
          exit = true;
          break;
        case EDIT:
          CommentController::edit();
          break;
        case DELETE:
          CommentController::destroy();
          exit = true;
          break;
        default:
          throw invalid_argument("Invalid option!");
          break;
      }
    } catch(invalid_argument erro) {
      error = true;
    }
  }
}

void CommentController::edit(Comment comment) {
  try{
    comment = CommentView::edit_page(comment);              // render edit page and get new comment
    // CommentModel::update(comment);                 // safe using the model                 // TODO: put a stub in here (later implement) 
  } catch(invalid_argument erro) {}
}

void CommentController::destroy(Comment comment) {
  try {
    bool decision = CommentView::delete_page();                    // render delete page and get confirmation
    if(decision == true) {
      // CommentModel::delete(comment)                // safe using the model                 // TODO: put a stub in here (later implement) 
    }
  } catch(invalid_argument erro);
}

//------------------------------------------------
// POST CONTROLLER CLASS
//------------------------------------------------

// TODO: IMPORTANT! add to the Post an id to identify to which blog is he refering to
// TODO: do not let it comment if the post disllow it

void PostController::index(Blog blog){
  const int EXIT = 0;

  bool error = false;
  bool exit = false;
  
  vector<Post> posts = Stub::get_posts(blog);

  while(!exit){
    int option = PostView::index_page(posts, error);

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
        PostController::show(post[option - 1]);
        break;
    }
  }
}

void PostController::create() {
  try {
    Post post = PostView::create_page();           // render create page and receive a new post
    // PostModel::save(Post);                 // Send to model to save it             // TODO: put a stub in here (later implement)
  } catch(invalid_argument erro) {}
}

void PostController::show(Post post) {
  static const int EXIT = 0;
  static const int COMMENTS = 1;
  static const int EDIT = 2;
  static const int DISALLOW = 3;
  static const int DELETE = 4;

  bool exit = false;
  bool error = false;

  while(!exit) {
    int option = PostView::show_page(post, error);                  // render show page

    try {
      switch(option) {
        case EXIT:
          exit = true;
          break;
        case COMMENTS:
          CommentController::index();
          break;
        case EDIT:
          PostController::edit();
          break;
        case DISALLOW:
          Post::disallow_comments();
          break;
        case DELETE:
          PostController::destroy();
          exit = true;
          break;
        default:
          throw invalid_argument("Invalid option!");
          break;
      }
    } catch(invalid_argument erro) {
      error = true;
    }
  }
}

void PostController::edit(Post post) {
  try{
    post = PostView::edit_page(post);              // render edit page and get new post
    // PostModel::update(post);                 // safe using the model                 // TODO: put a stub in here (later implement) 
  } catch(invalid_argument erro) {}
}

void PostController::destroy(Post post) {
  try {
    bool decision = PostView::delete_page();                    // render delete page and get confirmation
    if(decision == true) {
      // PostModel::delete(comment)                // safe using the model                 // TODO: put a stub in here (later implement) 
    }
  } catch(invalid_argument erro);
}

//------------------------------------------------
// USER CONTROLLER CLASS
//------------------------------------------------

void UserController::create() {
  try {
  User user = UserView::create_page();            // render create page and receive a new user
  // UserModel::save(user);                 // Send to model to save it             // TODO: put a stub in here (later implement)
  } catch(invalid_argument erro) {}
}

void UserController::show() {
  static const int EXIT = 0;
  static const int CHANGE_PASSWORD = 1;
  static const int DELETE_ACCOUNT = 2;

  bool exit = false;
  bool error = false;

  User user = Auth::get_current_user();           // get the current user

  while(!exit) {
    int option = UserView::show_page(user, error);                  // render show page

    try {
      switch(option) {
        case EXIT:
          exit = true;
          break;
        case CHANGE_PASSWORD:
          UserController::edit();
          break;
        case DELETE_ACCOUNT:
          // TODO: make sure he will be back to the home page
          UserController::destroy();
          exit = true;
          break;
        default:
          throw invalid_argument("Invalid option!");
          break;
      }
    } catch(invalid_argument erro) {
      error = true;
    }
  }
}

void UserController::edit() {
  try{
    User user = Auth::get_current_user();           // get the current user           
    user = UserView::edit_page(user);             // render edit page and get new user
    // UserModel::update(user);                 // safe using the model                 // TODO: put a stub in here (later implement) 
  } catch(invalid_argument erro) {}
}

void UserController::destroy() {
  try {
    bool decision = PostView::delete_page();                    // render delete page and get confirmation
    if(decision == true) {
      User user = Auth::get_current_user();                       // get the current user
      // UserModel::delete(user)                // safe using the model                 // TODO: put a stub in here (later implement)   
      // Auth::forced_logout()                // logout current user                  // TODO: implement
    }
  } catch(invalid_argument erro);
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
      if(Auth::user_logged()) {
        switch(option){
          case LOGOUT:
            AuthController::logout();
            break;
          case ACCOUNT:
            UserController::show();
            break;
          case LISTBLOGS: 
            // TODO: mudar para index
            BlogController::show();
            break;
          case EXIT:   
            exit = true; 
            break;
          default:
            throw invalid_argument("Invalid option!");
            break;
        }
      } else {
        switch(option) {
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
            break;
        }
      }
    } catch(invalid_argument erro) {
      error = true;
    }
  }
}

//------------------------------------------------
// Auth CONTROLLER CLASS
//------------------------------------------------

void AuthController::login(){
  bool error = false;
  
  Email email;
  Password password;
  
  try {
    // TODO: verify if the email is passed as reference so it can be altered within this function
    AuthView::login_page(email, password);
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
      // TODO: verify implementation to see if can be used like that
      Auth::logout();
    case NAO:
      return;
    default:
      throw invalid_argument("Invalid option!");
  }
}

