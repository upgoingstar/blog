// GUARDS
#ifndef __WELCOME_VIEW_H_INCLUDED__
#define __WELCOME_VIEW_H_INCLUDED__

// INCLUDES
#include <bits/stdc++.h>
using namespace std;

/**
* A view class that controls interface with user
*/
class WelcomeView {
public:
	/*
	 * Render home page
	 */
	static void home_page();

	/*
	 * Renderiza tela de login
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 * TODO: Existe um espaço entre as opções onde virão as mensagens de erro em vermelho.
	 */
	static void login_page();
	
};

#endif