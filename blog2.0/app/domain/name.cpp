// INCLUDES
#include "../../lib/domain/name.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
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
    if(!isalpha(c) and c != ' ') {
      throw invalid_argument( "There is unpermited caracters!" );
    }
  }
}