#include "../hdr/test_entities.hpp"
#include "../hdr/domains.hpp"
#include "../hdr/entities.hpp"
#include <bits/stdc++.h>
using namespace std;

TestUser::TestUser(){}

TestUser::~TestUser(){}

void TestUser::success_scenario(Name name, Email email, Password password){
	User testAuxiliar;

	try{
		testAuxiliar.set(name,email,password);
		try{
			Name testAuxiliar2 = testAuxiliar.get_name();
			if(testAuxiliar2 != name){
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(invalid_argument erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}

	try{
		testAuxiliar.check_user(email,password);
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestUser::failure_scenario(Name name, Email email, Password password){
	bool daerro = false;
	User testAuxiliar;

	try{
		testAuxiliar.set(name,email,password);
		daerro = true;
	}
	catch(invalid_argument erro){
		try{
			testAuxiliar.get_name();
			daerro = true;
		}
		catch(invalid_argument erro){}
	}
	
	try{
		testAuxiliar.check_user(email,password);
		daerro = true;
	}
	catch(invalid_argument erro){}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
}

void TestUser::verify(){
	Name correct_name, incorrect_name;
	Password correct_password, incorrect_password;
	Email correct_email, incorrect_email;
	correct_name.set("Abacaba");
	correct_password.set("12345");
	correct_email.set("l@l.l");
	success_scenario(correct_name,correct_email,correct_password);
	failure_scenario(incorrect_name,incorrect_email,incorrect_password);
}
