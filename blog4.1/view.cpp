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
void BlogView::index_page(vector<Blog> blogs){
  const int EXIT = 0;
  bool exit = false;
  bool error = false;

  while(!exit){
    system("clear || cls"); 
    
    if(error) {
      error = false;
      cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
    }
    
    cout << "0 - Sair" << endl;
    for(int i = 1; i <= (int)blogs.size(); i++){
      cout << i << " - " << blogs[i].get_blog_name().get() << endl;
    }
    
    int option;
    cout << "Escolha um blog para acessar: ";
    cin >> option;
    
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

void BlogView::create_page() {
  cout << "create Blog page" << endl;
}

// TODO: change this to menu (show page is to show a individual blog)
void BlogView::show_page() {
  const int EXIT = 0;
  const int LIST = 1;
  const int MYBLOGS = 2;
  const int CREATEBLOG = 3; 
  bool error = false;
  bool exit = false;

  while(!exit){
    system("clear || cls");
    cout << "Blogs" << endl;
    
    if(error) {
      error = false;
      cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
    }
    
    cout << "0 - Sair" << endl;
    cout << "1 - Listar blogs" << endl;
    if(Auth::user_logged()){
      cout << "2 - Meus blogs" << endl;
      cout << "3 - Criar blog" << endl;
    }

    int option;
    cin >> option;

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

void BlogView::edit_page(Blog blog, bool master, bool error) {
  const int EXIT = 0;
  const int VIEWPOST = 1;
  const int NEWPOST = 2;
  const int DELETEPOST = 3;
  const int DELETEBLOG = 4;
  bool exit = false;
  bool error = false;

  while(!exit){
    system("clear || cls");
    cout << blog.get_blog_name().get() << endl << endl;
    
    if(error){
      error = false;
    	cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
    }
    
    cout << "0 - Sair" << endl;
    cout << "1 - Acessar post" << endl;
    if(master){
    	cout << "2 - Adicionar post" << endl;
    	cout << "3 - Deletar post" << endl;
    	cout << "4 - Deletar blog" << endl;
    }
    
    int option;
    cin >> option;
    
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

void BlogView::delete_page(unsigned int) {
  cout << "delete Blog page" << endl;
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

void PostView::show_page(vector<Post> posts, bool error) {
	const int EXIT = 0;
  const int LIST = 1;
  const int MYBLOGS = 2;
  const int CREATEBLOG = 3; 
  bool error = false;
  bool exit = false;

  while(!exit){
    system("cls || clear");

    if(error) {
      error = false;
      cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
    }	

    cout << "0 - Sair" << endl;
    for(int i = 0; i < (int)posts.size(); i++){
      cout << i+1 << " - " << posts[i].get().get_content().get() << endl;
    }

    cout << "Escolha o post que deseja acessar: ";
    int option;
    cin >> option;

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
  bool userAccepted = true;
  bool correctName = true;
  bool correctPassword = true;
  bool correctEmail = true;
  bool registredEmail = false;
  
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
  
  cout << "Uma seha deve conter ate 5 caracteres sem repeticao." << endl;
  cout << "Digite uma senha: ";
  cin >> newPassword;
  
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

void UserView::finish_create_page(bool userAccepted, bool correctName, bool correctPassword, bool correctEmail, bool registredEmail){
  if(!correctName){
	cout << "Nome de usuario em formato incorreto." << endl;
  }
  
  if(!correctEmail){
    cout << "Email em formato incorreto." << endl;
  }
  
  if(!correctPassword){
    cout << "Senha em formato incorreto." << endl;
  }
  
  if(registredEmail){
      cout << "Email ja em uso." << endl;
  }
  
  if(userAccepted){
	cout << "Nova conta criada com sucesso!" << endl << "Aperte 'ENTER' para retornar ao menu principal" << endl;
    getchar();getchar();
  } else{
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
  static const int EXIT = 0;
  static const int LOGIN = 1;
  static const int LOGOUT = 1;
  static const int REGISTER = 2;
  static const int ACCOUNT = 2;
  static const int LISTBLOGS = 3;
  
  bool exit = false;
  bool error = false;

  while(!exit){
    system("clear || cls");
    cout << "Bem-vindo a Blog - a platarfoma de blogs mais supimpa do mundo!" << endl << endl;
    
    if(error) {
      error = false;
      cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
    }

    cout << "0 - Sair" << endl;
    if(Auth::user_logged()){
      cout << "1 - Deslogar" << endl;
      cout << "2 - Gerenciar conta" << endl;
    } else {
      cout << "1 - Logar" << endl;
      cout << "2 - Registrar" << endl;  
    }
    
    cout << "3 - Blogs" << endl;

    cout << endl << "> ";
    int option;
    cin >>  option;

    try{
      if(Auth::user_logged()) {
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
        }
      }
    } catch(invalid_argument erro) {
      error = true;
    }
	}
}

//------------------------------------------------
// AUTH VIEW CLASS
//------------------------------------------------

void AuthView::login_page(string &email, string &password) {
  bool error = false;
  
  string emailIn, passwordIn;
  Email email;
  Password password;
  
  system("clear || cls");
  cout << "Log-in" << endl << endl;
  
  cout << "E-mail: ";
  cin >> email;
  
  cout << "Senha: ";
  cin >> password;

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

void AuthView::finish_login_page(bool error){
	if(error){
	  system("clear || cls");
      cout << "E-mail ou senha incorretos!" << endl << "Aperte 'ENTER' para retonar ao menu principal." << endl;
   	  getchar(); getchar();
	}
	else{
   	  system("clear || cls");
      cout << "Log-in realizado com sucesso!" << endl << "Aperte 'ENTER' para continuar." << endl;
      getchar(); getchar();	
	}
}

int AuthView::logout_page() {
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
