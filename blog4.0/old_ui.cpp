//------------------------------------------------
// Includes
//------------------------------------------------
#include <bits/stdc++.h>
#include "ui.hpp"
#include "controllers.hpp"
#include "domains.hpp"
#include "entities.hpp"

using namespace std;

//------------------------------------------------
// Method Implementation of Class MainMenu
//------------------------------------------------
void MainMenu::execute(){
  
}

bool MainMenu::logIn(){
  cout << string(50, '\n');
  cout << "Log-in" << endl;
  
  string input;
  Password logPassword;
  Email logEmail;
  cout << "E-mail: " << endl;
  cin >> input;
  try{
    logEmail.set(input);
  }
  catch(invalid_argument erro){
    cout << "Email em formato incorreto." << endl;
    getchar();
    getchar();
    return false;
  }
  
  cout << "Senha: " << endl;
  cin >> input;
  try{
    logPassword.set(input);
  }
  catch(invalid_argument erro){
    cout << "Senha em formato incorreto." << endl;
    getchar();
    getchar();
    return false;
  }
  
  if(UIController::userAutenticate(logEmail,logPassword)){
    cout << "Log-in realizado com sucesso, aperte 'ENTER' para retonar ao menu principal" << endl;
    getchar();
    getchar();
    return true;
  }
  else{
    cout << "E-mail ou senha incorretos, aperte 'ENTER' para retonar ao menu principal" << endl;
    getchar();
    getchar();
    return false;
  }
}

bool MainMenu::logOut() throw(invalid_argument){
  cout << string(50, '\n');
  cout << "Tem certeza que deseja deslogar de sua conta?" << endl;
  cout << "1-Sim  2-Nao" << endl;
  int option;
  cin >> option;
  switch(option){
        case SIM:
        return false;
        case NAO:
            return true;
    default:
        throw invalid_argument("Invalid option!");
  }
  
}

void MainMenu::createAccount(){
  
}

//------------------------------------------------
// Method Implementation of Class AccountUI
//------------------------------------------------
void AccountUI::execute(){

}

//------------------------------------------------
// Method Implementation of Class BlogsUI
//------------------------------------------------
void BlogsUI::execute(bool userLogged) throw(invalid_argument){
  cout << string(50, '\n');
  cout << "Blogs" << endl;
  cout << "1 - Listar blogs" << endl;
  if(userLogged){
    cout << "2 - Meus blogs" << endl;
  }

  int option;
  cin >> option;

  switch(option){
    case LIST:
        BlogsUI::list();
        break;
    case MYBLOGS:
      if(userLogged){
        BlogsUI::myBlogs();
        break;
      }
    default:
      throw invalid_argument("Invalid option!");
      break;
  }
}

void BlogsUI::list(){

}

void BlogsUI::myBlogs(){
  cout << string(50, '\n');
  vector<Blog> myBlogsList = UIController::getBlogs(Auth::get());   
  for(auto blog : myBlogsList){
    cout << blog.get_blog_name().get() << endl;
  }
  getchar();
  getchar();
}

//------------------------------------------------
// Method Implementation of Class Auth
//------------------------------------------------
// Metodo quase sem relacai com o final
User Auth::get(){
  Email registredEmail;
  registredEmail.set("stub@stub.stub");
  
  Password registredPassword;
  registredPassword.set("stubp");

  Name registredName;
  registredName.set("Stub");

  User registredUser;
  registredUser.set(registredName, registredEmail, registredPassword);

  return registredUser;

}

