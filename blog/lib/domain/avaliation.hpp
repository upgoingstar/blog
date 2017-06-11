// GUARDS
#ifndef __AVALIATION_H_INCLUDED__
#define __AVALIATION_H_INCLUDED__

// INCLUDES
#include "_domain.hpp"
#include <bits/stdc++.h>
using namespace std;

/**
 * Class Avaliation. Inherit of class Domain.
 * Valid avaliation. Verify if the avaliation is a number in the interval [0, 5].
 */
 // TODO: see the problems of this do not inherit from Domain
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
  void set(int avaliation);
};

#endif
