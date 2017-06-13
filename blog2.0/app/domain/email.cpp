// INCLUDES
#include "../../lib/domain/email.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
Email::Email() {}

Email::~Email() {}

void Email::valid(string e) throw(invalid_argument) {
  for(int i = 0; i < (int)e.size(); i++) {
    if(!isalpha(e[i]) and e[i] != '@' and e[i] != '.') {
      throw invalid_argument( "There is unpermit caracters!" );
    }

    if(i > 0 and isalpha(e[i-1]) and isalpha(e[i])) {
      e.erase(i,1);
      i--;
    }
  }

  if(e.size() != 5 or e[1] != '@' or e[3] != '.' or !isalpha(e[0]) or !isalpha(e[2]) or !isalpha(e[4])) {
    throw invalid_argument( "Invalid email!" );
  }
}