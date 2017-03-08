#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <map>
// #include <bits/stdc++.h>
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

#define INV_OP  1
#define NICK_E  2
#define MAIL_E  3
#define PASS_E  4

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
		anonymous = false;
	}

	User(){
		anonymous = true;
	}

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


	//TODO: redo this in an efficient way
	//TODO: test later with a lot of cases
	// a@a.a -> passa
	// @a.a  -> nao pode passar
	// a@.a  -> nao pode passar
	// a@a.  -> nao pode passar
	static bool valid_email(string u_email){
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

vector<User> registred_Users;
map<string,User*> users_Informations; //OBTER TODOS OS DADOS DO USUARIO APARTIR DO NOME

//TODO: essa prórpia função tornar error nulo
void error_message(int error){
	switch(error){
		case INV_OP:
			printf(KRED "Invalid option\n" RESET);
			break;
		case NICK_E:
			printf(KRED "The username must contain only letters and at most 20 characters\n" RESET);
			break;
		case PASS_E:
			printf(KRED "The password must contain 5 characters whitout repetition\n" RESET);
			break;
		case MAIL_E:
			printf(KRED "The e-mail must contain only letters in the format: paradinhas@paradinhas.paradnhas\n" RESET);
			break;
	}
}

void render_start_page(){
	system(CLEAR);
	cout << "Escolha uma opcao bacana\n";
	cout << "1 - Sign In.\n";
	cout << "2 - Sign Up.\n";
	cout << "3 - Visitant mode.\n";
	cout << "4 - Exit.\n";
}

//TODO: refatorar
string get_nickname(){
	string nickname;

	system(CLEAR);

	cout << "Username: ";
	cin >> nickname;

	while(!User::valid_nickname(nickname)){
		system(CLEAR);

		error_message(NICK_E);

		cout << "Username: ";

		cin >> nickname;
	}

	return nickname;
}
//TODO: refatorar
string get_password(){
	system(CLEAR);

	string password;

	cout << "Password: ";
	cin >> password;

	while(!User::valid_password(password)){
		system(CLEAR);
		error_message(PASS_E);
		cout << "Password: ";
		cin >> password;
	}

	return password;
}
//TODO: refatorar
string get_email(){
	system(CLEAR);

	string email;

	cout << "E-mail: ";
	cin >> email;
	while(!User::valid_email(email)){
		system(CLEAR);
		error_message(MAIL_E);
		cout << "E-mail: ";
		cin >> email;
	}

	return email;
}
//TODO: refatorar
void successful_sign_up_message(string nickname){
	system(CLEAR);

	cout << "Congratulations " << nickname << "! You are now a member of the blog BLOG!\n";
	cout << "Press ENTER to return to the initial menu and Sing In\n";

	getchar();
	getchar();
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
	//render_blog(current_user);

}

void render_initial_page(){
	int error = 0;
	bool not_leave = true;

	while(not_leave){
		char op;

		render_start_page();
		error_message(error);

		error = 0;

		get_input(&op);

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
				error = 1;
				break;
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
