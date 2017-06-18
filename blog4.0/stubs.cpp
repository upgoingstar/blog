//------------------------------------------------
// Includes
//------------------------------------------------
#include "stubs.hpp"
#include "entity.hpp"
#include "domains.hpp"

using namespace std;

//------------------------------------------------
// Method Implementation of Class Stub
//------------------------------------------------
bool Stub::user_autenticate(Email toCheckEmail, Password toCheckPassword){
  Email registredEmail;
  registredEmail.set("stub@stub.stub");
  
  Password registredPassword;
  registredPassword.set("stubp");

  if(toCheckEmail == registredEmail and toCheckPassword == registredPassword){
    return true;
  }
  else{
    return false;
  }
};

bool Stub::user_find(Email toCheckEmail){
  Email registredEmail;
  registredEmail.set("stub@stub.stub");
  
  if(toCheckEmail == registredEmail){
    return true;
  }
  else{
    return false;
  }
}

vector<Blog> Stub::get_blogs(User stubUser){
  vector<Blog> stubBlogs;
  Blog stubBlog1,stubBlog2;
  Name stubBlogName;
  
  stubBlogName.set("Claudino Adventure");
  stubBlog1.set(stubUser.get_name(),stubBlogName);
    
  stubBlogName.set("A batata");
  stubBlog2.set(stubUser.get_name(),stubBlogName);
  
  stubBlogs.push_back(stubBlog1); 
  stubBlogs.push_back(stubBlog2);
  
  return stubBlogs; 
}

vector<Blog> Stub::get_all_blogs(){
  Email registredEmail;
  registredEmail.set("stub@stub.stub");
  
  Password registredPassword;
  registredPassword.set("stubp");
  
  Name registredName;
  registredName.set("stub");
  
  User stubUser;
  stubUser.set(registredName, registredEmail, registredPassword);
  
  
  vector<Blog> stubBlogs;
  Blog stubBlog1, stubBlog2, stubBlog3;
  Name stubBlogName;
  
  stubBlogName.set("Claudino Adventure");
  stubBlog1.set(stubUser.get_name(),stubBlogName);
    
  stubBlogName.set("A batata");
  stubBlog2.set(stubUser.get_name(),stubBlogName);
  
  registredName.set("Gabierl");
  stubUser.set(registredName, registredEmail, registredPassword);
  stubBlogName.set("Outra coisa");
  stubBlog3.set(stubUser.get_name(),stubBlogName);
  
  stubBlogs.push_back(stubBlog1); 
  stubBlogs.push_back(stubBlog2);
  stubBlogs.push_back(stubBlog3);
  
  return stubBlogs; 
}

User Stub::get_user(Email email){
  Email registredEmail;
  registredEmail.set("stub@stub.stub");
  
  Password registredPassword;
  registredPassword.set("stubp");
  
  Name registredName;
  registredName.set("stub");
  
  User registredUser;
  registredUser.set(registredName, registredEmail, registredPassword);
  
  return registredUser;
}

vector<Post> Stub::get_posts(Blog blog){
  vector<Post> posts;
  Post aux;
  Text aux3;
  
  if(blog.get_name().get() == "A batata"){
    aux3.set("Uma batata queria uma calca muito chique");
    aux.set_author(blog.get_author());
    aux.set_content(aux3);
    posts.push_back(aux);
    
    aux3.set("Mas ai deu um bug e veio uma bermuda");
    aux.set_author(blog.get_author());
    aux.set_content(aux3);
    posts.push_back(aux);
  }
  
  if(blog.get_name() == "Claudino Adventure"){
    aux3.set("Claudino saiu em uma aventura cheia de perigos");
    aux.set_author(blog.get_author());
    aux.set_content(aux3);
    posts.push_back(aux);
    
    aux3.set("Claudino terminou sua aventura");
    aux.set_author(blog.get_author());
    aux.set_content(aux3);
    posts.push_back(aux);
  }
  
  if(blog.get_name() == "Outra coisa"){
    aux3.set("Como faz pra excluir o blog?");
    aux.set_author(blog.get_author());
    aux.set_content(aux3);
    posts.push_back(aux);
  }
  
  return posts;
}

vector<Comment> Stub::get_comments(Post post){
  vector<Comment> comments;
  Comment aux;
  Text aux3;
  Name aux4;
  
  if(post.get_content() == "Uma batata queria uma calca muito chique"){
    aux3.set("Que emocionante, mal posso esperar a continuacao");
    aux4.set("Carinha");
    aux.set_author(aux4);
    aux.set_content(aux3);
    comments.push_back(aux);
    
    aux3.set("A historia mais empolgante que ja li!");
    aux4.set("Fildosve");
    aux.set_author(aux4);
    aux.set_content(aux3);
    comments.push_back(aux);
  }
  
  if(post.get_content() == "Mas ai deu um bug e veio uma bermuda"){
    aux3.set("Final triste ;(");
    aux4.set("Carinha");
    aux.set_author(aux4);
    aux.set_content(aux3);
    comments.push_back(aux);
    
    aux3.set("A batata vai aprender a amar sua bermuda!");
    aux4.set("Genoscla");
    aux.set_author(aux4);
    aux.set_content(aux3);
    comments.push_back(aux);
    
    aux3.set("Aff, que virjao, sai do computador e vai comer uma");
    aux4.set("Jyubertw");
    aux.set_author(aux4);
    aux.set_content(aux3);
    comments.push_back(aux);
    
  }
  
  if(post.get_content() == "Como faz pra excluir o blog?"){
    aux3.set("Vai na pagina de deletar o blog");
    aux4.set("stub");
    aux.set_author(aux4);
    aux.set_content(aux3);
    comments.push_back(aux);
    
  }
  
  aux3.set("Bolsonaro 2018!");
  aux4.set("Pedrinho");
  aux.set_author(aux4);
  aux.set_content(aux3);
  comments.push_back(aux);
  
  return comments;
 }
