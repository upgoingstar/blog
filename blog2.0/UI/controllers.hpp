#ifndef CONTROLLERS_H_INCLUDED
#define CONTROLLERS_H_INCLUDED

#include"domains.hpp"
#include"entities.hpp"
using namespace std;

class UIController{
public:
	static bool userAutenticate(Email, Password){
		return true;
	}
	
	static bool userFind(string){
		return true;
	}
	
	static void insertNewUser(User){
		return;
	}
};

#endif
