//------------------------------------------------
// Includes
//------------------------------------------------

  #include "../hdr/entities.hpp"
  #include <bits/stdc++.h>
  using namespace std;

//------------------------------------------------
// Method Implementation of Class User
//------------------------------------------------

User::User(){
    this->anonymous = true;
}

User::~User(){}

void User::set(Name name, Email email, Password password){
  this->name = name;
  this->password = password;
  this->email = email;
  this->anonymous = false;
}

Name User::get_name(){
  return this->name;
}

void User::check_user(Email email, Password password){
  if(this->email != email || this->password != password){
    throw invalid_argument( "That is not yout email or password!" );
  }
};

//------------------------------------------------
// Method Implementation of Class Content
//------------------------------------------------

Content::Content(){}

Content::~Content(){}

void Content::set(Name name, Text text){
  this->author = name;
  this->content = text;
}

void Content::add_avaliation(Avaliation avaliation){
  this->avaliations.push_back(avaliation);
}

Name Content::get_author(){
  return this->author;
}

Text Content::get_content(){
  return this->content;
}

Avaliation Content::get_avaliation(){
  int total_sum = 0;
  int total_size = this->avaliations.size();

  for(Avaliation avaliation : this->avaliations){
    total_sum += avaliation.get();
  }

  Avaliation ans;
  ans.set(total_sum / total_size);

  return ans;
}

//------------------------------------------------
// Method Implementation of Class Comment
//------------------------------------------------

Comment::Comment(){}

Comment::~Comment(){}

//------------------------------------------------
// Method Implementation of Class Post
//------------------------------------------------

Post::Post(){}

Post::~Post(){}

void Post::add_comment(Comment comment){
  this->comments.push_back(comment);
}

vector<Comment> Post::get_comments(){
  return this->comments;
}
