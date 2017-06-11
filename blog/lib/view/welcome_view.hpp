// GUARDS
#ifndef __WELCOME_VIEW_H_INCLUDED__
#define __WELCOME_VIEW_H_INCLUDED__

// INCLUDES
#include <bits/stdc++.h>
using namespace std;

/**
* A view class that show home page
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
	 * TODO: This funtion will be part of a class named Auth 
	 */
	static void login_page();
	
};

#endif
