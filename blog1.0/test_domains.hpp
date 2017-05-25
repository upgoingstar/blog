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
	 * Test the methods of the received class and throw exception if something is detected wrong
	 */
	void success_scenario(string,Domain&) throw(invalid_argument);


	/**
	 * A protected method
	 * Test the methods of the received class and throw exception if something wrong is not detected
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
	
	/**
	* A private constant string
	* Keep a correct value for the class Name
	*/
	const string correct = "Abc";
	
	/**
	* A private constant string
	* Keep an incorrect value for the class Name
	*/
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
	
	/**
	* A private constant string
	* Keep a correct value for the class Password
	*/
	const string correct = "ab123";
	
	/**
	* A private constant string
	* Keep an incorrect value for the class Password
	*/
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
	
	/**
	* A private constant string
	* Keep a correct value for the class Email
	*/
	const string correct = "a@a.a";
	
	/**
	* A private constant string
	* Keep an incorrect value for the class Email
	*/
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
	
	/**
	* A private constant string
	* Keep a correct value for the class Text
	*/
	const string correct = "Valid text with less than 50 characters!";
	
	/**
	* A private constant string
	* Keep an incorrect value for the class Text
	*/
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
	/**
	* A private constant integer
	* Keep a correct value for the class Avaliation
	*/
	const int correct = 3;
	
	/**
	* A private constant integer
	* Keep an incorrect value for the class Avaliation
	*/
	const int incorrect = 7;

	/**
	 * A protected method
	 * Test the methods of the class Avaliation and throw exception if something is detected wrong
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
