//------------------------------------------------
// Guards
//------------------------------------------------
#ifndef CONTROLLERS_H_INCLUDED
#define CONTROLLERS_H_INCLUDED

//------------------------------------------------
// Includes
//------------------------------------------------
#include <bits/stdc++.h>
#include "domains.hpp"
#include "entities.hpp"
#include "stubs.hpp"
using namespace std;

//------------------------------------------------
// Class UIController
//------------------------------------------------
class UIController{
public:
	static bool userAutenticate(Email e, Password p){
		return Stub::userAutenticate(e, p);
	}
	
	static bool userFind(Email e){
		return Stub::userFind(e);
	}
	
	static void insertNewUser(User){
		return;
	}

	static vector<Blog> getBlogs(User u){
		return Stub::getBlogs(u);
	}
};

#endif
