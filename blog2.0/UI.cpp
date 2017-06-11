#include "UI.h"
#include "string"
#include "iostream"

using namespace std;

void MainMenu::execute(){
	while(true){
		cout << string(50, '\n');
		cout << "Bem-vindo a Blog - a platarfoma de blogs mais supimpa do mundo!\n" << endl;
	
		if(USERLOGGED){
			cout << "1 - Deslogar" << endl;
			cout << "2 - Editar conta" << endl;
		}	
		else{
			cout << "1 - Logar" << endl;
			cout << "2 - Registrar" << endl;	
		}
		cout << "3 - Listar blogs" << endl;
		cout << "4 - Sair" << endl;
		
		cout << "Escolha uma opcao: ";
		int option;
		cin >>	option;
		
		try{
			if(USERLOGGED){
				switch(option){
		            case LOGOUT:
								LogOut::execute();
		                        break;
		            case ACCOUNT:
								EditAccount()::execute;
		                        break;
		            case LISTBLOGS: 
								ListBlogs()::execute;
		                        break;
		            case EXIT:    
								return;
					default:
						throw invalid_argument("Invalid option!");
		        }
			}
			else{
				switch(option){
		            case LOGIN:
								LogIn()::execute;
		                        break;
		            case REGISTER:
								CreateAccount()::execute;
		                        break;
		            case LISTBLOGS: 
								ListBlogs()::execute;
		                        break;
		            case EXIT:    
								return;
					default:
						throw invalid_argument("Invalid option!");
		        }
			}
		}
		catch(invalid_argument erro){
			cout << "Opcao invalida, escolha uma das opcoes listadas na tela!";
		}
	}
}
