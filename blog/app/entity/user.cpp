// INCLUDES
#include "../../lib/entity/user.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
User::User() {
  this->anonymous = true;
}

User::~User() {}

void User::valid(Name name, Email email, Password password) throw(invalid_argument) {
  if(name.empty() or email.empty() or password.empty()) {
    throw invalid_argument("Invalid informations to compose a user!");
  }
}

void User::set(Name name, Email email, Password password) {
  User::valid(name, email,password);
  this->name = name;
  this->password = password;
  this->email = email;
  this->anonymous = false;
}

Name User::get_name() throw(invalid_argument) {
  if(anonymous) {
    throw invalid_argument("This user is anonymous, doesn't have a name");
  }
  else {
    return this->name;
  }
}

void User::check_user(Email email, Password password) throw(invalid_argument) {
  if(this->email != email or this->password != password or email.empty() or password.empty()) {
    throw invalid_argument( "That is not your email or password!" );
  }
}