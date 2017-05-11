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


//------------------------------------------------
// Abstract Class TestDomain
//------------------------------------------------

class TestDomain{
protected:
	/**
	 * A protected method
	 * Test the methods of the receivied class and throw exception if something wrong is detected
	 */
	void success_scenario(string,Domain&) throw(invalid_argument);


	/**
	 * A protected method
	 * Test the methods of the receivied class and throw exception if something wrong is not detected
	 */
	void failure_scenario(string,Domain&) throw(invalid_argument);

public:

	/**
	 * A public constructor
	 */
	TestDomain();

	/**
	 * A public destructor
	 */
	~TestDomain();
};

//------------------------------------------------
// Class TestName
//------------------------------------------------

class TestName : protected TestDomain{
private:
	const string correct = "Abc";
	const string incorrect = "A1";
public:

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void verify();

	/**
	 * A public constructor
	 */
	TestName();

	/**
	 * A public destructor
	 */
	~TestName();
};

//------------------------------------------------
// Class TestPassword
//------------------------------------------------

class TestPassword : protected TestDomain{
private:
	const string correct = "ab123";
	const string incorrect = "ab112";
public:

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void verify();

	/**
	 * A public constructor
	 */
	TestPassword();

	/**
	 * A public destructor
	 */
	~TestPassword();
};

//------------------------------------------------
// Class TestEmail
//------------------------------------------------

class TestEmail : protected TestDomain{
private:
	const string correct = "a@a.a";
	const string incorrect = "a1@a.a";
public:

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void verify();

	/**
	 * A public constructor
	 */
	TestEmail();

	/**
	 * A public destructor
	 */
	~TestEmail();
};

//------------------------------------------------
// Class TestText
//------------------------------------------------

class TestText : protected TestDomain{
private:
	const string correct = "Valid text with less than 50 characters!";
	const string incorrect = "Text too much looooooooooooooooooooooooooooooooooooooooooooooooooooooooooong";
public:

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void verify();

	/**
	 * A public constructor
	 */
	TestText();

	/**
	 * A public destructor
	 */
	~TestText();
};

//------------------------------------------------
// Class TestAvaliation
//------------------------------------------------

class TestAvaliation{
private:
	const int correct = 3;
	const int incorrect = 7;

	/**
	 * A protected method
	 * Test the methods of the class Avaliation and throw exception if something wrong is detected
	 */
	void success_scenario(int) throw(invalid_argument);

	/**
	 * A protected method
	 * Test the methods of the class Avaliation and throw exception if something wrong is not detected
	 */
	void failure_scenario(int) throw(invalid_argument);
public:

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void verify();

	/**
	 * A public constructor
	 */
	TestAvaliation();

	/**
	 * A public destructor
	 */
	~TestAvaliation();
};

#endif
