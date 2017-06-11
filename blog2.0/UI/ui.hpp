#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include<bits/stdc++.h>
using namespace std;

class LogIn{
public:
	static bool execute();
};

class LogOut{
public:
	const static int SIM = 1;
	const static int NAO = 2;
	static bool execute() throw(invalid_argument);
};

class ListBlogs{
public:
	static void execute();
};

class CreateAccount{
public:
	static	void execute();
};

class EditAccount{
public:
	static void execute();
};

class MainMenu{
private:
	static const int LOGIN = 1;
	static const int LOGOUT = 1;
	static const int REGISTER = 2;
	static const int ACCOUNT = 2;
	static const int LISTBLOGS = 3;
	static const int EXIT = 4;
	
	//friend static void LogIn::execute();
	//friend static bool LogOut::execute();
	//friend class ListBlogs;
	//friend class CreateAccount;
	//friend class EditAccount;
public:
	static void execute(); 
};

#endif
