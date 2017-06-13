// INCLUDES
#include "../../lib/entity/post.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
Post::Post(Name author, Text post_content) {
  Content::set(author, post_content);
  Post::allow_comments();
}

Post::~Post() {}

void Post::allow_comments() {
  comments_allowed = true;
}

void Post::disallow_comments() {
  comments_allowed = false;
  this->comments.clear();
}

void Post::add_comment(Comment comment) throw(invalid_argument) {
  if(comments_allowed and number_comments[comment.get_author()] < comments_limit) {
    number_comments[comment.get_author()]++;
    this->comments.push_back(comment);
  }
  else {
    throw invalid_argument("This comment is not allowed!");
  }
}

vector<Comment> Post::get_comments() {
  if(this->comments.empty()){
    throw invalid_argument("There is no comments!");
  }
  return this->comments;
}