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
	
	/**
	 * A protected method
	 * Test the methods of the class User and throw exception if something is detected wrong
	 */
	void success_scenario(Name, Email, Password) throw(invalid_argument);

	/**
	 * A protected method
	 * Test the methods of the class User and throw exception if something wrong is not detected
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
	
	/**
	 * A protected method
	 * Test the methods of the class Comment and throw exception if something is detected wrong
	 */
	void success_scenario(Name, Text) throw(invalid_argument);

	/**
	 * A protected method
	 * Test the methods of the class Comment and throw exception if something wrong is not detected
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
	
	/**
	 * A protected method
	 * Test the methods of the class Post and throw exception if something is detected wrong
	 */
	void success_scenario(Name, Text) throw(invalid_argument);

	/**
	 * A protected method
	 * Test the methods of the class Post and throw exception if something wrong is not detected
	 */
	void failure_scenario(Name, Text) throw(invalid_argument);

	/**
	 * A protected method
	 * Test the methods of the class Post and throw exception if something wrong is not detected
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
	/**
	 * A protected method
	 * Test the methods of the class Blog and throw exception if something is detected wrong
	 */
	void success_scenario(Name, Name) throw(invalid_argument);

	/**
	 * A protected method
	 * Test the methods of the class Blog and throw exception if something wrong is not detected
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
