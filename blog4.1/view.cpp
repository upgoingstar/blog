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
int BlogView::index_page(vector<Blog> blogs, bool error){
  system("clear || cls"); 
  
  if(error) {
    cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
  }
  
  cout << "0 - Sair" << endl;
  for(int i = 0; i < (int)blogs.size(); i++){
    cout << i+1 << " - " << blogs[i].get_blog_name().get() << endl;
  }
  
  int option;
  cout << "Escolha um blog para acessar: ";
  cin >> option;
  
  return option;
}

void BlogView::create_page() {
  cout << "create Blog page" << endl;
}

int BlogView::show_page(bool error) {
  system("clear || cls");
  cout << "Blogs" << endl;
  
  if(error) {
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

  return option;
}

int BlogView::edit_page(Blog blog, bool master, bool error) {
  system("clear || cls");
  cout << blog.get_blog_name().get() << endl << endl;
  
  if(error){
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
  
  return option;
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

int PostView::show_page(vector<Post> posts, bool error) {
	
	system("cls || clear");
	
    if(error) {
      cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!" << endl << endl;
    }	
	
	cout << "0 - Sair" << endl;
	for(int i = 0; i < (int)posts.size(); i++){
		cout << i+1 << " - " << posts[i].get().get_content().get() << endl;
	}
	
	cout << "Escolha o post que deseja acessar: ";
	int option;
	cin >> option;
	
	return option;

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

void UserView::create_page(string& newName, string& newEmail, string& newPassword) {
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
  
  bool userAccepted = true;
  
  Name userName;
  Email userEmail;
  Password userPassword;
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

int WelcomeView::home_page(bool error) {
    system("clear || cls");
    cout << "Bem-vindo a Blog - a platarfoma de blogs mais supimpa do mundo!" << endl << endl;
    
    if(error) {
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
	return option;
}

//------------------------------------------------
// AUTH VIEW CLASS
//------------------------------------------------

void AuthView::login_page(string &email, string &password) {
  bool error = false;
	
  system("clear || cls");
  cout << "Log-in" << endl << endl;
  
  cout << "E-mail: ";
  cin >> email;
  
  cout << "Senha: ";
  cin >> password;
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
  system("clear || cls");
  cout << "Tem certeza que deseja deslogar de sua conta?" << endl;
  cout << "1 - Sim" << endl;
  cout << "2 - Nao" << endl;
  
  int option;
  cin >> option;
  
  return option;
}
