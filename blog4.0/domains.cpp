//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include "domains.hpp"
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// DOMAIN ABSTRACT CLASS
//------------------------------------------------

Domain::Domain() {}

Domain::~Domain() {}

string Domain::get() {
  if(this->value.empty()) {
    throw invalid_argument( "String is empty!" );
  }
  return this->value;
}

void Domain::set(string value) {
  this->valid(value);
  this->value = value;
}

bool Domain::empty() {
  return this->value.empty();
}

bool Domain::operator!=(const Domain &other) const {
  return !(this->value == other.value);
}

bool Domain::operator==(const Domain &other) const {
  return this->value == other.value;
}

bool Domain::operator<(const Domain &other) const {
  return this->value < other.value;
}

//------------------------------------------------
// NAME CLASS
//------------------------------------------------

Name::Name() {}

Name::~Name() {}

void Name::valid(string n) throw(invalid_argument) {
  if(n.size() > size_limit) {
    throw invalid_argument( "Name is to big!" );
  }

  if(n.empty()) {
    throw invalid_argument( "Name is empty!" );
  }

  for(int i = 0; i < n.size(); i++) {
  	char c = n[i];
    if(!isalpha(c) && c != ' ') {
      throw invalid_argument( "There is unpermited caracters!" );
    }
  }
}

//------------------------------------------------
// PASSWORD CLASS
//------------------------------------------------

Password::Password() {}

Password::~Password() {}

void Password::valid(string p) throw(invalid_argument) {
  if(p.empty()) {
    throw invalid_argument( "There is no password!" );
  }

  if(p.size() != allowed_size) {
    throw invalid_argument( "Password size diferent from allowed!" );
  }

  map<char,int> repeat;

  for(int i = 0; i < p.size(); i++) {
  	char c = p[i];
    repeat[c]++;
    if(repeat[c] > repetition_limit) {
      throw invalid_argument( "There is repeated caracters!" );
    }
  }
}

// ------------------------------------------------
// EMAIL CLASS
// ------------------------------------------------

Email::Email() {}

Email::~Email() {}

void Email::valid(string e) throw(invalid_argument) {
  for(int i = 0; i < (int)e.size(); i++) {
    if(!isalpha(e[i]) && e[i] != '@' && e[i] != '.') {
      throw invalid_argument( "There is unpermit caracters!" );
    }

    if(i > 0 && isalpha(e[i-1]) && isalpha(e[i])) {
      e.erase(i,1);
      i--;
    }
  }

  if(e.size() != 5 || e[1] != '@' || e[3] != '.' || !isalpha(e[0]) || !isalpha(e[2]) || !isalpha(e[4])) {
    throw invalid_argument( "Invalid email!" );
  }
}

//------------------------------------------------
// AVALIATION CLASS
//------------------------------------------------

Avaliation::Avaliation() {
  this->value = 0;
}

Avaliation::~Avaliation() {}

int Avaliation::get() {
  return this->value;
}

void Avaliation::set(int avaliation) {
  valid(avaliation);
  this->value = avaliation;
}

void Avaliation::valid(int a) throw(invalid_argument) {
  if(a > 5 || a < 0) {
    throw invalid_argument( "Invalid number!" );
  }
}

//------------------------------------------------
// TEXT CLASS
//------------------------------------------------

Text::Text() {}

Text::~Text() {}

void Text::valid(string t) throw(invalid_argument) {
  if(t.empty()) {
    throw invalid_argument( "There is no text!" );
  }

  if(t.size() > 50) {
    throw invalid_argument( "This text is too big!" );
  }
}

