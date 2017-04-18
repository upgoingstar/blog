// Control of Input
#define LOGIN   '1'
#define SIGNUP  '2'
#define VISITOR '3'
#define EXIT    '4'

// Colors
#define KNRM  "\x1b[0m"
#define KRED  "\x1b[31m"
#define KGRN  "\x1b[32m"
#define KYEL  "\x1b[33m"
#define KBLU  "\x1b[34m"
#define KMAG  "\x1b[35m"
#define KCYN  "\x1b[36m"
#define KWHT  "\x1b[37m"
#define RESET "\x1b[0m"

// Clean Screen Multiplataform Support
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


void get_enter(){
	char a;

	do{
		a = getchar();
	}while(a != '\n');
}

void get_input(int* ch) {
  struct termios oldt;
  struct termios newt;
  tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
  newt = oldt; /* copy old settings to new settings */
  newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
  (*ch) = getchar(); /* standard getchar call */
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
  (*ch) -= 48; /*return received char */
}

void get_input(char* ch) {
  struct termios oldt;
  struct termios newt;
  tcgetattr(STDIN_FILENO, &oldt); /*store old settings */
  newt = oldt; /* copy old settings to new settings */
  newt.c_lflag &= ~(ICANON | ECHO); /* make one change to old settings in new settings */
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); /*apply the new settings immediatly */
  (*ch) = getchar(); /* standard getchar call */
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt); /*reapply the old settings */
}

void error_message(){
	switch(error){
		case INV_OP:
			cout << KRED "Invalid option" RESET << endl;
			break;
		case NICK_E:
			cout << KRED "The username must contain only letters and at most 20 characters" RESET << endl;
			break;
		case PASS_E:
			cout << KRED "The password must contain 5 characters whitout repetition" RESET << endl;
			break;
		case MAIL_E:
			cout << KRED "The e-mail must contain only letters in the format: letters@letters.letters" RESET << endl;
			break;
		case N_USER:
			cout << KRED "The name or the password is invalid" RESET << endl;
	}

	error = NO_MSG;
}

void successful_sign_up_page(string name){
	system(CLEAR);

	cout << "Congratulations " << name << "! You are now a member of the blog BLOG!\n";
	cout << "Press ENTER to return to the initial menu and Sing In\n";

	get_enter();
}

void sign_up_page(string& name, string& password, string& email){
	system(CLEAR);

	cout << "Username: ";
	getline(cin, name);

	cout << "Password: ";
	getline(cin, password);

	cout << "Email: ";
	getline(cin, email);
}

void sign_in_page(string& name, string& password){
	char op;

	system(CLEAR);

	cout << "1 - Login" << endl;
	cout << "2 - Exit" << endl;
	cin >> op;
	getchar();

	if(op == '2'){
		return;
 	}

	cout << "Username: ";
	getline(cin, name);

	cout << "Password: ";
	getline(cin, password);
}

void start_page(){
	system(CLEAR);

	cout << "1 - Sign In" << endl;
	cout << "2 - Sign Up" << endl;
	cout << "3 - Visitant mode" << endl;
	cout << "4 - Exit" << endl;
}

void initial_page(){
	bool not_leave = true;

	error = NO_MSG;

	while(not_leave){
		char op;

		start_page();
		error_message();
		cin >> op;
		getchar();

		switch(op){
			case LOGIN:
				sign_in();
				break;
			case SIGNUP:
				sign_up();
				break;
			case VISITOR:{
				User visitor;
				blog(visitor);
			}break;
			case EXIT:
				not_leave = false;
				break;
			default:
				error = INV_OP;
		}
	}
}
