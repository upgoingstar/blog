class User{
	Name     name;
	Password password;
	Email    email;
	bool     anonymous;

	User(string n, string p, string e){
		name(n);
		password(p);
		email(e);
		anonymous = false;
	}

	User(){
		name("unknown");
		password("nknwn");
		email("unknown@unknown.unknown");
		anonymous = true;
	}

	vector<string> blogs;

  void add_blog(string new_blog){
      blogs.push_back(new_blog);
  }
};
