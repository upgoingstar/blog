// GUARDS
#ifndef __USER_H_INCLUDED__
#define __USER_H_INCLUDED__

// INCLUDES
#include "../domain/_domain.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
class User {
private:
	/**
 * A private variable of class Name.
 * Keeps the name of the User.
 */
	Name name;

	/**
 * A private variable of class Password.
 * Keeps the password of the User.
 */
	Password password;

	/**
	 * A private variable of class Email.
	 * Keeps the email of the User.
	 */
	Email email;

	/**
 * A private bolean variable.
 * Keeps the name of the User.
 */
	bool anonymous;

	/**
	 * A private method.
   * Validate User by verifying if any of the arguments (name, email and password) already exists, so that there are no two users with the same name or email or password.
   */
	void valid(Name, Email,Password) throw(invalid_argument);

public:
	/**
 * A public constructor.
 */
  User();

	/**
 * A public destructor.
 */
  ~User();

	/**
 * A public method
 * Modify the value of the Name, Email and Password of this User.
 */
  void set(Name, Email, Password);

	/**
 * A public method
 * @return Value of the Name of the User.
 */
	Name get_name() throw(invalid_argument);

	/**
 * A public method.
	 * Check if the email and password given correspond to a real User.
	 * TODO: Need refactoring!
 */
  void check_user(Email, Password) throw(invalid_argument);
};

#endif
