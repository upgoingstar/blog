#include "model.hpp"
#include <bits/stdc++.h>
using namespace std;

// TODO: verify if opened ok
// TODO: add try catch

// USER MODEL CLASS ------------------------------------------------------------------------------------------ 

vector<User> UserModel::all() {
	Id id;
	Name name;
	Email email;
	Password password;
	User user;
	vector<User> users;
	ofstream file(userFilename);
	while(file.eof()) {
		User user;
		file >> id >> name >> email >> password;
		user.set_id(id);
		user.set(name, email, password);
		users.push_back(user);
	}
	file.close();
	return users;
}

void UserModel::add(User user) {
	ofstream file(userFilename);
	file << user.get_id() << " " << user.get_name() << " " << user.get_email() << " " << user.get_password() << endl;
	file.close();
}

void UserModel::update(User user) {
	Id id;
	Name name;
	Email email;
	Password password;
	ofstream file(userFilename);
	ofstream file_aux(userFilename + "_copy");
	while(file.eof()) {
		file >> id >> name >> email >> password;
		if(user.get_id() != id) {
			file_aux << user.get_id() << " " << user.get_name() << " " << user.get_email() << " " << user.get_password() << endl;
		} else {
			file_aux << id() << " " << name() << " " << email() << " " << password() << endl;
		}
	}
	file.close();
	file_aux.close();
	remove(userFilename);
	rename(userFilename + "_copy", userFilename);
}

void UserModel::destroy(User user) {
	Id id;
	Name name;
	Email email;
	Password password;
	ofstream file(userFilename);
	ofstream file_aux(userFilename + "_copy");
	while(file.eof()) {
		file >> id >> name >> email >> password;
		if(user.get_id() != id) {
			file_aux << user.get_id() << " " << user.get_name() << " " << user.get_email() << " " << user.get_password() << endl;
		}
	}
	file.close();
	file_aux.close();
	remove(userFilename);
	rename(userFilename + "_copy", userFilename);
}

// BLOG MODEL CLASS ------------------------------------------------------------------------------------------

vector<Blog> BlogModel::all() {

}

vector<Blog> BlogModel::from_user(User user) {

}

// POST MODEL CLASS ------------------------------------------------------------------------------------------

vector<Post> PostModel::all_from(Blog blog) {

}

vector<Post> PostModel::from_user(Blog blog, User user) {

}

// COMMENT MODEL CLASS ---------------------------------------------------------------------------------------

vector<Comment> CommentModel::all_from(Post post) {

}

vector<Comment> CommentModel::from_user(Post post, User user) {

}