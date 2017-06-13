// INCLUDES
#include "../../lib/domain/avaliation.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
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
  if(a > 5 or a < 0) {
    throw invalid_argument( "Invalid number!" );
  }
}
