#include "model.hpp"
#include <bits/stdc++.h>
using namespace std;

// TODO: verify if opened ok
// TODO: add try catch

// USER MODEL CLASS ------------------------------------------------------------------------------------------ 

	const string UserModel::FILENAME = "users.txt";

	vector<User> UserModel::get_all() {
		vector<User> users;

		ifstream file(FILENAME);

		while(!file.eof()) {
			User user;
			Id id;
			Name name;
			Email email;
			Password password;
			
			string aux;
			
			getline(file,aux);
			if(file.eof()) break;
			
			int pos;
			pos = aux.find('#');
			id.set(aux.substr(0, pos));
			aux.erase(0,pos+1);
			
			pos = aux.find('#');
			name.set(aux.substr(0, pos));
			aux.erase(0,pos+1);
			
			pos = aux.find('#');
			email.set(aux.substr(0, pos));
			aux.erase(0,pos+1);
			
			pos = aux.find('#');
			password.set(aux.substr(0, pos));
			
			user.set(id, name, email, password);
			users.push_back(user);
		}

		file.close();

		return users;
	}

	void UserModel::add(User user) {
		ofstream file(FILENAME, ios::app);
		file << user.get_id() << "#" << user.get_name() << "#" << user.get_email() << "#" << user.get_password() << "#\n";
		file.close();
	}
	
	void UserModel::add(vector<User> users) {
		ofstream file(FILENAME, ios::app);
		for(int i = 0; i < (int)users.size(); i++){
			file << users[i].get_id() << "#" << users[i].get_name() << "#" << users[i].get_email() << "#" << users[i].get_password() << "#\n";
		}
		file.close();
	}
	
	void UserModel::update(User user) {
		vector<User> users = UserModel::get_all();
		
		bool exist = false;
		for(int i = 0; i < (int)users.size(); i++){
			if(user.get_id() == users[i].get_id()){
				users[i] = user;
				exist = true;
				break;
			}
		}
		
		if(exist){
			remove("users.txt");
			UserModel::add(users);
		}
	}

	void UserModel::destroy(User user) {
		vector<User> users = UserModel::get_all();
		
		int pos = -1;
		for(int i = 0; i < (int)users.size(); i++){
			if(user.get_id() == users[i].get_id()){
				pos = i;
				break;
			}
		}
		
		if(pos != -1){
			remove("users.txt");
			
			ofstream file(FILENAME, ios::app);
			for(int i = 0; i < (int)users.size(); i++){
				if(i != pos){
					file << users[i].get_id() << "#" << users[i].get_name() << "#" << users[i].get_email() << "#" << users[i].get_password() << "#\n";
				}
			}
			file.close();
		}
	}

	bool UserModel::find(Email email){
		vector<User> users = UserModel::get_all();
		
		bool exist = false;
		for(int i = 0; i < (int)users.size(); i++){
			if(email == users[i].get_email()){
				exist = true;
				break;
			}
		}
		
		return exist;
	}
	
	bool UserModel::autenticate(Email email, Password password){
		vector<User> users = UserModel::get_all();
		
		bool exist = false;
		for(int i = 0; i < (int)users.size(); i++){
			if(email == users[i].get_email() and password == users[i].get_password()){
				exist = true;
				break;
			}
		}
		
		return exist;
	}

	User UserModel::get(Email email){
		vector<User> users = UserModel::get_all();
		
		for(int i = 0; i < (int)users.size(); i++){
			if(email == users[i].get_email()){
				return users[i];
			}
		}
		
	}

// BLOG MODEL CLASS ------------------------------------------------------------------------------------------

	// vector<Blog> BlogModel::all() {

	// }

	// vector<Blog> BlogModel::from_user(User user) {

	// }

// POST MODEL CLASS ------------------------------------------------------------------------------------------

	// vector<Post> PostModel::all_from(Blog blog) {

	// }

	// vector<Post> PostModel::from_user(Blog blog, User user) {

	// }

// COMMENT MODEL CLASS ---------------------------------------------------------------------------------------

	// vector<Comment> CommentModel::all_from(Post post) {

	// }

	// vector<Comment> CommentModel::from_user(Post post, User user) {

	// }
