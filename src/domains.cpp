//------------------------------------------------
// INCLUDES
//------------------------------------------------

  #include "domains.hpp"

//------------------------------------------------
// Method Implementation of Class Domain
//------------------------------------------------

string Domain::get() {
  if(this->value.empty()) {
    throw invalid_argument( "String is empty!" );
  }
  return this->value;
}

void Domain::set(string v) {
  this->valid(v);
  this->value = v;
}

//------------------------------------------------
// Method Implementation of Class Name
//------------------------------------------------

  Name::Name() {}

  Name::~Name() {}

  void Name::valid(string n) throw(invalid_argument) {
    if(n.size() > size_limit) {
      throw invalid_argument( "Name is to big!" );
    }

    for(char c : n) {
      if(!isalpha(c)) {
        throw invalid_argument( "There is unpermited caracters!" );
      }
    }
  }

//------------------------------------------------
// Method Implementation of Class Password
//------------------------------------------------

  Password::Password() {}

  Password::~Password() {}

  void Password::valid(string p) throw(invalid_argument) {
    if(p.size() != allowed_size) {
      throw invalid_argument( "Password size diferent from allowed!" );
    }

    map<char,int> repeat;

    for(auto c : p) {
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

  void Email::valid(string e) throw(invalid_argument) {
    for(int i = 0; i < e.size(); i++) {
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

  Avaliation::Avaliation() {}

  Avaliation::~Avaliation() {}

  void Avaliation::valid(string a) throw(invalid_argument){
    if(a.size() != 1 || a[0] > '5' || a[0] < '0'){
      throw invalid_argument( "Invalid number!" );
    }
  }

//------------------------------------------------
// Method Implementation of Class Text
//------------------------------------------------

  Text::Text() {}

  Text::~Text() {}

  void Text::valid(string t) throw(invalid_argument) {
    if(t.size() > 50) {
      throw invalid_argument( "This text is too big!" );
    }
  }