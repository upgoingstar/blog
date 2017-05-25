// INCLUDES
#include "../../lib/domain/email.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
Email::Email() {}

Email::~Email() {}

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