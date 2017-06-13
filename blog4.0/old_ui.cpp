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

