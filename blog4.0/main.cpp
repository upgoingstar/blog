/**
 * @Author Claudio (claudiosegalafilho@gmail.com), Luis Gebrim (?)
 * @brief  A simulation of a blog.
 *
 * An simple simulation of a blog with persistence and following the MVC. Made all in OOP for training.
 */

#include "domains.hpp"
#include "entity.hpp"
#include "controller.hpp"
#include "model.hpp"
#include "view.hpp"

// TODO: it does need all this includes?

int main() {
  WelcomeView::home_page();
  return 0;
}
