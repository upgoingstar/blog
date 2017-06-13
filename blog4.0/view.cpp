//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include "view.hpp"
#include "controller.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// BLOG VIEW CLASS
//------------------------------------------------
void BlogView::index(vector<Blog> allBlogs){
	system("clear || cls");    
  for(auto blog : allBlogs){
    cout << blog.get_blog_name().get() << endl;
  }
  getchar();
  getchar();
}

void BlogView::create_page() {
  system("clear || cls");
  cout << "Create Blog" << endl;
  
}

void BlogView::show_page() {
  system("clear || cls");
  cout << "Blogs" << endl;
  cout << "1 - Listar blogs" << endl;
  if(Auth::user_logged()){
    cout << "2 - Meus blogs" << endl;
  }

  int option;
  cin >> option;

  switch(option){
    case LIST:
        BlogController::index();
        break;
    case MYBLOGS:
      if(Auth::user_logged()){
        BlogView::my_blogs_page();
        break;
      }
    default:
      throw invalid_argument("Invalid option!");
      break;
  }
}

void BlogView::edit_page(unsigned int) {
  cout << "edit Blog page" << endl;
}

void BlogView::delete_page(unsigned int) {
  cout << "delete Blog page" << endl;
}

void BlogView::my_blogs_page(){
  system("clear || cls");
  vector<Blog> myBlogsList = BlogController::get_blogs(Auth::get_current_user());    
  for(auto blog : myBlogsList){
    cout << blog.get_blog_name().get() << endl;
  }
  getchar();
  getchar();
}

//------------------------------------------------
// COMMENT VIEW CLASS
//------------------------------------------------

void CommentView::create_page() {
  cout << "create Comment page" << endl;
}

void CommentView::show_page(bool, unsigned int) {
  cout << "show Comment page" << endl;
}

void CommentView::edit_page(unsigned int) {
  cout << "edit Comment page" << endl;
}

void CommentView::delete_page(unsigned int) {
  cout << "delete Comment page" << endl;
}

//------------------------------------------------
// POST VIEW CLASS
//------------------------------------------------

void PostView::create_page() {
  cout << "create Post page" << endl;
}

void PostView::show_page(bool, unsigned int) {
  cout << "show Post page" << endl;
}

void PostView::edit_page(unsigned int) {
  cout << "edit Post page" << endl;
}

void PostView::delete_page(unsigned int) {
  cout << "delete Post page" << endl;
}

//------------------------------------------------
// USER VIEW CLASS
//------------------------------------------------

void UserView::create_page() {
  string newName;
  string newEmail;
  string newPassword;
  
  system("clear || cls");
  
  cout << "Um nome deve conter apenas letras e espacos. Alem disso, deve conter no maximo 20 caracteres." << endl;
  cout << "Digite um nome: ";
  cin >> newName;
  
  cout << "Um email deve estar no formato 'l(arroba)l.l'', onde 'l' sao palavras que contem apenas letras." << endl;
  cout << "Digite um e-mail: ";
  cin >> newEmail;
  
  cout << "Uma senha deve conter ate 5 caracteres sem repeticao." << endl;
  cout << "Digite uma senha: ";
  cin >> newPassword;
  
  bool userAccepted = true;
  
  Name userName;
  Email userEmail;
  Password userPassword;
  
  try{
    userName.set(newName);
  } catch(invalid_argument erro) {
    cout << "Nome de usuario em formato incorreto." << endl;
    userAccepted = false;
  }
  
  try{
    userEmail.set(newEmail);
    try{
      if(UserController::find(userEmail)){
        throw invalid_argument("Email ja em uso.");
      }
    } catch(invalid_argument erro) {
      cout << "Email ja em uso." << endl;
      userAccepted = false;
    }
  } catch(invalid_argument erro) {
    cout << "Email em formato incorreto." << endl;
    userAccepted = false;
  }
  
  try{
    userPassword.set(newPassword);
  } catch(invalid_argument erro) {
    cout << "Senha em formato incorreto." << endl;
    userAccepted = false;
  }
  
  if(userAccepted){
    User newUser;
    newUser.set(userName, userEmail, userPassword);
    UserController::insert_new_user(newUser);
    cout << "Nova conta criada com sucesso!" << endl << "Aperte 'ENTER' para retornar ao menu principal" << endl;
    getchar();getchar();
  } else {
    cout << "Houve um problema e nao foi possivel criar a conta. Tente novamente mais tarde." << endl << "Aperte 'ENTER' para retornar ao menu principal" << endl;
    getchar();getchar();
  }
}

void UserView::show_page() {
  cout << "show user page" << endl;
}

void UserView::edit_page(unsigned int) {
  cout << "edit user page" << endl;
}

void UserView::delete_page(unsigned int) {
  cout << "delete user page" << endl;
}

//------------------------------------------------
// WELCOME VIEW CLASS
//------------------------------------------------

void WelcomeView::home_page() {
  static const int LOGIN = 1;
  static const int LOGOUT = 1;
  static const int REGISTER = 2;
  static const int ACCOUNT = 2;
  static const int LISTBLOGS = 3;
  static const int EXIT = 4;
  
  bool exit = false;
  bool error = false;

  while(!exit){
    system("clear || cls");
    cout << "Bem-vindo a Blog - a platarfoma de blogs mais supimpa do mundo!" << endl << endl;
    
    if(error) {
      cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
      error = false;
	}

    if(Auth::user_logged()){
      cout << "1 - Deslogar" << endl;
      cout << "2 - Gerenciar conta" << endl;
    } else {
      cout << "1 - Logar" << endl;
      cout << "2 - Registrar" << endl;  
    }
    
    cout << "3 - Blogs" << endl;
    cout << "4 - Sair" << endl;

    cout << endl << "> ";
    int option;
    cin >>  option;

    try{
      if(Auth::user_logged()){
        switch(option){
          case LOGOUT:
            AuthView::logout_page();
            break;
          case ACCOUNT:
            UserView::show_page();
            break;
          case LISTBLOGS: 
            BlogView::show_page();
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
            AuthView::login_page();
            break;
          case REGISTER:
            UserView::create_page();
            break;
          case LISTBLOGS: 
            BlogView::show_page();
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
// AUTH VIEW CLASS
//------------------------------------------------

void AuthView::login_page() {
  bool error = false;
	
  system("clear || cls");
  cout << "Log-in" << endl << endl;
  
  string input;
  Password password;
  Email email;
  
  cout << "E-mail: ";
  cin >> input;
  
  try{
    email.set(input);
  } catch(invalid_argument erro) {
	error = true;
  }
  
  cout << "Senha: ";
  cin >> input;
  
  try{
    password.set(input);
  } catch(invalid_argument erro) {
	error = true;
  }
  
  if(UserController::autenticate(email, password) and not error) {
    system("clear || cls");
    cout << "Log-in realizado com sucesso!" << endl << "Aperte 'ENTER' para continuar." << endl;
    getchar(); getchar();
    Auth::login(UserController::get_user(email)); 
  } else {
    system("clear || cls");
    cout << "E-mail ou senha incorretos!" << endl << "Aperte 'ENTER' para retonar ao menu principal." << endl;
    getchar(); getchar();
    Auth::logout();
  }
}

void AuthView::logout_page() {
  const static int SIM = 1;
  const static int NAO = 2;
  
  system("clear || cls");
  cout << "Tem certeza que deseja deslogar de sua conta?" << endl;
  cout << "1 - Sim" << endl;
  cout << "2 - Nao" << endl;
  
  int option;
  cin >> option;
  
  switch(option){
    case SIM:
      Auth::logout();
    case NAO:
      return;
    default:
	    throw invalid_argument("Invalid option!");
  }
}
