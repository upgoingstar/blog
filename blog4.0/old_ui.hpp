//------------------------------------------------
// Guards
//------------------------------------------------

#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

//------------------------------------------------
// Class Includes
//------------------------------------------------

#include <bits/stdc++.h>
#include "entities.hpp"
using namespace std;

//------------------------------------------------
// Class Auth
//------------------------------------------------

class Auth{
public:
  static User get();
};

//------------------------------------------------
// Class BlogsUI
//------------------------------------------------

class BlogsUI{
private:
  static const int LIST = 1;
  static const int MYBLOGS = 2;
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

