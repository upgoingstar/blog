//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include "view.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// BLOG VIEW CLASS
//------------------------------------------------

void BlogView::create_page() {
	cout << "create Blog page" << endl;
}

void BlogView::show_page(bool, unsigned int) {
	cout << "show Blog page" << endl;
}

void BlogView::edit_page(unsigned int) {
	cout << "edit Blog page" << endl;
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

Name UserView::field_name_page() {
	cout << "field page name" << endl;
	Name name;
	name.set("Algum Exemplo");
	return name;
}

Email UserView::field_email_page() {
	cout << "field page email" << endl;
	Email email;
	email.set("exemplo@exemplo.com");
	return email;
}

Password UserView::field_password_page() {
	cout << "field page password" << endl;
	Password password;
	password.set("123456");
	return password;
}

void UserView::create_page() {
	cout << string(50, '\n');
	string newName;
	cout << "Digite o nome de usuario desejado (deve conter apenas letras e espacos em branco e ate 20 caracteres): ";
	cin >> newName;
	
	string newEmail;
	cout << "Digite o e-mail desejado (deve estar no formato 'l(arroba)l.l'', onde 'l' sao palavras que contem apenas letras): ";
	cin >> newEmail;
	
	string newPassword;
	cout << "Digite a senha desejada (deve conter 5 caracters sem repeticao): ";
	cin >> newPassword;
	cout << endl;
	
	bool userAccepted = true;
	
	Name userName;
	Email userEmail;
	Password userPassword;
	
	try{
		userName.set(newName);
	}
	catch(invalid_argument erro){
		cout << "Nome de usuario em formato incorreto." << endl;
		userAccepted = false;
	}
	
	try{
		userEmail.set(newEmail);
		try{
			if(UserController::userFind(userEmail)){
				throw invalid_argument("E-mail already in use");
			}
		}
		catch(invalid_argument erro){
			cout << "Email ja em uso." << endl;
			userAccepted = false;
		}
		
	}
	catch(invalid_argument erro){
		cout << "Email em formato incorreto." << endl;
		userAccepted = false;
	}
	
	try{
		userPassword.set(newPassword);
	}
	catch(invalid_argument erro){
		cout << "Senha em formato incorreto." << endl;
		userAccepted = false;
	}
	
	if(userAccepted){
		User newUser;
		newUser.set(userName, userEmail, userPassword);
		UserController::insertNewUser(newUser);
		cout << "Nova conta criada com sucesso! Aperte 'ENTER' para retornar ao menu principal" << endl;
		getchar();
		getchar();
	}
	else{
		cout << "Nao foi possivel criar a conta. Aperte 'ENTER' para retornar ao menu principal" << endl;
		getchar();
		getchar();
	}
}

void UserView::show_page(bool, unsigned int) {
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
	bool userLogged = false;
	bool exit = false;
	
	while(!exit){
		cout << string(50, '\n');
		cout << "Bem-vindo a Blog - a platarfoma de blogs mais supimpa do mundo!\n" << endl;
	
		if(userLogged){
			cout << "1 - Deslogar" << endl;
			cout << "2 - Gerenciar conta" << endl;
		}	
		else{
			cout << "1 - Logar" << endl;
			cout << "2 - Registrar" << endl;	
		}
		cout << "3 - Blogs" << endl;
		cout << "4 - Sair" << endl;
		
		cout << "Escolha uma opcao: ";
		int option;
		cin >>	option;
		
		try{
			if(userLogged){
				switch(option){
		            case LOGOUT:
								userLogged = AuthView::logout_page();
		                        break;
		            case ACCOUNT:
								UserView::show_page();
		                        break;
		            case LISTBLOGS: 
								BlogView::show_page(userLogged);
		                        break;
		            case EXIT:   
								exit = true; 
								break;
					default:
						throw invalid_argument("Invalid option!");
		        }
			}
			else{
				switch(option){
		            case LOGIN:
								userLogged = AuthView::login_page();
		                        break;
		            case REGISTER:
								UserView::create_page();
		                        break;
		            case LISTBLOGS: 
								BlogView::show_page(userLogged);
		                        break;
		            case EXIT:    
								exit = true; 
								break;
					default:
						throw invalid_argument("Invalid option!");
		        }
			}
		}
		catch(invalid_argument erro){
			cout << "Opcao invalida, ecolha uma das opcoes listadas na tela!";
		}
	}
}

//------------------------------------------------
// AUTH VIEW CLASS
//------------------------------------------------

void AuthView::login_page() {
	cout << "login page" << endl;
}

void AuthView::logout_page() {
	cout << string(50, '\n');
	cout << "Tem certeza que deseja deslogar de sua conta?" << endl;
	cout << "1-Sim	2-Nao" << endl;
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
