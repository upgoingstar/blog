  // GUARDS
  #ifndef __EMAIL_H_INCLUDED__
  #define __EMAIL_H_INCLUDED__

  // INCLUDES
  #include "_domain.hpp"
  #include <bits/stdc++.h>
  using namespace std;

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

  #endif
