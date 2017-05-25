  // GUARDS
  #ifndef __TEXT_H_INCLUDED__
  #define __TEXT_H_INCLUDED__

  // INCLUDES
  #include "_domain.hpp"
  #include <bits/stdc++.h>
  using namespace std;

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

  #endif