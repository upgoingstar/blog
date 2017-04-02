 int error;

//TODO: create a class to deal with db queries
vector<User> registred_Users;
map<string,int> users_id; //OBTER TODOS OS DADOS DO USUARIO APARTIR DO NOME


void sign_up(){
	string name;
	string password;
	string email;

	sign_up_page(name, password, email);

	User(name, password, email);
	registred_Users.push_back(valid_user);
	users_id.insert(make_pair(name,registred_Users.size()-1));

	successful_sign_up_page(name);
}

void blog(User current_user){

}

void sign_in(){
	string name;
	string password;

	do{
		sign_in_page(&name, &password);
	}while(!users_id.count(name) ? 1 : registred_Users[users_id[name]].password != password);

	render_blog(registred_Users[users_id[name]]);
}

int main(){
	set_users_db(); // le os arquivos
	initial_page();
	create_db();
}
