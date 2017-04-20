#include <bits/stdc++.h>
using namespace std;

class Test{
protected:
	string correct;
	string incorrect;
	virtual void success_scenario(string);
	virtual void failure_scenario(string);
	Test();
	~Test();
public:
	void verify();
};

class TestName : public Test{
private:
	void success_scenario(string);
	void failure_scenario(string);
public:
	TestName();
	~TestName();
};

class TestPassword : public Test{
private:
	void success_scenario(string);
	void failure_scenario(string);
public:
	TestPassword();
	~TestPassword();
};

class TestEmail : public Test{
private:
	void success_scenario(string);
	void failure_scenario(string);
public:
	TestEmail();
	~TestEmail();
};

class TestText : public Test{
private:

	void success_scenario(string);
	void failure_scenario(string);
public:
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