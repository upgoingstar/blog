class Database {
	void create_db(){
		remove("users.txt");
	    ofstream new_file("users.txt");
	    for(int i = 0; i < (int)registred_Users.size(); i++){
	    	new_file << registred_Users[i].name + "|";
	    	new_file << registred_Users[i].password + "|";
	    	new_file << registred_Users[i].email + "|";
	    	for(int j = 0; j < (int)registred_Users[i].blogs.size(); j++)
	    		new_file << registred_Users[i].blogs[j] + "|";
	    	new_file << '\n';
	    }
	    new_file.close();
	}

	void set_users_db(){
	    ifstream users_file("users.txt");

	    if(users_file.is_open()){

		    string user_info;

		    while(getline(users_file, user_info)){
		        string nick;
		        string password;
		        string email;

		        int i = 0;

		        for(; user_info[i] != '|'; i++){
		            nick += user_info[i];
		        }

		        for(i++; user_info[i] != '|'; i++){
		            password += user_info[i];
		        }

		        for(i++; user_info[i] != '|'; i++){
		            email += user_info[i];
		        }

		        User new_user(nick,password,email);

		        while(i < (int)user_info.size() - 1){
		            string blog;

		            for(i++; user_info[i] != '|'; i++){
		                blog += user_info[i];
		            }

		            new_user.add_blog(blog);
		        }

		        registred_Users.push_back(new_user);
		        users_id[nick] = registred_Users.size()-1;
		    }

		    users_file.close();
		}
	}
};
