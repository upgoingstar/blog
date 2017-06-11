  // GUARDS
  #ifndef __NAME_H_INCLUDED__
  #define __NAME_H_INCLUDED__

  // INCLUDES
  #include "_domain.hpp"
  #include <bits/stdc++.h>
  using namespace std;

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

  #endif
