#include "../hdr/test_entities.hpp"
#include "../hdr/domains.hpp"
#include "../hdr/entities.hpp"
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------
// Method Implementation of Class TestUser
// ------------------------------------------------

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

// ------------------------------------------------
// Method Implementation of Class TestComment
// ------------------------------------------------

TestComment::TestComment(){}

TestComment::~TestComment(){}

void TestComment::success_scenario(Name name, Text text){
	try{
		Comment testAuxiliar(name,text);
		if(name != testAuxiliar.get_author() || text != testAuxiliar.get_content())
			throw invalid_argument("Invalid Class!");
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestComment::failure_scenario(Name name, Text text){
	bool daerro = false;
	try{
		Comment testAuxiliar(name,text);
		daerro = true;
	}
	catch(invalid_argument erro){}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
}

void TestComment::verify(){
	Name correct_name, incorrect_name;
	Text correct_text, incorrect_text;
	correct_name.set("Batata");
	correct_text.set("Batata de bermuda");
	success_scenario(correct_name,correct_text);
	failure_scenario(incorrect_name,incorrect_text);
}

// ------------------------------------------------
// Method Implementation of Class TestPost
// ------------------------------------------------

TestPost::TestPost(){}

TestPost::~TestPost(){}

void TestPost::success_scenario(Name name, Text text){
	try{
		Post testAuxiliar(name,text,true);
		if(name != testAuxiliar.get_author() || text != testAuxiliar.get_content())
			throw invalid_argument("Invalid Class!");
		Comment testAuxiliar2(name,text);
		try{
			testAuxiliar.add_comment(testAuxiliar2);
		}
		catch(invalid_argument erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestPost::failure_scenario(Name name, Text text){
	bool daerro = false;
	try{
		Post testAuxiliar(name,text);
		daerro = true;
	}
	catch(invalid_argument erro){}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
}

void TestPost::failure_scenario2(Name name, Text text){
	bool daerro = false;
	try{
		Post testAuxiliar(name,text);
		Comment testAuxiliar2(name,text);
		testAuxiliar.add_comment(testAuxiliar2);
		daerro = true;
	}
	catch(invalid_argument erro){}

	try{
		Post testAuxiliar(name,text,1);
		Comment testAuxiliar2(name,text);
		testAuxiliar.add_comment(testAuxiliar2);
		testAuxiliar.add_comment(testAuxiliar2);
		testAuxiliar.add_comment(testAuxiliar2);
		testAuxiliar.add_comment(testAuxiliar2);
		testAuxiliar.add_comment(testAuxiliar2);
		testAuxiliar.add_comment(testAuxiliar2);
		daerro = true;
	}
	catch(invalid_argument erro){}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
}

void TestPost::verify(){
	Name correct_name, incorrect_name;
	Text correct_text, incorrect_text;
	correct_name.set("Batata de bermuda");
	correct_text.set("Queria uma calca muito chique pra minha batata");
	success_scenario(correct_name,correct_text);
	failure_scenario(incorrect_name,incorrect_text);
	failure_scenario2(correct_name,correct_text);
}

TestBlog::TestBlog(){}

TestBlog::~TestBlog(){}

void TestBlog::success_scenario(Name name, Text text){
	try{
		Blog testAuxiliar(name,text);
		if(name != testAuxiliar.get_author() || text != testAuxiliar.get_content())
			throw invalid_argument("Invalid Class!");
			Post testAuxiliar2(name,text);
		try{
			testAuxiliar.add_post(testAuxiliar2);
		}
		catch(invalid_argument erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestBlog::failure_scenario(Name name, Text text){
	bool daerro = false;
	try{
		Blog testAuxiliar(name,text);
		daerro = true;
	}
	catch(invalid_argument erro){}
	name.set("Batata");
	text.set("Calca chique");
	Blog testAuxiliar(name,text);
	Name name2;
	name2.set("Calca chique");
	Post testAuxiliar2(name2,text);
	try{
		testAuxiliar.add_comment(testAuxiliar2);
		daerro = true;
	}
	catch(invalid_argument erro){}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
}

void TestBlog::verify(){
	Name correct_name, incorrect_name;
	Text correct_text, incorrect_text;
	correct_name.set("Batata de bermuda");
	correct_text.set("Queria uma calca muito chique pra minha batata");
	success_scenario(correct_name,correct_text);
	failure_scenario(incorrect_name,incorrect_text);
}
