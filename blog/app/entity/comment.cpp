// INCLUDES
#include "../../lib/entity/comment.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
Comment::Comment(Name author, Text comment_content) {
  Content::set(author, comment_content);
}

Comment::~Comment() {}
