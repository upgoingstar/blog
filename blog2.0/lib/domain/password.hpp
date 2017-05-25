  // GUARDS
  #ifndef __PASSWORD_H_INCLUDED__
  #define __PASSWORD_H_INCLUDED__

  // INCLUDES
  #include "_domain.hpp"
  #include <bits/stdc++.h>
  using namespace std;

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

  #endif
