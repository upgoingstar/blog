  // GUARDS
  #ifndef __DOMAIN_H_INCLUDED__
  #define __DOMAIN_H_INCLUDED__

  // INCLUDES
  #include <bits/stdc++.h>
  using namespace std;

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