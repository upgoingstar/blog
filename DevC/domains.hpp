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
// Abstract Class Domain
//------------------------------------------------

  /**
   * An Abstract Class Domain.
   * Keeps a string for all classes that inherit this class and implement the methods get and set (respectively, see and modify the value keeped). Also declares a virtual method "valid" for each class implement.
   */
  class Domain {
  protected:
    /**
     * A protected string.
     * Keep a value for all classes that inherit this one.
     */
    string value;

    /**
     * A virtual method.
     * For all classes that inherit this implement their own validation. Utilized in method set.
     */
    virtual void valid(string) throw(invalid_argument) = 0;

  public:
    /**
     * A public constructor.
     */
    Domain();

    /**
     * A public destructor.
     */
    ~Domain();

    /**
     * A public method
     * @return Value of the keeped string.
     */
    string get();

    /**
     * A public method
     * Warn if the string is empty.
     */
    bool empty();

    /**
     * A public method
     * Modify the value of the keeped string.
     */
    void set(string);

    /**
     * Make it possible to compare if one Domain object has different value than other.
     */
    bool operator!=(const Domain &other) const;

    /**
     * Make it possible to compare if one Domain object has igual value than other.
     */
    bool operator==(const Domain &other) const;

    /**
     * Make it possible to compare if one Domain object has better value than other.
     */
    bool operator<(const Domain &other) const;
  };

//------------------------------------------------
// Class Name
//------------------------------------------------

  /**
   * A class Name. Inherit of class Domain.
   * Valid name. Limit the size of the name.
   */
  class Name : public Domain {
  private:

    /**
     * A protected static constant integer.
     * Limit the size of the name.
     */
    static const int size_limit = 20;

    /**
     * Validate Name by verifying if the name is not bigger than the limit and see if all caracters are alphabetic or spaces.
     */
    void valid(string) throw(invalid_argument);

  public:
    /**
     * A public constructor.
     */
    Name();

    /**
     * A public destructor.
     */
    ~Name();
  };

//------------------------------------------------
// Class Password
//------------------------------------------------

  /**
   * A class Password. Inherit of class Domain.
   * Valid password. Define the size of the password and does not permit that more than 1 caracter repeats.
   */
  class Password : public Domain {
  private:
    /**
     * A protected static constant integer.
     * Delimits the size of the password.
     */
    static const int allowed_size = 5;

    /**
     * A protected static constant integer.
     * Limits the quantity of repeticion of caracters.
     */
    static const int repetition_limit = 1;

    /**
     * Validate Password by verifying if the password is the determined size and if there are no repeated caracters.
     */
    void valid(string) throw(invalid_argument);

  public:
    /**
     * A public constructor.
     */
    Password();

    /**
     * A public destructor.
     */
    ~Password();
  };

//------------------------------------------------
// Class Email
//------------------------------------------------

  /**
   * A class Email. Inherit of class Domain.
   * Valid email. Verify if the email follow the pattern l@l.l (being l any string with only alphabetic caracters).
   */
  class Email : public Domain {
  private:
    /**
     * Validate Email by verifying if the email follow the pattern l@l.l (being l any string with only alphabetic caracters).
     */
    void valid(string) throw(invalid_argument);

  public:
    /**
     * A public constructor.
     */
    Email();

    /**
     * A public destructor.
     */
    ~Email();
  };

//------------------------------------------------
// Class Text
//------------------------------------------------

  /**
   * A class Text. Inherit of class Domain.
   * Valid the text. Verify if the text has a size less than 50 caracters.
   */
  class Text : public Domain {
  private:
    /**
     * Validate Text by verifying if the text has a size less than 50 caracters.
     */
    void valid(string) throw(invalid_argument);

  public:
    /**
     * A public constructor.
     */
    Text();

    /**
     * A public destructor.
     */
    ~Text();
  };

//------------------------------------------------
// Class Avaliation
//------------------------------------------------

  /**
   * A class Avaliation. Inherit of class Domain.
   * Valid avaliation. Verify if the avaliation is a number in the interval [0, 5].
   */
  class Avaliation {
  private:
    /**
     * A variable integer and protected.
     * Keep the value of the avaliation.
     */
    int value;

    /**
     * Validate Avaliation by verifying if the avaliation is a number in the interval [0, 5].
     */
    void valid(int) throw(invalid_argument);

  public:
    /**
     * A public constructor.
     * Inicialize with minimum value.
     */
    Avaliation();

    /**
     * A public destructor.
     */
    ~Avaliation();

    /**
     * A public method
     * @return Value of the keeped string.
     */
    int get();

    /**
     * A public method
     * Modify the value of the keeped string. If no value was given, it will consider that was given the minimum value.
     */
    void set(int avaliation = 0);
  };

#endif
