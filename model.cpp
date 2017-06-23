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

void UserModel::add(User user) {

}

User UserModel::find(User user) {

}

void UserModel::update(User user) {

}

void UserModel::destroy(User user) {

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

vector<Post> PostModel::all_from(Blog blog) {

}

vector<Post> PostModel::from_user(Blog blog, User user) {

}

//------------------------------------------------
// COMMENT MODEL CLASS
//------------------------------------------------

vector<Comment> CommentModel::all_from(Post post) {

}

vector<Comment> CommentModel::from_user(Post post, User user) {

}