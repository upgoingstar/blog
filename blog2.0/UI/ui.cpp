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
								userLogged = MainMenu::logOut();
		                        break;
		            case ACCOUNT:
								AccountUI::execute();
		                        break;
		            case LISTBLOGS: 
								BlogsUI::execute(userLogged);
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
								userLogged = MainMenu::logIn();
		                        break;
		            case REGISTER:
								MainMenu::createAccount();
		                        break;
		            case LISTBLOGS: 
								BlogsUI::execute(userLogged);
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

void MainMenu::createAccount(){
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
			if(UIController::userFind(userEmail)){
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
		UIController::insertNewUser(newUser);
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
