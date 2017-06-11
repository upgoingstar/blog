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
	static bool userAutenticate(Email, Password){
		return Stub::userAutenticate(Email, Password);
	}
	
	static bool userFind(Email){
		return Stub::userFind(Email);
	}
	
	static void insertNewUser(User){
		return;
	}

	static vector<string> getBlogs(User){
		return Stub::getBlogs(User);
	}
};

#endif
