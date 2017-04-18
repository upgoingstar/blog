//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include "entities.hpp"

//------------------------------------------------
// Method Implementation of Class User
//------------------------------------------------

User::User(){
    anonymous = true;
}

~User::User(){}

void User::set(Name n, Email e, Password p){
  name = n;
  password = p;
  email = e;
}

Name User::get_name(){
  return name;
}

bool check_user(Email e, Password p){
  if(email != e || password != p){
    throw invalid_argument( "That is not yout email or password!" );
  }
};

//------------------------------------------------
// Method Implementation of Class Content
//------------------------------------------------

Content::Content(){}

~Content::Content(){}

void Content::set(Name n, Text t){
  this->author = n;
  this->content = t;
}

void Content::add_avaliation(Avaliation a){
  this->avaliations.push_back(a);
}

Name Content::get_author(){
  return this->author;
}

Text Content::get_content(){
  return this->content;
}

Avaliation Content::get_final_avaliation(){
  int total_sum = '0';
  int total_size = this->avaliations.size();

  for(auto a : this->avaliations){
    total_sum += this->avaliations;
  }

  Avaliation ans = total_sum / total_size;

  return ans;
}

//------------------------------------------------
// Method Implementation of Class Comment
//------------------------------------------------

Comment(){}

~Comment(){}

//------------------------------------------------
// Method Implementation of Class Post
//------------------------------------------------

Post::Post(){}

~Post::Post(){}

void Post::add_comment(Comment c){
  comments.push_back(c);
}

vector<Comment> Post::get_comments(){
  return comments;
}
