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
	static bool userAutenticate(Email, Password);
	static bool userFind(Email);
	static vector<Blog> getBlogs(User);
};

#endif
