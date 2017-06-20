//------------------------------------------------
// INCLUDE
//------------------------------------------------

#include "model.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// BLOG MODEL CLASS
//------------------------------------------------

// TODO: put stub in here
vector<Blog> BlogModel::all() {

}

// TODO: put stub in here
vector<Blog> BlogModel::from_user(User user) {

}

//------------------------------------------------
// COMMENT MODEL CLASS
//------------------------------------------------

// TODO: put stub in here
vector<Comment> CommentModel::all() {

}

// TODO: put stub in here
vector<Comment> CommentModel::from_user(User user) {

}

//------------------------------------------------
// POST MODEL CLASS
//------------------------------------------------

// TODO: put stub in here
vector<Post> PostModel::all() {

}

// TODO: put stub in here
vector<Post> PostModel::from_user(User user) {

}

//------------------------------------------------
// USER MODEL CLASS
//------------------------------------------------

// TODO: put stub in here
vector<User> UserModel::all() {

}

void UserModel::save(User user) {
  commandSQL = "INSERT INTO users VALUES (";
  commandSQL += "'" + user.get_name().get() + "', ";
  commandSQL += "'" + user.get_email().get() + "', ";
  commandSQL += "'" + user.get_password().get() + "')";
}

void UserModel::update(User user) {
	commandSQL = "UPDATE users ";
  commandSQL += "SET name = '" + user.get_name().get();
  commandSQL += "', password = '" + user.get_password().get();
  commandSQL += "' WHERE email = " + user.get_email().get();
}

void UserModel::destroy(User user) {
	comandoSQL = "DELETE FROM users WHERE email = ";
	comandoSQL += user.get_email().get();
}