//------------------------------------------------
// INCLUDE
//------------------------------------------------

#include "model.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// USER MODEL CLASS
//------------------------------------------------

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

//------------------------------------------------
// BLOG MODEL CLASS
//------------------------------------------------

vector<Blog> BlogModel::all() {

}

vector<Blog> BlogModel::from_user(User user) {

}

//------------------------------------------------
// POST MODEL CLASS
//------------------------------------------------

vector<Post> PostModel::all() {

}

vector<Post> PostModel::from_user(User user) {

}

//------------------------------------------------
// COMMENT MODEL CLASS
//------------------------------------------------

vector<Comment> CommentModel::all() {

}

vector<Comment> CommentModel::from_user(User user) {

}