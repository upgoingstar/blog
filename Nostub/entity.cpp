	#include "domains.hpp"
	#include "entity.hpp"
	#include <bits/stdc++.h>
	using namespace std;

// COMMENT CLASS --------------------------------------------------------------------------------------------

	Comment::Comment() {}

	Comment::~Comment() {}

	void Comment::valid(Text content) throw(invalid_argument) {
		if(content.empty()) {
			throw invalid_argument("Invalid informations to compose a content!");
		}
	}

	bool Comment::empty() {
		return this->author.empty() or this->content.empty();
	}

	void Comment::set_author(Name author) {
		this->author = author;
	}

	void Comment::set_content(Text content) {
		Comment::valid(content);
		this->content = content;
	}

	void Comment::set_avaliation(Name name, Avaliation avaliation) throw(invalid_argument) {
		if(has_avaliated[name]) {
			throw invalid_argument("This user has already avaliated!");
		} else {
			this->avaliations.push_back(avaliation);
			has_avaliated[name] = true;
		}
	}

	Name Comment::get_author() {
		if(this->author.empty()){
			throw invalid_argument("There is no author!");
		}
		return this->author;
	}

	Text Comment::get_content() {
		if(this->content.empty()){
			throw invalid_argument("There is no content to show!");
		}
		return this->content;
	}

	Avaliation Comment::get_avaliation() {
		int total_sum = 0;
		int total_size = int(this->avaliations.size());

		for(int i = 0; i < int(avaliations.size()); i++) {
			Avaliation avaliation = avaliations[i];
			total_sum += avaliation.get();
		}

		Avaliation ans;
		if(total_size != 0){
			ans.set(total_sum / total_size);
		}
		else{
			ans.set(0);
		}

		return ans;
	}

// POST CLASS ----------------------------------------------------------------------------------------------

	Post::Post() {}

	Post::~Post() {}

	void Post::valid(Text content) throw(invalid_argument) {
		if(content.empty()) {
			throw invalid_argument("Invalid informations to compose a content!");
		}
	}

	bool Post::empty() {
		return this->author.empty() or this->content.empty();
	}

	Name Post::get_author() {
		if(this->author.empty()){
			throw invalid_argument("There is no author!");
		}
		return this->author;
	}

	Text Post::get_content() {
		if(this->content.empty()){
			throw invalid_argument("There is no content to show!");
		}
		return this->content;
	}

	Avaliation Post::get_avaliation() {
		int total_sum = 0;
		int total_size = int(this->avaliations.size());

		for(int i = 0; i < int(avaliations.size()); i++) {
			Avaliation avaliation = avaliations[i];
			total_sum += avaliation.get();
		}
	
		Avaliation ans;
		if(total_size != 0){
			ans.set(total_sum / total_size);
		}
		else{
			ans.set(0);
		}
	
		return ans;
	}

	vector<Comment> Post::get_comments() {
		if(this->comments.empty()){
			throw invalid_argument("There is no comments!");
		}
		return this->comments;
	}

	void Post::set_author(Name author) {
		this->author = author;
	}

	void Post::set_content(Text content) {
		Post::valid(content);
		this->content = content;
	}

	void Post::set_avaliation(Name name, Avaliation avaliation) throw(invalid_argument) {
		if(has_avaliated[name]) {
			throw invalid_argument("This user has already avaliated!");
		} else {
			this->avaliations.push_back(avaliation);
			has_avaliated[name] = true;
		}
	}

	void Post::set_comment(Comment comment) throw(invalid_argument) {
		if(comments_allowed and number_comments[comment.get_author()] < comments_limit) {
			number_comments[comment.get_author()]++;
			this->comments.push_back(comment);
		} else {
			throw invalid_argument("This comment is not allowed!");
		}
	}

	void Post::allow_comments() {
		comments_allowed = true;
	}

	void Post::disallow_comments() {
		comments_allowed = false;
		this->comments.clear();
	}

// BLOG CLASS ----------------------------------------------------------------------------------------------

	Blog::Blog(){}

	Blog::~Blog() {}

	Name Blog::get_author() throw(invalid_argument) {
		if(this->author.empty()){
			throw invalid_argument("There is no author!");
		}
		return this->author;
	}

	Name Blog::get_name() throw(invalid_argument) {
		if(this->blog_name.empty()){
			throw invalid_argument("This blog has no name!");
		}
		return this->blog_name;
	}

	vector<Post> Blog::get_posts() throw(invalid_argument) {
		if(this->posts.empty()){
			throw invalid_argument("There is no posts in this Blog!");
		}
		return this->posts;
	}

	void Blog::set(Name author, Name blog_name) throw(invalid_argument) {
		if(author.empty() or blog_name.empty())
			throw invalid_argument("Invalid blog name or author!");
		this->author = author;
		this->blog_name = blog_name;
	}

	void Blog::set_name(Name blog_name) throw(invalid_argument) {
		if(blog_name.empty()) {
			throw invalid_argument("Invalid blog name!"); 
		}
		this->blog_name = blog_name;
	}

	void Blog::set_post(Post post) throw(invalid_argument) {
		if(this->author != post.get_author()) {
			throw invalid_argument("You are not allowed to post in this blog!");
		} else {
			this->posts.push_back(post);
		}
	}

// USER CLASS -----------------------------------------------------------------------------------------------

	User::User() {
		this->anonymous = true;
	}

	User::~User() {}

	void User::valid(Id id, Name name, Email email, Password password) throw(invalid_argument) {
		if(id.empty() or name.empty() or email.empty() or password.empty()) {
			throw invalid_argument("Invalid informations to compose a user!");
		}
	}

	Id User::get_id() throw(invalid_argument) {
		if(anonymous) {
			throw invalid_argument("This user is anonymous, doesn't have a id");
		} else if(this->id.empty()) {
			throw invalid_argument("This user doesn't have a id");
		} else {
			return this->id;
		}
	}

	Name User::get_name() throw(invalid_argument) {
		if(anonymous) {
			throw invalid_argument("This user is anonymous, doesn't have a name");
		} else if(this->name.empty()) {
			throw invalid_argument("This user doesn't have a name");
		} else {
			return this->name;
		}
	}

	Email User::get_email() throw(invalid_argument) {
		if(anonymous) {
			throw invalid_argument("This user is anonymous, doesn't have a email");
		} else if(this->email.empty()) {
			throw invalid_argument("This user doesn't have a email");
		} else {
			return this->email;
		}
	}

	Password User::get_password() throw(invalid_argument) {
		if(anonymous) {
			throw invalid_argument("This user is anonymous, doesn't have a password");
		} else if(this->password.empty()) {
			throw invalid_argument("This user doesn't have a password");
		} else {
			return this->password;
		}
	}

	void User::set(Id id, Name name, Email email, Password password) {
		User::valid(id, name, email,password);
		this->id = id;
		this->name = name;
		this->password = password;
		this->email = email;
		this->anonymous = false;
	}

	void User::set_password(Password password) {
		User::valid(this->id, this->name, this->email, password);
		this->password = password;
	}

// AUTH CLASS -----------------------------------------------------------------------------------------------

	bool Auth::userLogged = false;
	User Auth::currentUser;

	bool Auth::user_logged() { 
		return userLogged;
	}

	User Auth::get_current_user() throw(invalid_argument) {
		if(Auth::user_logged()) {
			return currentUser;
		} else {
			throw invalid_argument ("Nenhum usuario esta logado");
		}
	}

	void Auth::login(User user) {
		userLogged = true;
		currentUser = user;
	}

	void Auth::logout(){
		userLogged = false;
	}
