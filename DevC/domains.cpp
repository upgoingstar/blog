//------------------------------------------------
// INCLUDES
//------------------------------------------------

  #include "domains.hpp"
  #include <bits/stdc++.h>
  using namespace std;

//------------------------------------------------
// Method Implementation of Class Domain
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

/*
  Make it possible to compare if one Domain object has different value than other.
*/
bool Domain::operator!=(const Domain &other) const {
  return !(this->value == other.value);
}

/*
  Make it possible to compare if one Domain object has igual value than other.
*/
bool Domain::operator==(const Domain &other) const {
  return this->value == other.value;
}

/*
  Make it possible to compare if one Domain object has better value than other.
*/
bool Domain::operator<(const Domain &other) const {
  return this->value < other.value;
}

//------------------------------------------------
// Method Implementation of Class Name
//------------------------------------------------

  Name::Name() {}

  Name::~Name() {}

  /*
    Validate Name by verifying if the name is not bigger than the limit and see if all caracters are alphabetic or spaces.
  */
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
// Method Implementation of Class Password
//------------------------------------------------

  Password::Password() {}

  Password::~Password() {}

  /*
    Validate Password by verifying if the password is the determined size and if there are no repeated caracters.
  */
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
// Method Implementation of Class Email
// ------------------------------------------------

  Email::Email() {}

  Email::~Email() {}

  /*
    Validate Email by verifying if the email follow the pattern l@l.l (being l any string with only alphabetic caracters).
  */
  void Email::valid(string e) throw(invalid_argument) {
    for(int i = 0; i < (int)e.size(); i++) {
      if(!isalpha(e[i]) && e[i] != '@' && e[i] != '.') {
        throw invalid_argument( "There is unpermit caracters!" );
      }

      if(i > 0 && isalpha(e[i-1]) && isalpha(e[i])) {
        e.erase(i);
      }
    }

    if(e.size() != 5 || e[1] != '@' || e[3] != '.' || !isalpha(e[0]) || !isalpha(e[2]) || !isalpha(e[4])) {
      throw invalid_argument( "Invalid email!" );
    }
  }

//------------------------------------------------
// Method Implementation of Class Avaliation
//------------------------------------------------

  Avaliation::Avaliation() {
    this->value = -1;
  }

  Avaliation::~Avaliation() {}

  int Avaliation::get() {
    if(this->value == -1) {
      throw invalid_argument( "Invalid number!" );
    }
    return this->value;
  }

  void Avaliation::set(int avaliation) {
    valid(avaliation);
    this->value = avaliation;
  }

  /*
    Validate Avaliation by verifying if the avaliation is a number in the interval [0, 5].
  */
  void Avaliation::valid(int a) throw(invalid_argument) {
    if(a > 5 || a < 0) {
      throw invalid_argument( "Invalid number!" );
    }
  }

//------------------------------------------------
// Method Implementation of Class Text
//------------------------------------------------

  Text::Text() {}

  Text::~Text() {}

  /*
    Validate Text by verifying if the text has a size less than 50 caracters.
  */
  void Text::valid(string t) throw(invalid_argument) {
    if(t.empty()) {
      throw invalid_argument( "There is no text!" );
    }

    if(t.size() > 50) {
      throw invalid_argument( "This text is too big!" );
    }
  }
