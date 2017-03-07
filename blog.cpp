//#include <iostream>
//#include <string>
#include <bits/stdc++.h>
using namespace std;

#define LOGIN   1
#define SIGNUP  2
#define VISITOR 3
#define EXIT    4

#define NICKNAME_SIZE_LIMIT 20
#define PASSWORD_SIZE 5
#define PASSWORD_REPETICION_LIMIT 1

class User{
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
			if(!alfa(c)){
				return false;
			}
		}
		
		return true;
	}
	
	bool valid_password(string u_password){
		if(u_password.size() != PASSWORD_SIZE){
			return false;
		}
		
		for(auto c : u_password){
			int cnt = 0;

			for(auto h : u_password){
				if(c == h){
					cnt++;
				}
			}

			if(cnt > PASSWORD_REPETICION_LIMIT){
				return false;
			}
		}
		
		return true;
	}
	

	//TODO: do this in an efficient way
	//TODO: test later with a lot of cases
	bool valid_email(string u_email){

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
		grades.insert(grade);
	}

	int final_grade(){
		int grade = 0;

		for(auto i : grades){
			grade += i;
		}

		return grade / grades.size();
	}
}

//TODO: print this message red
void error_message(bool error){
	if(error){
		printf("invalid option");
	}
}

void login(){
	bool error = false;

	while(true){
		char op;
		
		render_start_page();
		error_message(error);
		get_input(op);

		if(op == LOGIN){
			render_login_page();
		}
		else if(op == SIGNUP){
			render_signup_page();
		}
		else if(op == VISITOR){
			User current_user = User.anonymous_user();
			render_initial_page(current_user);
		}
		else if(op ==  EXIT){
			break;
		}
		else{
			error == true;
		}
	}
}

void set_db(){
	if(db_exist()){
		read_db();
	}
	else{
		create_db();
	}
}

int main(){
	set_db(); // le os arquivos
	login();
}
