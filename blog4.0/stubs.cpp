//------------------------------------------------
// Includes
//------------------------------------------------
#include "stubs.hpp"
#include "entity.hpp"
#include "domains.hpp"

using namespace std;

//------------------------------------------------
// Method Implementation of Class Stub
//------------------------------------------------
bool Stub::user_autenticate(Email toCheckEmail, Password toCheckPassword){
	Email registredEmail;
	registredEmail.set("stub@stub.stub");
	
	Password registredPassword;
	registredPassword.set("stubp");

	if(toCheckEmail == registredEmail and toCheckPassword == registredPassword){
		return true;
	}
	else{
		return false;
	}
};

bool Stub::user_find(Email toCheckEmail){
	Email registredEmail;
	registredEmail.set("stub@stub.stub");
	
	if(toCheckEmail == registredEmail){
		return true;
	}
	else{
		return false;
	}
}

vector<Blog> Stub::get_blogs(User stubUser){
	vector<Blog> stubBlogs;
	Blog stubBlog1,stubBlog2;
	Name stubBlogName;
	
	stubBlogName.set("Caludino Adventure");
	stubBlog1.set(stubUser.get_name(),stubBlogName);
		
	stubBlogName.set("A batata");
	stubBlog2.set(stubUser.get_name(),stubBlogName);
	
	stubBlogs.push_back(stubBlog1);	
	stubBlogs.push_back(stubBlog2);
	
	return stubBlogs;	
}

vector<Blog> Stub::get_all_blogs(){
	Email registredEmail;
	registredEmail.set("stub@stub.stub");
	
	Password registredPassword;
	registredPassword.set("stubp");
	
	Name registredName;
	registredName.set("stub");
	
	User stubUser;
	stubUser.set(registredName, registredEmail, registredPassword);
	
	
	vector<Blog> stubBlogs;
	Blog stubBlog1, stubBlog2, stubBlog3;
	Name stubBlogName;
	
	stubBlogName.set("Claudino Adventure");
	stubBlog1.set(stubUser.get_name(),stubBlogName);
		
	stubBlogName.set("A batata");
	stubBlog2.set(stubUser.get_name(),stubBlogName);
	
	stubBlogName.set("Outra coisa");
	stubBlog3.set(stubUser.get_name(),stubBlogName);
	
	stubBlogs.push_back(stubBlog1);	
	stubBlogs.push_back(stubBlog2);
	stubBlogs.push_back(stubBlog3);
	
	return stubBlogs;	
}

User Stub::get_user(Email email){
	Email registredEmail;
	registredEmail.set("stub@stub.stub");
	
	Password registredPassword;
	registredPassword.set("stubp");
	
	Name registredName;
	registredName.set("stub");
	
	User registredUser;
	registredUser.set(registredName, registredEmail, registredPassword);
	
	return registredUser;
}

vector<Post> Stub::get_posts(Blog blog){
	vector<Post> posts;
	Post aux;
	Text aux3;
	
	if(blog.get_blog_name().get() == "A batata"){
		aux3.set("Era uma vez uma batata que queria uma calca");
		aux.set_author(blog.get_author());
		aux.set_content(aux3);
		posts.push_back(aux);
		
		aux3.set("Mas ai deu um bug e veio uma bermuda");
		aux.set_author(blog.get_author());
		aux.set_content(aux3);
		posts.push_back(aux);
	}
	
	if(blog.get_blog_name().get() == "Claudino Adventure"){
		aux3.set("Claudino saiu em uma aventura cheia de perigos");
		aux.set_author(blog.get_author());
		aux.set_content(aux3);
		posts.push_back(aux);
		
		aux3.set("Claudino terminou sua aventura");
		aux.set_author(blog.get_author());
		aux.set_content(aux3);
		posts.push_back(aux);
	}
	
	if(blog.get_blog_name().get() == "Outra coisa"){
		aux3.set("Como faz pra excluir o blog?");
		aux.set_author(blog.get_author());
		aux.set_content(aux3);
		posts.push_back(aux);
	}
	
	return posts;
}
