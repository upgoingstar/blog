//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include "view.hpp"
#include "controller.hpp"
#include "entity.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// BLOG VIEW CLASS
//------------------------------------------------
void BlogView::index_page(vector<Blog> blogs) {
  const int EXIT = 0;
  bool exit = false;
  bool error = false;

  while(!exit){
    system("clear || cls"); 
    
    if(error) {
      error = false;
      cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
    }
    
    cout << "0 - Sair" << endl;
    for(int i = 1; i <= (int)blogs.size(); i++){
      cout << i << " - " << blogs[i].get_blog_name() << endl;
    }
    
    cout << " > ";
    
    int option;
    cin >> option;
    
    if(option > blogs.size()){
      error = true;
      continue;
    }

    // TODO: put a try catch in here
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

Blog BlogView::create_page() throw(invalid_argument) {
	User user = Auth::get_current_user();
	Name blogAuthor = user.get_name();
    Name blogName;
    
	system("clear || cls");
	
	cout << "Um nome deve conter apenas letras e espacos. Alem disso, deve conter no maximo 20 caracteres." << endl;
	cout << "Digite um nome: ";
	try {
		cin >> blogName;	
	} catch(invalid_argument erro) {
		cout << "Nome em formato incorreto." << endl;
		cout << "Aperte 'ENTER' para retornar" << endl;
		getchar();getchar();
		throw invalid_argument("Nome em formato incorreto.");
	}
	
	Blog newBlog;
	newBlog.set(blogAuthor, blogName);
	
	cout << "Novo blog criada com sucesso!" << endl;
	cout << "Aperte 'ENTER' para retornar ao menu principal" << endl;
	getchar();getchar();
	
	return newBlog;
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
      cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
    }
    
    cout << "0 - Sair" << endl;
    cout << "1 - Listar blogs" << endl;
    if(Auth::user_logged()){
      cout << "2 - Meus blogs" << endl;
      cout << "3 - Criar blog" << endl;
    }
    
    cout << " > ";

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

void BlogView::edit_page(Blog blog, bool master) {
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
      cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
    }
    
    cout << "0 - Sair" << endl;
    cout << "1 - Acessar post" << endl;
    if(master){
      cout << "2 - Adicionar post" << endl;
      cout << "3 - Deletar post" << endl;
      cout << "4 - Deletar blog" << endl;
    }
    
    cout << " > ";
    
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

Comment CommentView::create_page() throw(invalid_argument) {
  User user = Auth::get_current_user();
  Name commentAuthor = user.get_name();
  Text commentContent;

  system("clear || cls");

  cout << "Um comentario deve conter no maximo 50 caracteres." << endl;		// TODO: conferir se e somente isso msm
  cout << "Digite um comentario: ";
  try {
  	cin >> commentContent;	
  } catch(invalid_argument erro) {
  	cout << "Comentario invalido." << endl;
  	cout << "Aperte 'ENTER' para retornar" << endl;
    getchar();getchar();
    throw invalid_argument("Comentario invalido.");
  }
  
  Comment newComment;
  newComment.set_author(commentAuthor);
  newComment.set_content(commentContent);

  cout << "Novo comentario criado com sucesso!" << endl;
  cout << "Aperte 'ENTER' para retornar ao menu principal" << endl;
  getchar(); getchar();
  
  return newComment;
}

void CommentView::show_page(Comment comment) {
  static const int EXIT = 0;
  static const int EDIT = 1;
  static const int DELETE = 2;

  bool exit = false;
  bool error = false;

  while(!exit) {
    system("clear || cls");

    cout << "Comentario" << endl;
    cout << endl;
    cout << comment.get_author() << endl;
    cout << comment.get_content() << endl;
    cout << endl;

    if(error) {
      error = false;
      cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
    }

    cout << "0 - Sair" << endl;
    cout << "1 - Editar" << endl;
    cout << "2 - Deletar" << endl;
    cout << endl;
    cout << "> ";

    int option;
    cin >>  option;

    try {
      switch(option) {
        case EXIT:
          exit = true;
          break;
        case EDIT:
          //CommentController::edit();
          break;
        case DELETE:
          //CommentController::destroy();
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

Comment CommentView::edit_page(Comment comment) throw(invalid_argument) {
  Text newContent;

  system("clear || cls");

  cout << "Mudando Comentario" << endl;
  cout << endl;
  cout << "Digite o novo comentario: ";

  try {
    cin >> newContent;
  } catch(invalid_argument erro) {
    cout << "Esse comentario e invalido!" << endl;
    cout << "Aperte 'ENTER' para voltar." << endl;
    getchar(); getchar();
    throw invalid_argument("Essa senha nao pode ser usada!");
  }

  try {
    comment.set_content(newContent);
    cout << "Comentario alterado com sucesso!" << endl;
    cout << "Aperte 'ENTER' para voltar." << endl;
    getchar(); getchar();
    return comment;
  } catch(invalid_argument arro) {
    cout << "Houve um erro no sistema! Tente novamente mais tarde." << endl;
    cout << "Aperte 'ENTER' para voltar." << endl;
    getchar(); getchar();
    throw invalid_argument("Houve um erro no sistema! Tente novamente mais tarde.");
  }
}

bool CommentView::delete_page() {
  const static int SIM = 1;
  const static int NAO = 2;

  system("clear || cls");
  cout << "Tem certeza que deseja deletar seu comentario?" << endl;
  cout << "1 - Sim" << endl;
  cout << "2 - Nao" << endl;
  
  int option;
  cin >> option;
  
  switch(option){
    case SIM:
      return true;
    case NAO:
      return false;
    default:
      throw invalid_argument("Opcao invalida, escolha uma das opcoes listadas na tela!");
  }
}


//------------------------------------------------
// POST VIEW CLASS
//------------------------------------------------

void PostView::create_page() {
  cout << "create Post page" << endl;
}

void PostView::show_page(vector<Post> posts) {
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
      cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
    } 

    cout << "0 - Sair" << endl;
    for(int i = 0; i < (int)posts.size(); i++){
      cout << i+1 << " - " << posts[i].get_content() << endl;
    }

    cout << " > ";
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

User UserView::create_page() throw(invalid_argument) {
  Name userName;
  Email userEmail;
  Password userPassword;

  system("clear || cls");
  
  cout << "Um nome deve conter apenas letras e espacos. Alem disso, deve conter no maximo 20 caracteres." << endl;
  cout << "Digite um nome: ";
  try {
  	cin >> userName;	
  } catch(invalid_argument erro) {
  	cout << "Nome em formato incorreto." << endl;
  	cout << "Aperte 'ENTER' para retornar" << endl;
    getchar();getchar();
    throw invalid_argument("Nome em formato incorreto.");
  }
  
  cout << "Um email deve estar no formato 'l(arroba)l.l'', onde 'l' sao palavras que contem apenas letras." << endl;
  cout << "Digite um e-mail: ";
  try {
  	cin >> userEmail;	
  } catch(invalid_argument erro) {
  	cout << "Email em formato incorreto." << endl;
  	cout << "Aperte 'ENTER' para retornar" << endl;
    getchar();getchar();
    throw invalid_argument("Email em formato incorreto.");
  }
  
  cout << "Uma seha deve conter ate 5 caracteres sem repeticao." << endl;
  cout << "Digite uma senha: ";
  try {
  	cin >> userPassword;	
  } catch(invalid_argument erro) {
  	cout << "Senha em formato incorreto." << endl;
  	cout << "Aperte 'ENTER' para retornar" << endl;
    getchar();getchar();
    throw invalid_argument("Senha em formato incorreto.");
  }
  
  try{
    if(Stub::user_find(userEmail)){
      throw invalid_argument("Email ja em uso.");
    }
  } catch(invalid_argument erro) {
    cout << "Email ja em uso." << endl;
  	cout << "Aperte 'ENTER' para retornar" << endl;
    getchar();getchar();
    throw invalid_argument("Email ja em uso.");
  }
  
  User newUser;
  newUser.set(userName, userEmail, userPassword);

  cout << "Nova conta criada com sucesso!" << endl << "Aperte 'ENTER' para retornar ao menu principal" << endl;
  getchar();getchar();
  
  return newUser;
}

void UserView::show_page(User user) {
  static const int EXIT = 0;
  static const int CHANGE_PASSWORD = 1;
  static const int DELETE_ACCOUNT = 2;

  bool exit = false;
  bool error = false;

  while(!exit) {
    system("clear || cls");

    cout << "Perfil" << endl;
    cout << endl;
    cout << "Nome: " << user.get_name() << endl;
    cout << endl;

    if(error) {
      error = false;
      cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
    }

    cout << "0 - Sair" << endl;
    cout << "1 - Mudar senha" << endl;
    cout << "2 - Deletar conta" << endl;
    cout << endl;
    cout << "> ";

    int option;
    cin >>  option;

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

User UserView::edit_page(User user) throw(invalid_argument) {
  Password  newPassword;

  system("clear || cls");

  cout << "Mudando Senha" << endl;
  cout << endl;
  cout << "Digite a nova senha: ";

  try {
    cin >> newPassword;
  } catch(invalid_argument erro) {
    cout << "Essa senha nao pode ser usada!" << endl;
    cout << "Aperte 'ENTER' para voltar." << endl;
    getchar(); getchar();
    throw invalid_argument("Essa senha nao pode ser usada!");
  }

  try {
    user.set_password(newPassword);
    cout << "Senha alterada com sucesso!" << endl;
    cout << "Aperte 'ENTER' para voltar." << endl;
    getchar(); getchar();
    return user;
  } catch(invalid_argument arro) {
    cout << "Houve um erro no sistema! Tente novamente mais tarde." << endl;
    cout << "Aperte 'ENTER' para voltar." << endl;
    getchar(); getchar();
    throw invalid_argument("Houve um erro no sistema! Tente novamente mais tarde.");
  }
}

// TODO: this should unlog you and make sure you return to home page
bool UserView::delete_page() {
  const static int SIM = 1;
  const static int NAO = 2;

  system("clear || cls");
  cout << "Tem certeza que deseja deletar sua conta?" << endl;
  cout << "1 - Sim" << endl;
  cout << "2 - Nao" << endl;
  
  int option;
  cin >> option;
  
  switch(option){
    case SIM:
      return true;
    case NAO:
      return false;
    default:
      throw invalid_argument("Opcao invalida, escolha uma das opcoes listadas na tela!");
  }
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
      cout << "Opcao invalida, escolha uma das opcoes listadas na tela!" << endl << endl;
    }

    cout << "0 - Sair" << endl;
    if(Auth::user_logged()){
      cout << "1 - Deslogar" << endl;
      cout << "2 - Perfil" << endl;
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

void AuthView::login_page() {
  bool error = false;
  
  Email email;
  Password password;
  
  system("clear || cls");
  cout << "Log-in" << endl << endl;
  
  cout << "E-mail: ";
  try {
    cin >> email;	
  } catch(invalid_argument erro) {
    error = true;
  }
  
  cout << "Senha: ";
  try {
  	cin >> password;
  } catch(invalid_argument erro) {
    error = true;
  }
  
  error |= !Stub::user_autenticate(email, password);
  
  AuthView::finish_login_page(error);
  
  if(not error) {
    Auth::login(Stub::get_user(email)); 
  } 
}

void AuthView::finish_login_page(bool error){
  system("clear || cls");
  if(error){
      cout << "E-mail ou senha incorretos!" << endl << "Aperte 'ENTER' para retonar ao menu principal." << endl;
  }
  else{
      cout << "Log-in realizado com sucesso!" << endl << "Aperte 'ENTER' para continuar." << endl;
  }
  getchar(); getchar(); 
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
