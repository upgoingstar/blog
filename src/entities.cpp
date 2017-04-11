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
// Method Implementation of Class Post
//------------------------------------------------

Post::Post(){}

~Post::Post(){}

void Post::set(Name n, Text t){
  author = n;
  content = t;
}

void Post::add_avaliation(Avaliation a){
  avaliations.push_back(a);
}

void Post::add_comment(Comment c){
  comments.push_back(c);
}

Name Post::get_author(){
  return author;
}

Text Post::get_content(){
  return content;
}

Avaliation Post::get_final_avaliation(){
  int total_sum = '0';
  int total_size = avaliations.size();

  for(auto a : avaliations){
    total_sum += avaliations;
  }

  Avaliation ans = total_sum / total_size

  return ans;
}

vector<Comment> Post::get_comments(){
  return comments;
}

//------------------------------------------------
// Method Implementation of Class Comment
//------------------------------------------------

Comment(){}

~Comment(){}
