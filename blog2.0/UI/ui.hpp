//------------------------------------------------
// Guards
//------------------------------------------------
#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

//------------------------------------------------
// Class Includes
//------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// Class BlogsUI
//------------------------------------------------
class BlogsUI{
private:
	static void list();
	static void myBlogs();

public:
	static void execute(bool) throw(invalid_argument);
};

//------------------------------------------------
// Class AccountUI
//------------------------------------------------
class AccountUI{
public:
	static void execute();
};

//------------------------------------------------
// Class MainMenu
//------------------------------------------------
class MainMenu{
private:
	static const int LOGIN = 1;
	static const int LOGOUT = 1;
	static const int REGISTER = 2;
	static const int ACCOUNT = 2;
	static const int LISTBLOGS = 3;
	static const int EXIT = 4;
	
	const static int SIM = 1;
	const static int NAO = 2;
	static bool logOut() throw(invalid_argument);
	static bool logIn();
	static void createAccount();

	//friend class Blogs;
	//friend class CreateAccount;
	//friend class Account;
public:
	static void execute(); 
};

#endif
