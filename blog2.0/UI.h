#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

class MainMenu{
private:
	const static int LOGIN = 1;
	const static int LOGOUT = 1;
	const static int REGISTER = 2;
	const static int ACCOUNT = 2;
	const static int LISTBLOGS = 3;
	const static int EXIT = 4;
	bool USERLOGGED = false;
	
public:
	void execute(); 
};

#endif
