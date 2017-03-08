//#include <iostream>
//#include <string>
#include <bits/stdc++.h>
using namespace std;

#define LOGIN   '1'
#define SIGNUP  '2'
#define VISITOR '3'
#define EXIT    '4'
#define PASS_E  4
#define MAIL_E  3
#define NICK_E  2

#define NICKNAME_SIZE_LIMIT 20
#define PASSWORD_SIZE 5
#define PASSWORD_REPETICION_LIMIT 1

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


class User{
public:
	string nickname;
	string password;
	string email;
	
	bool anonymous;

	User(string u_nickname, string u_password, string u_email){
		nickname = u_nickname;
		password = u_password;
		email = u_email;
	}
	
	bool valid_nickname(string u_nickname){
		if(u_nickname.size() > NICKNAME_SIZE_LIMIT){
			return false;
		}
		
		for(auto c : u_nickname){
			if(!isalpha(c)){
				return false;
			}
		}
		
		return true;
	}
	
	bool valid_password(string u_password){
		if(u_password.size() != PASSWORD_SIZE){
			return false;
		}
		
		map<char,int> repeat;

		for(auto c : u_password){
			
			repeat[c]++;

			if(repeat[c] > PASSWORD_REPETICION_LIMIT){
				return false;
			}
		}
		
		return true;
	}
	

	//TODO: do this in an efficient way
	//TODO: test later with a lot of cases
	bool valid_email(string u_email){
		char valid[3];
		int i = 0;
		valid[0] = '@';
		valid[1] = '.';
		valid[2] = 'a';
		for(auto c : u_email){
			if(!isalpha(c)){
				if(c != valid[i])
					return false;
				else
					i++;
			}
		}
		return true;
	}
	void anonymous_user(){
		anonymous = true;
	}
};

//TODO: add comment structure
class Post{
	string author;
	string post;

	vector<int> grades; //keep all grades given to a single post to later calculate it

	Post(string u_author, string u_post){
		author = u_author;
		post = u_post;
	}
	
	//TODO: find a way to count how many way a person already comment, a person can only comment 5 times
	void add_comment(){}

	//TODO: learn how does this work. A person can give grades more than 1 time?
	//TODO: verify problems with this implementation
	//TODO: verify if the grade send if between 1 and 5
	void add_grade(int grade){
		grades.push_back(grade);
	}

	int final_grade(){
		int grade = 0;

		for(auto i : grades){
			grade += i;
		}

		return grade / grades.size();
	}
};


vector<User> registred_Users;
map<string,User*> users_Informations; //OBTER TODOS OS DADOS DO USUARIO APARTIR DO NOME 

//TODO: print this message red
void error_message(int error){
	if(error == 1)
		cout << "Invalid option\n";
	else if(error == NICK_E)
		cout << "The username must be unic, contain only letters and at most 20 characters\n";
	else if(error == PASS_E)
		cout << "The password must contain 5 characters whitout repetition\n";
	else if(error == MAIL_E)
		cout << "The e-mail must contain only letters in the format: paradinhas@paradinhas.paradnhas\n";

}

void render_start_page(){
	system(CLEAR);
	cout << "Escolha uma opcao bacana\n";
	cout << "1 - Sing in.\n";
	cout << "2 - Sing up.\n";
	cout << "3 - Visitant mode.\n";
	cout << "4 - EXIT.\n";
}

void render_signup_page(){
	system(CLEAR);

	string nick, password, email;
	User new_user(nick,password,email);

	cout << "Username: ";
	getline(cin,nick);
	while(!new_user.valid_nickname(nick) || users_Informations.count(nick)){
		system(CLEAR);
		error_message(NICK_E);
		cout << "Username: ";
		getline(cin,nick);
	}

	system(CLEAR);

	cout << "Password: ";
	getline(cin,password);
	while(!new_user.valid_password(password)){
		system(CLEAR);
		error_message(PASS_E);
		cout << "Password: ";
		getline(cin,password);
	}

	system(CLEAR);

	cout << "E-mail: ";
	getline(cin,email);
	while(!new_user.valid_email(email)){
		system(CLEAR);
		error_message(MAIL_E);
		cout << "E-mail: ";
		getline(cin,email);
	}

	system(CLEAR);

	User valid_user(nick,password,email);
	registred_Users.push_back(valid_user);
	users_Informations.insert(make_pair(nick,&registred_Users[registred_Users.size()-1]));
	cout << "Congratulations " << valid_user.nickname << "! You are now a member of the blog BLOG!\n";
	cout << "Press ENTER to return to the initial menu and Sing In\n";
	getchar();

}

void render_login_page(){
	string nick, password;
	bool retry;

	system(CLEAR);

	cout << "Username: ";
	cin >> nick;
	while(!users_Informations.count(nick)){
		cout << "Invalid Username!\n";
		cout << "0 - EXIT\n";
		cout << "1 - Try again\n";
		cin >> retry;
		if(!retry) return;
		system(CLEAR);
		cout << "Username: ";
		cin >> nick;
	}
	
	system(CLEAR);

	cout << "Password: ";
	cin >> password;
	while(!(users_Informations[nick]->password == password)){
		cout << "Invalid Password!\n";
		cout << "0 - EXIT\n";
		cout << "1 - Try again\n";
		cin >> retry;
		if(!retry) return;
		system(CLEAR);
		cout << "Password: ";
		cin >> password;
	}

	User current_user = *users_Informations[nick];
	//render_initial_page(current_user);

}

void initial_menu(){
	int error = 0;

	while(true){
		char op;
		
		render_start_page();
		error_message(error);
		error = 0;
		cin >> op;
		getchar();
		//get_input(op);

		if(op == LOGIN){
			render_login_page();
		}
		else if(op == SIGNUP){
			render_signup_page();
		}
		else if(op == VISITOR){
			User current_user("0","9","1");
		getchar();
			current_user.anonymous_user();
			//render_initial_page(current_user);
		}
		else if(op ==  EXIT)
			break;
		else
			error = 1;
	}
}

// void set_db(){
// 	if(db_exist()){
// 		read_db();
// 	}
// 	else{
// 		create_db();
// 	}
// }

int main(){
	//set_db(); // le os arquivos
	initial_menu();
}
