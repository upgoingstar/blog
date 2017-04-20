//------------------------------------------------
// GUARDS
//------------------------------------------------

#ifndef __TESTDOMAINS_H_INCLUDED__
#define __TESTDOMAINS_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class TestName{
private:
	const string correct = "Abc";
	const string incorrect = "A1";
	void success_scenario(string);
	void failure_scenario(string);
public:
	void verify();
	TestName();
	~TestName();
};

class TestPassword{
private:
	const string correct = "ab123";
	const string incorrect = "ab112";
	void success_scenario(string);
	void failure_scenario(string);
public:
	void verify();
	TestPassword();
	~TestPassword();
};

class TestEmail{
private:
	const string correct = "a@a.a";
	const string incorrect = "a1@a.a";
	void success_scenario(string);
	void failure_scenario(string);
public:
	void verify();
	TestEmail();
	~TestEmail();
};

class TestText{
private:
	const string correct = "Valid text with less than 50 characters!";
	const string incorrect = "Text too much looooooooooooooooooooooooooooooooooooooooooooooooooooooooooong";
	void success_scenario(string);
	void failure_scenario(string);
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
	TestAvaliation();
	~TestAvaliation();
	void verify();
};

#endif
