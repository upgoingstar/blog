// GUARDS
#ifndef __COMMENT_H_INCLUDED__
#define __COMMENT_H_INCLUDED__

// INCLUDES
#include "../domain/_domain.hpp"
#include "content.hpp"
#include <bits/stdc++.h>
using namespace std;

//IMPLEMENTATION
class Comment : public Content {
public:
/**
 * A public constructor.
 */
  Comment(Name, Text);

/**
 * A public destructor.
 */
  ~Comment();
};

#endif
