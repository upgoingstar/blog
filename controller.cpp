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
        BlogController::show(blogs[option - 1]);
        break;
    }
  }
}

void BlogController::user_blogs() throw(invalid_argument) {
  const int EXIT = 0;
  
  bool exit = false;
  bool error = false;
  
  vector<Blog> blogs = Stub::get_blogs(Auth::get_current_user());  // get all Blogs from model
  
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
        BlogController::show(blogs[option - 1]);
        break;
    }
  }
}

void BlogController::create() throw(invalid_argument) {
  try {
    Blog blog = BlogView::create_page();                           // render create page and receive a new blog
    // BlogModel::save(user);                                      // Send to model to save it             // TODO: put a stub in here (later implement)
  } 
  catch(invalid_argument erro) {}
}

void BlogController::show(Blog blog){
  const int EXIT = 0;
  const int VIEWPOST = 1;
  const int NEWPOST = 2;
  const int DELETEBLOG = 3;
  
  bool exit = false;
  bool error = false;
  
  while(!exit){
    int option = BlogView::show_page(blog, error);
    error = false;
    
      if(Auth::user_logged() && Auth::get_current_user().get_name() == blog.get_author()){
        switch(option){
          case EXIT:
            exit = true;
            break;
          case VIEWPOST:
            PostController::index(blog);
            break;
          case NEWPOST:
            PostController::create();
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
            PostController::index(blog);
            break;
          default:
            error = true;
            break;
        }
      }
  } 
}

void BlogController::edit(Blog blog) {
  try{
    blog = BlogView::edit_page(blog);                             // render edit page and get new blog
    // BlogModel::update(blog);                                   // safe using the model                 // TODO: put a stub in here (later implement) 
  }
  catch(invalid_argument erro) {}
}

bool BlogController::destroy(Blog blog) throw(invalid_argument) {
  bool error = false;
  const int SIM = 1;
  const int NAO = 0;
  
  while(true){
    int option;
    try{
      option = BlogView::delete_page(error);
      error = false;
    }
    catch(invalid_argument erro){
      error = true;
      continue;
    }
    
    switch(option){
      case SIM:
        Stub::destroy_blog(blog);
        BlogView::deleted_page();
        return true;
      case NAO:
        return false;
    }
  }
}

void BlogController::menu() {
  const int EXIT = 0;
  const int LIST = 1;
  const int MYBLOGS = 2;
  const int CREATEBLOG = 3; 

  bool error = false;
  bool exit = false;
  
  while(!exit){
    int option = BlogView::menu_page(error);
    error = false;
  
    if(Auth::user_logged()){
      switch(option){
        case EXIT:
          exit = true;
          break;
        case LIST:
            BlogController::index();
            break;
        case MYBLOGS:
            BlogController::user_blogs();
            break;
        case CREATEBLOG:
            BlogController::create();
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
        case LIST:
            BlogController::index();
            break;
        default:
          error = true;
          break;
      }
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
        CommentController::show(comments[option - 1]);
        break;
    }
  }
}

void CommentController::create() {
  try {
    Comment comment = CommentView::create_page();                 // render create page and receive a new comment
    // CommentModel::save(Comment);                               // Send to model to save it             // TODO: put a stub in here (later implement)
  } 
  catch(invalid_argument erro) {}
}

void CommentController::show(Comment comment) {
  static const int EXIT = 0;
  static const int EDIT = 1;
  static const int DELETE = 2;

  bool exit = false;
  bool error = false;

  while(!exit) {
    int option = CommentView::show_page(comment, error);          // render show page

    try {
      if(Auth::user_logged() && comment.get_author() == Auth::get_current_user().get_name()){
        switch(option) {
          case EXIT:
            exit = true;
            break;
          case EDIT:
            CommentController::edit(comment);
            break;
          case DELETE:
            exit = CommentController::destroy(comment);
            break;
          default:
            throw invalid_argument("Invalid option!");
            break;
        }
      }
      else{
        switch(option) {
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

void CommentController::edit(Comment comment) {
  try{
    comment = CommentView::edit_page(comment);                    // render edit page and get new comment
    // CommentModel::update(comment);                             // safe using the model                 // TODO: put a stub in here (later implement) 
  } 
  catch(invalid_argument erro) {}
}

bool CommentController::destroy(Comment comment) {
  bool error = false;
  const int SIM = 1;
  const int NAO = 0;
  
  while(true){
    int option;
    try{
      option = CommentView::delete_page(error);
      error = false;
    }
    catch(invalid_argument erro){
      error = true;
      continue;
    }
    
    switch(option){
      case SIM:
        Stub::destroy_comment(comment);
        CommentView::deleted_page();
        return true;
      case NAO:
        return false;
    }
  }
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
        PostController::show(posts[option - 1]);
        break;
    }
  }
}

void PostController::create() {
  try {
    Post post = PostView::create_page();                          // render create page and receive a new post
    // PostModel::save(Post);                                     // Send to model to save it             // TODO: put a stub in here (later implement)
  } 
  catch(invalid_argument erro) {}
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
    int option = PostView::show_page(post, error);                // render show page
    error = false;
    
    try {
      if(Auth::user_logged() && post.get_author() == Auth::get_current_user().get_name()){
        switch(option) {
          case EXIT:
            exit = true;
            break;
          case COMMENTS:
            CommentController::index(post);
            break;
          case EDIT:
            PostController::edit(post);
            break;
          case DISALLOW:
            post.disallow_comments();
            break;
          case DELETE:
             exit = PostController::destroy(post);
            break;
          default:
            throw invalid_argument("Invalid option!");
            break;
        }
      }
      else{
        switch(option) {
          case EXIT:
              exit = true;
              break;
          case COMMENTS:
            CommentController::index(post);
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

void PostController::edit(Post post) {
  try{
    post = PostView::edit_page(post);                             // render edit page and get new post
    // PostModel::update(post);                                   // safe using the model                 // TODO: put a stub in here (later implement) 
  }
  catch(invalid_argument erro) {}
}

bool PostController::destroy(Post post) {
  bool error = false;
  const int SIM = 1;
  const int NAO = 0;
  
  while(true){
    int option;
    try{
      option = PostView::delete_page(error);
      error = false;
    }
    catch(invalid_argument erro){
      error = true;
      continue;
    }
    
    switch(option){
      case SIM:
        Stub::destroy_post(post);
        PostView::deleted_page();
        return true;
      case NAO:
        return false;
    }
  }
}

//------------------------------------------------
// USER CONTROLLER CLASS
//------------------------------------------------

void UserController::create() {
  try {
  User user = UserView::create_page();                            // render create page and receive a new user
  // UserModel::save(user);                                       // Send to model to save it             // TODO: put a stub in here (later implement)
  }
  catch(invalid_argument erro) {}
}

void UserController::show() {
  static const int EXIT = 0;
  static const int CHANGE_PASSWORD = 1;
  static const int DELETE_ACCOUNT = 2;

  bool exit = false;
  bool error = false;

  User user = Auth::get_current_user();                           // get the current user

  while(!exit) {
    int option = UserView::show_page(user, error);                // render show page

    try {
      switch(option) {
        case EXIT:
          exit = true;
          break;
        case CHANGE_PASSWORD:
          UserController::edit();
          break;
        case DELETE_ACCOUNT:
          exit = UserController::destroy(user);
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
    User user = Auth::get_current_user();                         // get the current user           
    user = UserView::edit_page(user);                             // render edit page and get new user
    // UserModel::update(user);                                   // safe using the model                 // TODO: put a stub in here (later implement) 
  } catch(invalid_argument erro) {}
}

bool UserController::destroy(User user) {
  bool error = false;
  const int SIM = 1;
  const int NAO = 0;
  
  while(true){
    int option;
    try{
      option = UserView::delete_page(error);
      error = false;
    }
    catch(invalid_argument erro){
      error = true;
      continue;
    }
    
    switch(option){
      case SIM:
        Stub::destroy_user(user);
        UserView::deleted_page();
        Auth::logout();
        return true;
      case NAO:
        return false;
    }
  }
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
            BlogController::menu();
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
            BlogController::menu();
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

void AuthController::login() {
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

void AuthController::logout() {
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

