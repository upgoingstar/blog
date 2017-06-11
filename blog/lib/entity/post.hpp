// GUARDS
#ifndef __POST_H_INCLUDED__
#define __POST_H_INCLUDED__

// INCLUDES
#include "../domain/_domain.hpp"
#include "content.hpp"
#include "comment.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
class Post : public Content {
private:
	/**
 * A private static constant integer variable.
 * Limits the number of times that a person can comment.
 */
  static const int comments_limit = 5;

	/**
 * A private variable of class Map.
 * Keeps the name that everyone that has already posted.
 */
	map<Name, int> number_comments;

	/**
 * A private variable of class Vector.
 * Keep all the comments made for this post.
 */
	vector<Comment> comments;

	/**
 * A private boolean variable.
 * Defines if comments are allowed.
 */
	bool comments_allowed;

public:
/**
 * A public constructor.
 */
  Post(Name, Text);

/**
 * A public destructor.
 */
  ~Post();
/**
 * A public method
 * Allow comments to be made by other users.
 */
  void allow_comments();

	/**
 * A public method
 * Disallow comments. This excludes all current comments.
 */
	void disallow_comments();

	/**
 * A public method
 * @return all the comments.
 */
	vector<Comment> get_comments();

	/**
 * A public method
 * Add a comment if possible (no user can comment more than 5 times and the post has to autorize comments).
 */
  void add_comment(Comment) throw(invalid_argument);
};

#endif
