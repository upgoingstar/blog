// INCLUDES
#include "../../lib/domain/text.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
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
