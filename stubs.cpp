#include "stubs.hpp"
#include "entity.hpp"
#include "domains.hpp"

using namespace std;

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

	time_t seconds;
	stringstream ss;
	string s;
	Id stubBlogId;
	
	seconds = time(0);
	ss << seconds;
	s = ss.str();
	stubBlogId.set(s);
	stubBlogName.set("Claudino Adventure");
	stubBlog1.set(stubBlogId, stubUser.get_name(),stubBlogName);
		
	seconds = time(0);
	ss << seconds;
	s = ss.str();
	stubBlogId.set(s);
	stubBlogName.set("A batata");
	stubBlog2.set(stubBlogId, stubUser.get_name(),stubBlogName);
	
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
	
	time_t seconds;
	stringstream ss;
	string s;
	Id stubUserId;

	seconds = time(0);
	ss << seconds;
	s = ss.str();
	stubUserId.set(s);
	User stubUser;
	stubUser.set(stubUserId, registredName, registredEmail, registredPassword);
	
	
	vector<Blog> stubBlogs;
	Blog stubBlog1, stubBlog2, stubBlog3;
	Name stubBlogName;
	
	Id stubBlogId;

	seconds = time(0);
	ss << seconds;
	s = ss.str();
	stubBlogId.set(s);
	stubBlogName.set("Claudino Adventure");
	stubBlog1.set(stubBlogId, stubUser.get_name(),stubBlogName);
	
	seconds = time(0);
	ss << seconds;
	s = ss.str();
	stubBlogId.set(s);
	stubBlogName.set("A batata");
	stubBlog2.set(stubBlogId, stubUser.get_name(),stubBlogName);
	
	Id registredId;

	seconds = time(0);
	ss << seconds;
	s = ss.str();
	registredId.set(s);
	registredName.set("Gabierl");
	stubUser.set(registredId, registredName, registredEmail, registredPassword);
	stubBlogName.set("Outra coisa");
	stubBlog3.set(stubBlogId, stubUser.get_name(),stubBlogName);
	
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
	
	Id registredId;
	
	stringstream ss;
	time_t seconds = time(0);

	ss << seconds;

	string s = ss.str();

	registredId.set(s);
	
	registredUser.set(registredId, registredName, registredEmail, registredPassword);
	
	return registredUser;
}

vector<Post> Stub::get_posts(Blog blog){
	vector<Post> posts;
	Id aux2;
	Post aux;
	Text aux3;
	
	if(blog.get_name().get() == "A batata"){
		aux3.set("Uma batata queria uma calca muito chique");
		aux2.set("987");
		aux.set(aux2, blog.get_id(), blog.get_author(), aux3);
		posts.push_back(aux);
		
		aux3.set("Mas ai deu um bug e veio uma bermuda");
		aux2.set("93387");
		aux.set(aux2, blog.get_id(), blog.get_author(), aux3);
		posts.push_back(aux);
	}
	
	if(blog.get_name() == "Claudino Adventure"){
		aux3.set("Claudino saiu em uma aventura cheia de perigos");
		aux2.set("987788");
		aux.set(aux2, blog.get_id(), blog.get_author(), aux3);
		posts.push_back(aux);
		
		aux3.set("Claudino terminou sua aventura");
		aux2.set("985557");
		aux.set(aux2, blog.get_id(), blog.get_author(), aux3);
		posts.push_back(aux);
	}
	
	if(blog.get_name() == "Outra coisa"){
		aux3.set("Como faz pra excluir o blog?");
		aux2.set("1212987");
		aux.set(aux2, blog.get_id(), blog.get_author(), aux3);
		posts.push_back(aux);
	}
	
	return posts;
}

vector<Comment> Stub::get_comments(Post post){
	vector<Comment> comments;
	Comment aux;
	Id aux2;
	Text aux3;
	Name aux4;
	Id aux5;
	
	if(post.get_content() == "Uma batata queria uma calca muito chique"){
		aux2.set("1234");
		aux5.set("1236");
		aux3.set("Que emocionante, mal posso esperar a continuacao");
		aux4.set("Carinha");
		aux.set(aux2, aux5, aux4, aux3);
		comments.push_back(aux);
		
		aux2.set("12434");
		aux5.set("121236");
		aux3.set("A historia mais empolgante que ja li!");
		aux4.set("Fildosve");
		aux.set(aux2, aux5, aux4, aux3);
		comments.push_back(aux);
	}
	
	if(post.get_content() == "Mas ai deu um bug e veio uma bermuda"){
		aux2.set("1231234");
		aux5.set("12312326");
		aux3.set("Final triste ;(");
		aux4.set("Carinha");
		aux.set(aux2, aux5, aux4, aux3);
		comments.push_back(aux);
		
		aux2.set("1211234");
		aux5.set("123336");
		aux3.set("A batata vai aprender a amar sua bermuda!");
		aux4.set("Genoscla");
		aux.set(aux2, aux5, aux4, aux3);
		comments.push_back(aux);
		
		aux2.set("123574");
		aux5.set("12536");
		aux3.set("Aff, que virjao, sai do computador e vai comer uma");
		aux4.set("Jyubertw");
		aux.set(aux2, aux5, aux4, aux3);
		comments.push_back(aux);
		
	}
	
	if(post.get_content() == "Como faz pra excluir o blog?"){
		aux2.set("1239574");
		aux5.set("12396");
		aux3.set("Vai na pagina de deletar o blog");
		aux4.set("stub");
		aux.set(aux2, aux5, aux4, aux3);
		comments.push_back(aux);
		
	}
	
	aux2.set("12395174");
	aux5.set("123196");
	aux3.set("Bolsonaro 2018!");
	aux4.set("Pedrinho");
	aux.set(aux2, aux5, aux4, aux3);
	comments.push_back(aux);
	
	return comments;
 }
