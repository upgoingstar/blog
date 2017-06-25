#include "model.hpp"
#include <bits/stdc++.h>
using namespace std;

// TODO: verify if opened ok
// TODO: add try catch

// USER MODEL CLASS ------------------------------------------------------------------------------------------ 

const string UserModel::FILENAME = ".users.txt";

vector<User> UserModel::all() {
	vector<User> users;

	ofstream file(FILENAME);

	while(file.eof()) {
		User user;
		Id id;
		Name name;
		Email email;
		Password password;

		file << id << name << email << password;

		user.set(id, name, email, password);
		users.push_back(user);
	}

	file.close();

	return users;
}

void UserModel::add(User user) {
	ofstream file(FILENAME);
	file << user.get_id() << " " << user.get_name() << " " << user.get_email() << " " << user.get_password() << endl;
	file.close();
}

void UserModel::update(User user) {
	ifstream file(FILENAME);
	ofstream file_aux(FILENAME + "_copy");

	while(file.eof()) {
		Id id;
		Name name;
		Email email;
		Password password;

		file >> id >> name >> email >> password;
		
		if(user.get_id() != id) {
			file_aux << user.get_id() << " " << user.get_name() << " " << user.get_email() << " " << user.get_password() << endl;
		} else {
			file_aux << id << " " << name << " " << email << " " << password << endl;
		}
	}

	file.close();
	file_aux.close();

	if(not remove(FILENAME.c_str())) {
		throw invalid_argument("Não foi possível excluir o arquivo");
	}
	if(not rename((FILENAME + "_copy").c_str(), FILENAME.c_str())) {
		throw invalid_argument("Não foi possível renomear o arquivo");
	}
}

void UserModel::destroy(User user) {
	ifstream file(FILENAME);
	ofstream file_aux(FILENAME + "_copy");

	while(file.eof()) {
		Id id;
		Name name;
		Email email;
		Password password;

		file >> id >> name >> email >> password;

		if(user.get_id() != id) {
			file_aux << user.get_id() << " " << user.get_name() << " " << user.get_email() << " " << user.get_password() << endl;
		}
	}

	file.close();
	file_aux.close();

	remove(FILENAME.c_str());
	rename((FILENAME + "_copy").c_str(), FILENAME.c_str());
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