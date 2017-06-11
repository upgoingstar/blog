// INCLUDES
#include "../../lib/domain/_domain.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
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