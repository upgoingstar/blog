//------------------------------------------------
// GUARDS
//------------------------------------------------

#ifndef __TESTDOMAINS_H_INCLUDED__
#define __TESTDOMAINS_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include <bits/stdc++.h>
#include "domains.hpp"
using namespace std;

class TestDomain{
protected:
	void success_scenario(string,Domain&);
	void failure_scenario(string,Domain&);
public:
	TestDomain();
	~TestDomain();
};

class TestName : protected TestDomain{
private:
	const string correct = "Abc";
	const string incorrect = "A1";
public:
	void verify();
	TestName();
	~TestName();
};

class TestPassword : protected TestDomain{
private:
	const string correct = "ab123";
	const string incorrect = "ab112";
public:
	void verify();
	TestPassword();
	~TestPassword();
};

class TestEmail : protected TestDomain{
private:
	const string correct = "a@a.a";
	const string incorrect = "a1@a.a";
public:
	void verify();
	TestEmail();
	~TestEmail();
};

class TestText : protected TestDomain{
private:
	const string correct = "Valid text with less than 50 characters!";
	const string incorrect = "Text too much looooooooooooooooooooooooooooooooooooooooooooooooooooooooooong";
public:
	void verify();
	TestText();
	~TestText();
};

class TestAvaliation{
private:
	const int correct = 3;
	const int incorrect = 7;
	void success_scenario(int);
	void failure_scenario(int);
public:
	void verify();
	TestAvaliation();
	~TestAvaliation();
};

#endif
