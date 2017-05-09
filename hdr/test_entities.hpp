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


class TestUser{
private:
	void success_scenario(Name, Email, Password);
	void failure_scenario(Name, Email, Password);
public:
	TestUser();
	~TestUser();
	void verify();
};

class TestComment{
private:
	void success_scenario(Name, Text);
	void failure_scenario(Name, Text);
public:
	TestComment();
	~TestComment();
	void verify();
};


class TestPost{
private:
	void success_scenario(Name, Text, bool);
	void failure_scenario(Name, Text, bool);
public:
	TestPost();
	~TestPost();
	void verify();
};

#endif
