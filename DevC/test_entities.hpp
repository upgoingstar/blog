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
	void success_scenario(Name, Email, Password) throw(invalid_argument);

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void failure_scenario(Name, Email, Password) throw(invalid_argument);
public:

	/**
	 * A public constructor
	 */
	TestUser();

	/**
	 * A public destructor
	 */
	~TestUser();

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void verify();
};


//------------------------------------------------
// Class TestComment
//------------------------------------------------

class TestComment{
private:
	void success_scenario(Name, Text) throw(invalid_argument);

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void failure_scenario(Name, Text) throw(invalid_argument);
public:

	/**
	 * A public constructor
	 */
	TestComment();

	/**
	 * A public destructor
	 */
	~TestComment();

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void verify();
};


//------------------------------------------------
// Class TestPost
//------------------------------------------------

class TestPost{
private:
	void success_scenario(Name, Text) throw(invalid_argument);

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void failure_scenario(Name, Text) throw(invalid_argument);

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void failure_scenario2(Name, Text) throw(invalid_argument);
public:

	/**
	 * A public constructor
	 */
	TestPost();

	/**
	 * A public destructor
	 */
	~TestPost();

	/**
	 * A public method
	 * Call the test methods with the expected values
	 */

	 /**
  * A public method
  * Call the test methods with the expected values
  */
	void verify();
};

class TestBlog{
private:
	void success_scenario(Name, Name) throw(invalid_argument);

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void failure_scenario(Name, Name) throw(invalid_argument);
public:

	/**
	 * A public constructor
	 */
	TestBlog();

	/**
	 * A public destructor
	 */
	~TestBlog();

	/**
 * A public method
 * Call the test methods with the expected values
 */
	void verify();
};


#endif
