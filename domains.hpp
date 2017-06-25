#ifndef __DOMAINS_H_INCLUDED__
#define __DOMAINS_H_INCLUDED__

#include <bits/stdc++.h>
using namespace std;

/**
* @class Domain
* @brief Abstract Class to define what some other domais should have and implement.
* @note It has a virtual function for all classes that inherit this implement (valid - check if the string is OK).
* Abstract Class for Name, Email, Password and Text. Keeps a string for all classes that inherit this class and implement the methods get and set (respectively, see and modify the value keeped). Also declares a virtual method "valid" for each class implement
*/
class Domain {
	protected:
		string value; ///< Keep a value for all classes that inherit this one.

		/**
		* @brief   Validate a string
		* Virtual Method for all classes that inherit this implement their own validation. Utilized in method set.
		*/
		virtual void valid(string) throw(invalid_argument) = 0;

	public:
		Domain(); ///< Constructor

		~Domain(); ///< Destructor

		/**
		* @brief   Get the value of the string
		* @return Value of string "value".
		*/
		string get() const;
		/**
		* @brief   Modify the value of the keeped string.
		* 
		* Set the keeped string to the new value if is a Valid string.
		*/
		void set(string);
		/**
		* @brief   Warn if the string is empty.
		* @retval TRUE The string is empty
		* @retval FALSE The string is not empty
		*/
		bool empty();
		/**
		* @brief   Operator overload to make it possible to compare if one Domain object has different value than other.
		* @retval TRUE The other Domain is different
		* @retval FALSE The other Domain is equal
		*/
		bool operator!=(const Domain &other) const;
		/**
		* @brief   Operator overload to make it possible to compare if one Domain object has igual value than other.
		* @retval TRUE The other Domain is equal
		* @retval FALSE The other Domain is different
		*/
		bool operator==(const Domain &other) const;
		/**
		* @brief   Operator overload to make it possible to compare if one Domain object has igual value than other.
		* @retval TRUE The other Domain is equal
		* @retval FALSE The other Domain is different
		*/
		bool operator==(const string &other) const;
		/**
		* @brief   Operator overload to make it possible to compare if one Domain object has better value than other.
		* @retval TRUE The other Domain is bigger
		* @retval FALSE The other Domain is smaller
		*/
		bool operator<(const Domain &other) const;
		/**
		* @brief   Operator overload to make it possible print using cout
		*/
		friend ostream& operator<<(ostream&, const Domain&);
		/**
		* @brief   Operator overload to make it possible print using cin
		*/
		friend istream& operator>>(istream&, Domain&);
};

/**
* @class Name
* @brief Define how a name should be.
* Inherit of class Domain. Restrict the string to be at most of size 20 and if all caracters are alphabetic or spaces.
*/
class Name : public Domain {
	private:
		static const int size_limit = 20; ///< Maximum size of the name

		/**
		* @brief   Validate the Name
		* Implementation of the virtaul function valid in Domain. Validate Name by verifying if the name is not bigger than the limit and see if all caracters are alphabetic or spaces.
		*/
		void valid(string) throw(invalid_argument);

	public:
		Name(); ///< Constructor

		~Name(); ///< Destructor
};

/**
* @class Password
* @brief Defines how a password should be.
* Inherit of class Domain. Restrict the string to be at most of size 5 and if there is no repetition of caracters.
*/
class Password : public Domain {
	private:
		static const int allowed_size = 5; ///< Maximum size of the password

		static const int repetition_limit = 1; ///< Maximum repetition

		/**
		* @brief   Validate the Password
		* Implementation of the virtaul function valid in Domain. Validate Password by verifying if the password is the determined size and if there are no repeated caracters.
		*/
		void valid(string) throw(invalid_argument);

	public:
		Password(); ///< Constructor

		~Password(); ///< Destructor
};

/**
* @class Email
* @brief Defines how a email should be.
* @note The restriction make it easier to check, but there are valid real email that do not follow this pattern.*
* Inherit of class Domain. Restrict the string to follow the pattern l@l.l (being l any string with only alphabetic caracters).
*/
class Email : public Domain {
	private:
		/**
		* @brief   Validate the Email
		* Implementation of the virtaul function valid in Domain. Validate Email by verifying if the email follow the pattern l@l.l (being l any string with only alphabetic caracters).
		*/
		void valid(string) throw(invalid_argument);

	public:
		Email(); ///< Constructor

		~Email();///< Destructor
};

/**
* @class Text
* @brief Defines how a text should be.
* Inherit of class Domain. Restrict the string to have size less than 50 caracters.
*/
class Text : public Domain {
	private:
		/**
		* @brief   Validate the Text
		* Implementation of the virtaul function valid in Domain. Validate Text by verifying if the text has a size less than 50 caracters.
		*/
		void valid(string) throw(invalid_argument);

	public:
		Text(); ///< Constructor

		~Text(); ///< Destructor
};

/**
* @class Avaliation
* @brief Defines how a avaliation should be.
* Restrict the int to be between 0 and 5 inclusive.
*/
class Avaliation {
	private:
		int value; ///< Keep the value of the avaliation.

		/**
		* @brief   Validate the Avaliation
		* Validate Avaliation by verifying if the avaliation is a number in the interval [0, 5].
		*/
		void valid(int) throw(invalid_argument);

	public:
		Avaliation(); ///< Constructor

		~Avaliation(); ///< Destructor

		/**
		* @brief   Get the value of the integer
		* @return Value of integer "value".
		*/
		int get() const;
		/**
		* @brief   Modify the value of the keeped integer.
		* Set the keeped integer to the new value if is a Valid integer.
		*/
		void set(int avaliation);
		/**
		* @brief   Operator overload to make it possible print using cout
		*/
		friend ostream& operator<<(ostream&, const Avaliation&);
		/**
		* @brief   Operator overload to make it possible print using cin
		*/
		friend istream& operator>>(istream&, Avaliation&);
};

/**
* @class Id
* @brief Defines how a Id should be.
* Restrict the string should represent the quantity of seconds since 1/1/1970
*/
class Id : public Domain {
	private:
		/**
		* @brief   Validate the Id
		* Implementation of the virtaul function valid in Domain. Validate Id by verifying if not empty or ...
		*/
		void valid(string) throw(invalid_argument);

	public:
		Id(); ///< Constructor

		~Id(); ///< Destructor
};

#endif