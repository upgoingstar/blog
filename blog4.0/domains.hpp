//------------------------------------------------
// GUARDS
//------------------------------------------------

#ifndef __DOMAINS_H_INCLUDED__
#define __DOMAINS_H_INCLUDED__

//------------------------------------------------
// INCLUDES
//------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

//------------------------------------------------
// DOMAIN ABSTRACT CLASS
//------------------------------------------------

/**
 * @class Domain
 *
 * @brief Abstract Class to define what some other domais should have and implement.
 *
 * Abstract Class for Name, Email, Password and Text. Keeps a string for all classes that inherit this class and implement the methods get and set (respectively, see and modify the value keeped). Also declares a virtual method "valid" for each class implement.
 *
 * @note It has a virtual function for all classes that inherit this implement (valid - check if the string is OK).
 */
class Domain {
  protected:
    /// Keep a value for all classes that inherit this one.
    string value;

    /**
     * @name    Valid
     * @brief   Validate a string
     *
     * Virtual Method for all classes that inherit this implement their own validation. Utilized in method set.
     */
    virtual void valid(string) throw(invalid_argument) = 0;

  public:
    /// Create a Domain
    Domain();

    /// Destroy a Domain
    ~Domain();

    /**
     * @name    Get
     * @brief   Get the value of the string
     *
     * @return Value of string "value".
     */
    string get() const;

    /**
     * @name    Set
     * @brief   Modify the value of the keeped string.
     * 
     * Set the keeped string to the new value if is a Valid string.
     */
    void set(string);

    /**
     * @name    Empty
     * @brief   Warn if the string is empty.
     *
     * @retval TRUE The string is empty
     * @retval FALSE The string is not empty
     */
    bool empty();

    /**
     * @name    Operator!=
     * @brief   Operator overload to make it possible to compare if one Domain object has different value than other.
     *
     * @retval TRUE The other Domain is different
     * @retval FALSE The other Domain is equal
     */
    bool operator!=(const Domain &other) const;

    /**
     * @name    Operator==
     * @brief   Operator overload to make it possible to compare if one Domain object has igual value than other.
     *
     * @retval TRUE The other Domain is equal
     * @retval FALSE The other Domain is different
     */
    bool operator==(const Domain &other) const;

    /**
     * @name    Operator<
     * @brief   Operator overload to make it possible to compare if one Domain object has better value than other.
     *
     * @retval TRUE The other Domain is bigger
     * @retval FALSE The other Domain is smaller
     */
    bool operator<(const Domain &other) const;

    /**
     * @name    Operator<<
     * @brief   Operator overload to make it possible print using cout
     */
    friend ostream& operator<<(ostream&, const Domain&);

	/**
     * @name    Operator<<
     * @brief   Operator overload to make it possible print using cin
     */
    friend istream& operator>>(istream&, Domain&);
};

//------------------------------------------------
// NAME CLASS
//------------------------------------------------

/**
 * @class Name
 *
 * @brief Define how a name should be.
 *
 * Inherit of class Domain. Restrict the string to be at most of size 20 and if all caracters are alphabetic or spaces.
 *
 * @note The size is small for view reasons.
 */
class Name : public Domain {
  private:
    /// Maximum size of the name
    static const int size_limit = 20;

    /**
     * @name    Valid
     * @brief   Validate the Name
     *
     * Implementation of the virtaul function valid in Domain. Validate Name by verifying if the name is not bigger than the limit and see if all caracters are alphabetic or spaces.
     */
    void valid(string) throw(invalid_argument);

  public:
    /// Create a Name
    Name();

    /// Destroy a Name
    ~Name();
};

//------------------------------------------------
// PASSWORD CLASS
//------------------------------------------------

/**
 * @class Password
 *
 * @brief Defines how a password should be.
 *
 * Inherit of class Domain. Restrict the string to be at most of size 5 and if there is no repetition of caracters.
 *
 * @note The size is small for some reasons.
 */
class Password : public Domain {
  private:
    /// Maximum size of the password
    static const int allowed_size = 5;

    /// Maximum repetition
    static const int repetition_limit = 1; 

    /**
     * @name    Valid
     * @brief   Validate the Password
     *
     * Implementation of the virtaul function valid in Domain. Validate Password by verifying if the password is the determined size and if there are no repeated caracters.
     */
    void valid(string) throw(invalid_argument);

  public:
    /// Create a Password
    Password();

    /// Destroy a Password
    ~Password();
};

//------------------------------------------------
// EMAIL CLASS
//------------------------------------------------

/**
 * @class Email
 *
 * @brief Defines how a email should be.
 *
 * Inherit of class Domain. Restrict the string to follow the pattern l@l.l (being l any string with only alphabetic caracters).
 *
 * @note The restriction make it easier to check, but there are valid real email that do not follow this pattern.
 */
class Email : public Domain {
  private:
    /**
     * @name    Valid
     * @brief   Validate the Email
     *
     * Implementation of the virtaul function valid in Domain. Validate Email by verifying if the email follow the pattern l@l.l (being l any string with only alphabetic caracters).
     */
    void valid(string) throw(invalid_argument);

  public:
    /// Create a Email
    Email();

    /// Destroy a Email
    ~Email();
};

//------------------------------------------------
// TEXT CLASS
//------------------------------------------------

/**
 * @class Text
 *
 * @brief Defines how a text should be.
 *
 * Inherit of class Domain. Restrict the string to have size less than 50 caracters.
 *
 * @note Twiter like restriction.
 */
class Text : public Domain {
  private:
    /**
     * @name    Valid
     * @brief   Validate the Text
     *
     * Implementation of the virtaul function valid in Domain. Validate Text by verifying if the text has a size less than 50 caracters.
     */
    void valid(string) throw(invalid_argument);

  public:
    /// Create a Text
    Text();

    /// Destroy a Text
    ~Text();
};

//------------------------------------------------
// AVALIATION CLASS
//------------------------------------------------

/**
 * @class Text
 *
 * @brief Defines how a text should be.
 *
 * Restrict the string to have size less than 50 caracters.
 *
 * @note Avaliation should be integer from 0 to 5, inclusive (There will be no 4.5 or anything like that)
 */
class Avaliation {
  private:
    /// Keep the value of the avaliation.
    int value;

    /**
     * @name    Valid
     * @brief   Validate the Avaliation
     *
     * Validate Avaliation by verifying if the avaliation is a number in the interval [0, 5].
     */
    void valid(int) throw(invalid_argument);

  public:
    /// Create a Avaliation
    Avaliation();

    /// Destroy a Avaliation
    ~Avaliation();

    /**
     * @name    Get
     * @brief   Get the value of the integer
     *
     * @return Value of integer "value".
     */
    int get() const;

    /**
     * @name    Set
     * @brief   Modify the value of the keeped integer.
     * 
     * Set the keeped integer to the new value if is a Valid integer.
     */
    void set(int avaliation);
    
    /**
     * @name    Operator<<
     * @brief   Operator overload to make it possible print using cout
     */
    friend ostream& operator<<(ostream&, const Avaliation&);

	/**
     * @name    Operator<<
     * @brief   Operator overload to make it possible print using cin
     */
    friend istream& operator>>(istream&, Avaliation&);
};

//------------------------------------------------
// END GUARD
//------------------------------------------------

#endif

