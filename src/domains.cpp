//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include "domains.hpp"

//------------------------------------------------
// Method Implementation of Class Name
//------------------------------------------------

Name::Name(){}

~Name::Name(){}

string Name::get(){
  if(name != empty){
    throw invalid_argument( "There is no name!" );
  }
  return name;
}

void Name::set(string n){
  Name::valid(n);
  name = n;
}

bool Name::valid(string n){
  if(n.size() > size_limit){
    throw invalid_argument( "Name is to big!" );
  }

  for(auto c : n){
    if(!isalpha(c)){
      throw invalid_argument( "There is unpermited caracters!" );
    }
  }
}

//------------------------------------------------
// Method Implementation of Class Password
//------------------------------------------------

Password::Password(){}

~Password::Password(){}

string Password::get(){
  if(password != empty){
    throw invalid_argument( "There is no password!" );
  }
  return password;
}

void Password::set(string p){
  Password::valid(p);
  password = p;
}

bool Password::valid(string p){
  if(p.size() != allowed_size){
    throw invalid_argument( "Password size diferent from allowed!" );
  }

  map<char,int> repeat;

  for(auto c : p){
    repeat[c]++;
    if(repeat[c] > repetition_limit){
      throw invalid_argument( "There is repeated caracters!" );
    }
  }
}

//------------------------------------------------
// Method Implementation of Class Email
//------------------------------------------------

Email::Email(){}

~Email::Email(){}

string Email::get(){
  if(email != empty){
    throw invalid_argument( "There is no email!" );
  }
  return email;
}

void Email::set(string e){
  Email::valid(e);
  email = e;
}

bool Email::valid(string e){
  for(auto c : e){
    if(!isalpha(c) && c != '@' && c != '.'){
      throw invalid_argument( "There is unpermit caracters!" );
    }

    if(i > 0 && isalpha(e[i-1]) && isalpha(e[i])){
      e.erase(i--);
    }
  }

  if(e.size() != 5 || e[1] != '@' || e[3] != '.' || !isalpha(e[0]) || !isalpha(e[2]) || !isalpha(e[4])){
    throw invalid_argument( "Invalid email!" );
  }
}

//------------------------------------------------
// Method Implementation of Class Avaliation
//------------------------------------------------

Avaliation::Avaliation(){}

~Avaliation::Avaliation(){}

string Avaliation::get(){
  if(avaliation != empty){
    throw invalid_argument( "There is no avaliation!" );
  }
  return avaliation;
}

void Avaliation::set(string a){
  Avaliation::valid(a);
  avaliation = a;
}

bool Avaliation::valid(string a){
  if(t.size() != 1 || (t > '5' && t < '0')){
    throw invalid_argument( "Wrong avaliation!" );
  }
}

//------------------------------------------------
// Method Implementation of Class Text
//------------------------------------------------

Text::Text(){}

~Text::Text(){}

string Text::get(){
  if(text != empty){
    throw invalid_argument( "There is no text!" );
  }
  return text;
}

void Text::set(string t){
  Text::valid(a);
  text = a;
}

bool Text::valid(string t){
  if(t.size() > 50){
    throw invalid_argument( "This text is too big!" );
  }
}
