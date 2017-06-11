// GUARDS
#ifndef __CONTENT_H_INCLUDED__
#define __CONTENT_H_INCLUDED__

// INCLUDES
#include "../domain/_domain.hpp"
#include "../domain/name.hpp"
#include "../domain/text.hpp"
#include "../domain/avaliation.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
// TODO: this is confuse
class Content {
private:
	/**
	 * A private method
	 * Checks if any of the value is empty.
	 */
	void valid(Name, Text) throw(invalid_argument);

protected:
	/**
	 * A protected variable of class Name.
	 * Keeps the name of the author of the content.
	 */
	Name author;

	/**
	 * A protected variable of class Text.
	 * Keeps the content.
	 */
	Text content;

	/**
	 * A protected variable of class Map.
	 * Keeps the name that everyone that has already avaliated.
	 */
	map<Name, bool> has_avaliated;

	/**
	 * A protected variable of class Vector.
	 * Keeps the avaliations.
	 */
	vector<Avaliation> avaliations;
	
public:
	/**
	 * A public constructor.
	 */
	Content();

	/**
	 * A public destructor.
	 */
	~Content();

	/**
	 * A public method
	 * @return Value of the author of the content.
	 */
	Name get_author();

	/**
	 * A public method
	 * @return Value of the content.
	 */
 	Text get_content();

	/**
	 * A public method
	 * @return The arithmetic mean of all avaliations given the to content in question.
	 */
	Avaliation get_avaliation();

	/**
	 * A public method
	 * It receives the name of the author of the content and the content and valid them.
	 */
  void set(Name, Text);

	/**
	 * A public method.
	 * Add an avaliation, making sure that no user do more than one avaliation.
	 * It receives a the name of the current user and the avaliation.
	 */
  void add_avaliation(Name, Avaliation) throw(invalid_argument);
};

#endif
