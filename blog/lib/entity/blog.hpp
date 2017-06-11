// GUARDS
#ifndef __BLOG_H_INCLUDED__
#define __BLOG_H_INCLUDED__

// INCLUDES
#include "../domain/_domain.hpp"
#include "../entity/post.hpp"
#include <bits/stdc++.h>
using namespace std;

//IMPLEMENTATION
class Blog {
private:
/**
 * A private variable of class Name.
 * Keeps the name of the author.
 */
	Name author;

/**
 * A private variable of class Name.
 * Keeps the name of the blog.
 */
	Name blog_name;

/**
 * A private variable of class Name.
 * Keeps all the posts.
 */
	vector<Post> posts;

public:
/**
 * A public constructor.
 */
  Blog();

/**
 * A public destructor.
 */
  ~Blog();

/**
 * A public method
 * Modify the Name of the author and the Name of the blog.
 */
  void set(Name, Name) throw(invalid_argument);

	/**
	 * A public method
	 * @return The name of the author of the blog.
	 */
	Name get_author();

	/**
	 * A public method
	 * @return The name of the blog.
	 */
	Name get_blog_name();

	/**
	 * A public method
	 * @return All the posts in this blog.
	 */
	vector<Post> get_posts();

	/**
 	 * A public method
	 * Add a new post to this blog. Does not add a post of a person different than the one who created the blog be added.
 	 */
	void add_post(Post) throw(invalid_argument);
};

#endif
