//------------------------------------------------
// Includes
//------------------------------------------------
#include "stubs.hpp"
#include "domains.hpp"

using namespace std;

//------------------------------------------------
// Method Implementation of Class Stub
//------------------------------------------------
bool Stub::userAutenticate(Email toCheckEmail, Password toCheckPassword){
	Email registredEmail;
	registredEmail.set("stub@stub.stub");
	
	Password registredPassword;
	registredPassword.set("stubp");

	if(toCheckEmail == registredEmail && toCheckPassword == registredPassword){
		return true;
	}
	else{
		return false;
	}
};

bool Stub::userFind(Email toCheckEmail){
	Email registredEmail;
	registredEmail.set("stub@stub.stub");
	
	if(toCheckEmail == registredEmail){
		return true;
	}
	else{
		return false;
	}
}

vector<Blog> Stub::getBlogs(User stubUser){
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
