// INCLUDES
#include "../../lib/entity/blog.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
Blog::Blog(){}

Blog::~Blog() {}

void Blog::set(Name author, Name blog_name) throw(invalid_argument) {
	if(author.empty() || blog_name.empty())
		throw invalid_argument("Invalid blog name or author!");
  this->author = author;
  this->blog_name = blog_name;
}

Name Blog::get_author() {
  if(this->author.empty()){
    throw invalid_argument("There is no author!");
  }
  return this->author;
}

Name Blog::get_blog_name() {
  if(this->blog_name.empty()){
    throw invalid_argument("This blog has no name!");
  }
  return this->blog_name;
}

/*
  Add a post in the blog if you are the creator for the blog.
*/
void Blog::add_post(Post post) throw(invalid_argument) {
  if(this->author != post.get_author()) {
    throw invalid_argument("You are not allowed to post in this blog!");
  }
  else {
    this->posts.push_back(post);
  }
}

vector<Post> Blog::get_posts() {
  if(this->posts.empty()){
    throw invalid_argument("There is no posts in this Blog!");
  }
  return this->posts;
}
