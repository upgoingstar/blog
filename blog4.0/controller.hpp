//------------------------------------------------
// GUARD
//------------------------------------------------

#ifndef __CONTROLLER_H_INCLUDED__
#define __CONTROLLER_H_INCLUDED__

//------------------------------------------------
// INCLUDE
//------------------------------------------------

#include "domains.hpp"
#include "entity.hpp"
#include "stubs.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// BLOG CONTROLLER CLASS
//------------------------------------------------

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

public:
  static vector<Blog> get_blogs(User u){
    return Stub::getBlogs(u); 
  }
};


//------------------------------------------------
// COMMENT CONTROLLER CLASS
//------------------------------------------------

/**
* A class that controls Comment
* Defines CRUD
*/
class CommentController : public Comment {

};

//------------------------------------------------
// CONTENT CONTROLLER CLASS
//------------------------------------------------

/**
* A class that controls Content
* Defines CRUD
*/
class ContentController : public Content {

};

//------------------------------------------------
// POST CONTROLLER CLASS
//------------------------------------------------

/**
* A class that controls Post
* Defines CRUD
*/
class PostController : public Post {

};

//------------------------------------------------
// USER CONTROLLER CLASS
//------------------------------------------------

/**
* A class that controls User
* Defines CRUD
*/
class UserController : public User {
public:
  static bool autenticate(Email e, Password p){
    return Stub::userAutenticate(e, p);
  }
  
  static bool find(Email e){
    return Stub::userFind(e);
  }
  
  static void insert_new_user(User){
    return;
  }
};

//------------------------------------------------
// AUTH CONTROLLER CLASS
//------------------------------------------------

/**
* A class that controls Auth
* Responsible for authentication
*/
// TODO: make it inherit from Auth
class AuthController {
public:
  static User get(){
    User u;
    Name nome;
    Email email;
    Password senha;
    nome.set("stub");
    email.set("stub@stub.stub");
    senha.set("stubp");
    u.set(nome,email,senha);
    return u;
  }
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif
