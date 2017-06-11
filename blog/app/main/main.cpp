#include "super_header.hpp"

// some structure

// each controller inherit from Controller class
// each model inherit from Model class
// each view inherit from View class

// each controller, model and view are friends of each other

int main() {
	WelcomeView::home_page();
	return 0;
}