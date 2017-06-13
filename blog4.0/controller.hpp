//------------------------------------------------
// Guards
//------------------------------------------------
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

//------------------------------------------------
// Includes
//------------------------------------------------
#include <bits/stdc++.h>
#include "domains.hpp"
#include "entity.hpp"
#include "stubs.hpp"
using namespace std;

//------------------------------------------------
// Class UIController
//------------------------------------------------
class UserController{
public:
	static bool autenticate(Email e, Password p){
		return Stub::userAutenticate(e, p);
	}
	
	static bool find(Email e){
		return Stub::userFind(e);
	}
	
	static void insert_new_user(User){
		return;
	}
};

class BlogController{
public:
	static vector<Blog> get_blogs(User u){
		return Stub::getBlogs(u); 
	}
};

class AuthController{
public:
	static User get(){
		User u;
		Name nome;
		Email email;
		Password senha;
		nome.set("stub");
		email.set("stub@stub.stub");
		senha.set("stubp");
		u.set(nome,email,senha);
		return u;
	}
};

#endif
