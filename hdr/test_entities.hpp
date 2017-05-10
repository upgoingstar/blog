//------------------------------------------------
// GUARDS
//------------------------------------------------

#ifndef __TESTENTITIES_H_INCLUDED__
#define __TESTENTITIES_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include <bits/stdc++.h>
#include "domains.hpp"
using namespace std;

//------------------------------------------------
// Class TestUser
//------------------------------------------------

class TestUser{
private:
	void success_scenario(Name, Email, Password);
	void failure_scenario(Name, Email, Password);
public:
	TestUser();
	~TestUser();
	void verify();
};


//------------------------------------------------
// Class TestComment
//------------------------------------------------

class TestComment{
private:
	void success_scenario(Name, Text);
	void failure_scenario(Name, Text);
public:
	TestComment();
	~TestComment();
	void verify();
};


//------------------------------------------------
// Class TestPost
//------------------------------------------------

class TestPost{
private:
	void success_scenario(Name, Text);
	void failure_scenario(Name, Text);
	void failure_scenario2(Name, Text);
public:
	TestPost();
	~TestPost();
	void verify();
};

class TestBlog{
private:
	void success_scenario(Name, Text);
	void failure_scenario(Name, Text);
public:
	TestBlog();
	~TestBlog();
	void verify();
};


#endif
