// INCLUDES
#include "../../lib/domain/password.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
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