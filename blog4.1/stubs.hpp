//------------------------------------------------
// Guards
//------------------------------------------------
#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

//------------------------------------------------
// Includes
//------------------------------------------------
#include "domains.hpp"
#include "entity.hpp"
using namespace std;

//------------------------------------------------
// Class Stub
//------------------------------------------------
class Stub{
public:
	static bool user_autenticate(Email, Password);
	static bool user_find(Email);
	static vector<Blog> get_blogs(User);
	static vector<Blog> get_all_blogs();
	static User get_user(Email email);
	static vector<Post> get_posts(Blog);
};

#endif
