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

void User::valid(Name name, Email email, Password password) throw(invalid_argument) {
  if(!name.exist() || !email.exist() || !password.exist())
    throw invalid_argument("Invalid informations to compose a user!");
}

void User::set(Name name, Email email, Password password) {
  User::valid(name,email,password);
  this->name = name;
  this->password = password;
  this->email = email;
  this->anonymous = false;
}

Name User::get_name(){
  if(anonymous) throw invalid_argument("This user don't have a name");
  else
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

void Content::valid(Name name, Text text){
  if(!name.exist() || !text.exist())
    throw invalid_argument("Invalid informations to compose a content!");
}

void Content::set(Name name, Text text){
  Content::valid(name,text);
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

Comment::Comment(Name author,Text comment_text){
  Content::set(author,comment_text);
}

Comment::~Comment(){}

//------------------------------------------------
// Method Implementation of Class Post
//------------------------------------------------

Post::Post(Name author,Text post_text,bool can_comment = 0){
  Content::set(author,post_text);
  comments_allowed = can_comment;
}

Post::~Post(){}

void Post::allow_comments(){
  comments_allowed = 1;
}

void Post::add_comment(Comment comment){
  if(comments_allowed && number_comments[comment.get_author()] < comments_limit){
    number_comments[comment.get_author()]++;
    this->comments.push_back(comment);
  }
  else
    throw invalid_argument("This comment is not allowed!");
}

vector<Comment> Post::get_comments(){
  return this->comments;
}
