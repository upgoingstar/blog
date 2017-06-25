#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#incklude "domains.hpp"
#include "entity.hpp"
using namespace std;

// Class Stub -------------------------------------------------------------------------------------------------

class Stub{
	public:
		static bool user_autenticate(Email, Password);

		static bool user_find(Email);
		
		static vector<Blog> get_blogs(User);
		
		static vector<Blog> get_all_blogs();
		
		static User get_user(Email email);
		
		static vector<Post> get_posts(Blog);

		static void destroy_blog(Blog){ return; }
		
		static void destroy_comment(Comment){ return; }
		
		static void destroy_post(Post){ return; }
		
		static void destroy_user(User){ return; }
			  
		static void new_post(Blog, Post){ return; }
		  
		static vector<Comment> get_comments(Post);
		
		static void update_post(Post){ return; }
		
		static void update_comment(Comment){ return; }
};

#endif
