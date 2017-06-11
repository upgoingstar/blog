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