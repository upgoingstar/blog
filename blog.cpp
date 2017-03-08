#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <map>
//#include <bits/stdc++.h>
using namespace std;

// Colors
#define KNRM  "\x1b[0m"
#define KRED  "\x1b[31m"
#define KGRN  "\x1b[32m"
#define KYEL  "\x1b[33m"
#define KBLU  "\x1b[34m"
#define KMAG  "\x1b[35m"
#define KCYN  "\x1b[36m"
#define KWHT  "\x1b[37m"
#define RESET "\x1b[0m"

#define LOGIN   '1'
#define SIGNUP  '2'
#define VISITOR '3'
#define EXIT    '4'

#define NO_MSG  0
#define INV_OP  1
#define NICK_E  2
#define MAIL_E  3
#define PASS_E  4
#define N_USER  5

#define NICKNAME_SIZE_LIMIT 20
#define PASSWORD_SIZE 5
#define PASSWORD_REPETICION_LIMIT 1

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int error;

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
		anonymous = false;
	}

	User(){ anonymous = true; };

	static bool valid_nickname(string u_nickname){
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

	static bool valid_password(string u_password){
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

	static bool valid_email(string u_email){
		for(int i = 0; i < u_email.size(); i++){
			if(!isalpha(u_email[i]) && u_email[i] != '@' && u_email[i]!= '.'){
				return false;
			}

			if(i > 0 && isalpha(u_email[i-1]) && isalpha(u_email[i])){
				u_email.erase(i--);
			}
		}

		if(u_email.size() != 5 || u_email[1] != '@' || u_email[3] != '.' || !isalpha(u_email[0]) || !isalpha(u_email[2]) || !isalpha(u_email[4])){
			return false;
		}

		return true;
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

void get_enter(){
	char a;
	
	do{
		a = getchar();
	}while(a != '\n');
}

void get_input(int* ch) {
  struct termios oldt;
  struct termios newt;
  tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
  newt = oldt; /* copy old settings to new settings */
  newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
  (*ch) = getchar(); /* standard getchar call */
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
  (*ch) -= 48; /*return received char */
}

void get_input(char* ch) {
  struct termios oldt;
  struct termios newt;
  tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
  newt = oldt; /* copy old settings to new settings */
  newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
  (*ch) = getchar(); /* standard getchar call */
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
}

//TODO: create a class to deal with db queries
vector<User> registred_Users;
map<string,User*> users_Informations; //OBTER TODOS OS DADOS DO USUARIO APARTIR DO NOME

void error_message(){
	switch(error){
		case INV_OP:
			cout << KRED "Invalid option" RESET << endl;
			break;
		case NICK_E:
			cout << KRED "The username must contain only letters and at most 20 characters" RESET << endl;
			break;
		case PASS_E:
			cout << KRED "The password must contain 5 characters whitout repetition" RESET << endl;
			break;
		case MAIL_E:
			cout << KRED "The e-mail must contain only letters in the format: letters@letters.letters" RESET << endl;
			break;
		case N_USER:
			cout << KRED "The nickname or the password is invalid" RESET << endl;
	}

	error = NO_MSG;
}

void render_start_page(){
	system(CLEAR);
	cout << "1 - Sign In" << endl;
	cout << "2 - Sign Up" << endl;
	cout << "3 - Visitant mode" << endl;
	cout << "4 - Exit" << endl;
}

string get_nickname(){
	string nickname;
	
	do{
		system(CLEAR);

		error_message();

		cout << "Username: ";
		getline(cin, nickname);

		error = NICK_E;
	}while(!User::valid_nickname(nickname) || users_Informations.count(nickname));
	
	error = NO_MSG;
	
	return nickname;
}

string get_password(){
	string password;
	
	do{
		system(CLEAR);

		error_message();

		cout << "Password: ";
		getline(cin, password);

		error = PASS_E;
	}while(!User::valid_password(password));
	
	error = NO_MSG;

	return password;
}

string get_email(){
	string email;
	
	do{
		system(CLEAR);

		error_message();

		cout << "Email: ";
		getline(cin, email);

		error = MAIL_E;
	}while(!User::valid_email(email));
	
	error = NO_MSG;

	return email;
}

void successful_sign_up_message(string nickname){
	system(CLEAR);

	cout << "Congratulations " << nickname << "! You are now a member of the blog BLOG!\n";
	cout << "Press ENTER to return to the initial menu and Sing In\n";
	
	get_enter();
}

void render_signup_page(){
	string nickname = get_nickname();
	string password = get_password();
	string email = get_email();

	User valid_user(nickname, password, email);
	registred_Users.push_back(valid_user);
	users_Informations.insert(make_pair(nickname,&registred_Users[registred_Users.size()-1]));

	successful_sign_up_message(nickname);
}

void render_login_page(){
	char op;
	
	string nick;
	string password;

	do{
		system(CLEAR);
		
		error_message();

		cout << "Username: ";
		getline(cin, nick);

		cout << "Password: ";
		getline(cin, password);

		cout << "1 - Login" << endl;
		cout << "2 - Exit" << endl;
		cin >> op;
		getchar();
		
		error = N_USER;
		if(op == LOGIN && !users_Informations.count(nick)) continue;
	}while(op == LOGIN && users_Informations[nick]->password != password);
	
	error = NO_MSG;

	User current_user = *users_Informations[nick];
	//render_blog(current_user);
}

void render_initial_page(){
	bool not_leave = true;

	error = NO_MSG;
	
	while(not_leave){
		char op;

		render_start_page();
		error_message();

		cin >> op;
		getchar();
		
		switch(op){
			case LOGIN:
				render_login_page();
				break;
			case SIGNUP:
				render_signup_page();
				break;
			case VISITOR:
				User visitor;
				//render_blog(visitor);
				break;
			case EXIT:
				not_leave = false;
				break;
			default:
				error = INV_OP;
		}
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
	render_initial_page();
}
