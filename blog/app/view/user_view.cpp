// INCLUDES
#include "../../lib/view/user_view.hpp"
#include <bits/stdc++.h>
using namespace std;

// IMPLEMENTATION
Name UserView::field_name_page() {
	cout << "field page name" << endl;
	Name name;
	name.set("Algum Exemplo");
	return name;
}

Email UserView::field_email_page() {
	cout << "field page email" << endl;
	Email email;
	email.set("exemplo@exemplo.com");
	return email;
}

Password UserView::field_password_page() {
	cout << "field page password" << endl;
	Password password;
	password.set("123456");
	return password;
}

void UserView::create_page() {
	cout << "create user page" << endl;
}

void UserView::show_page(bool, unsigned int) {
	cout << "show user page" << endl;
}

void UserView::edit_page(unsigned int) {
	cout << "edit user page" << endl;
}

void UserView::delete_page(unsigned int) {
	cout << "delete user page" << endl;
}
