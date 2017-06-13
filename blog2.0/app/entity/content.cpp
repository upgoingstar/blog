// INCLUDES
#include "../../lib/entity/content.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
Content::Content() {}

Content::~Content() {}

void Content::valid(Name author, Text content) throw(invalid_argument) {
  if(author.empty() or content.empty()) {
    throw invalid_argument("Invalid informations to compose a content!");
  }
}

void Content::set(Name author, Text content) {
  Content::valid(author, content);
  this->author = author;
  this->content = content;
}

void Content::add_avaliation(Name name, Avaliation avaliation) throw(invalid_argument) {
  if(has_avaliated[name]) {
    throw invalid_argument("This user has already avaliated!");
  }
  else {
    this->avaliations.push_back(avaliation);
    has_avaliated[name] = true;
  }
}

Name Content::get_author() {
  if(this->author.empty()){
    throw invalid_argument("There is no author!");
  }
  return this->author;
}

Text Content::get_content() {
  if(this->content.empty()){
    throw invalid_argument("There is no content to show!");
  }
  return this->content;
}

Avaliation Content::get_avaliation() {
  int total_sum = 0;
  int total_size = this->avaliations.size();

  for(int i = 0; i < avaliations.size(); i++) {
  	Avaliation avaliation = avaliations[i];
    total_sum += avaliation.get();
  }

  Avaliation ans;
  ans.set(total_sum / total_size);

  return ans;
}