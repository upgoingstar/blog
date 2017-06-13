#include "test_entities.hpp"
#include "domains.hpp"
#include "entities.hpp"
#include <bits/stdc++.h>
using namespace std;

	/*
		Para todos os sad paths, foram usados strings vazias
	*/

// ------------------------------------------------
// Method Implementation of Class TestUser
// ------------------------------------------------

	TestUser::TestUser() {}

	TestUser::~TestUser() {}

	void TestUser::success_scenario(Name name, Email email, Password password) throw(invalid_argument) {
		User testAuxiliar;

		try {
			testAuxiliar.set(name,email,password);
			try {
				Name testAuxiliar2 = testAuxiliar.get_name();
				if(testAuxiliar2 != name) {
					throw invalid_argument ("Invalid Class!");
				}
			}
			catch(invalid_argument erro) {
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(invalid_argument erro) {
			throw invalid_argument ("Invalid Class!");
		}

		try {
			testAuxiliar.check_user(email,password);
		}
		catch(invalid_argument erro) {
			throw invalid_argument ("Invalid Class!");
		}
	}

	void TestUser::failure_scenario(Name name, Email email, Password password) throw(invalid_argument) {
		bool errorOcurred = false;
		User testAuxiliar;

		try {
			testAuxiliar.set(name,email,password);
			errorOcurred = true;
		}
		catch(invalid_argument erro) {
			try {
				testAuxiliar.get_name();
				errorOcurred = true;
			}
			catch(invalid_argument erro) {}
		}

		try {
			testAuxiliar.check_user(email,password);
			errorOcurred = true;
		}
		catch(invalid_argument erro) {}
		if(errorOcurred) {
			throw invalid_argument ("Invalid Class!");
		}
	}

	void TestUser::verify() {
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

	TestComment::TestComment() {}

	TestComment::~TestComment() {}

	void TestComment::success_scenario(Name name, Text text) throw(invalid_argument) {
		try {
			Comment testAuxiliar(name,text);
			if(name != testAuxiliar.get_author() or text != testAuxiliar.get_content()) {
				throw invalid_argument("Invalid Class!");
			}
		}
		catch(invalid_argument erro) {
			throw invalid_argument ("Invalid Class!");
		}
	}

	void TestComment::failure_scenario(Name name, Text text) throw(invalid_argument) {
		bool errorOcurred = false;
		try {
			Comment testAuxiliar(name,text);
			errorOcurred = true;
		}
		catch(invalid_argument erro) {}
		if(errorOcurred) {
			throw invalid_argument ("Invalid Class!");
		}
	}

	void TestComment::verify() {
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

	TestPost::TestPost() {}

	TestPost::~TestPost() {}

	void TestPost::success_scenario(Name name, Text text) throw(invalid_argument) {
		try {
			Post testAuxiliar(name,text);
			if(name != testAuxiliar.get_author() or text != testAuxiliar.get_content()) {
				throw invalid_argument("Invalid Class!");
			}
			Comment testAuxiliar2(name,text);
			try {
				testAuxiliar.add_comment(testAuxiliar2);
			}
			catch(invalid_argument erro) {
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(invalid_argument erro) {
			throw invalid_argument ("Invalid Class!");
		}
	}

	void TestPost::failure_scenario(Name name, Text text) throw(invalid_argument) {
		bool errorOcurred = false;
		try {
			Post testAuxiliar(name,text);
			errorOcurred = true;
		}
		catch(invalid_argument erro) {}
		if(errorOcurred) {
			throw invalid_argument ("Invalid Class!");
		}
	}

	void TestPost::failure_scenario2(Name name, Text text) throw(invalid_argument) {
		bool errorOcurred = false;
		Post testAuxiliar(name, text);
		try {
			Comment testAuxiliar2(name, text);
			// Loop trying to add more than 5 comments, exception expected
			for(int i = 0; i < 6; i++) {
				testAuxiliar.add_comment(testAuxiliar2);
			}
			errorOcurred = true;
		}
		catch(invalid_argument erro) {}

		try {
			Comment testAuxiliar2(name,text);
			testAuxiliar.disallow_comments();
			testAuxiliar.add_comment(testAuxiliar2);
			errorOcurred = true;
		}
		catch(invalid_argument erro) {}
		if(errorOcurred) {
			throw invalid_argument ("Invalid Class!");
		}
	}

	void TestPost::verify() {
		Name correct_name, incorrect_name;
		Text correct_text, incorrect_text;
		correct_name.set("Batata de bermuda");
		correct_text.set("Queria uma calca muito chique pra minha batata");
		success_scenario(correct_name,correct_text);
		failure_scenario(incorrect_name,incorrect_text);
		failure_scenario2(correct_name,correct_text);
	}

// ------------------------------------------------
// Method Implementation of Class TestBlog
// ------------------------------------------------

	TestBlog::TestBlog() {}

	TestBlog::~TestBlog() {}

	void TestBlog::success_scenario(Name name, Name blog_name) throw(invalid_argument) {
		Blog testAuxiliar;
		try {
			testAuxiliar.set(name,blog_name);
			if(name != testAuxiliar.get_author() or blog_name != testAuxiliar.get_blog_name())
				throw invalid_argument("Invalid Class!");
				Text text;
				text.set("Teste");
				Post testAuxiliar2(name,text);
			try {
				testAuxiliar.add_post(testAuxiliar2);
			}
			catch(invalid_argument erro) {
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(invalid_argument erro) {
			throw invalid_argument ("Invalid Class!");
		}
	}

	void TestBlog::failure_scenario(Name name, Name blog_name) throw(invalid_argument) {
		bool errorOcurred = false;
		Blog testAuxiliar;
		try {
			testAuxiliar.set(name,blog_name);
			errorOcurred = true;
		}
		catch(invalid_argument erro) {}
		name.set("Batata");
		blog_name.set("Calca chique");
		testAuxiliar.set(name,blog_name);
		Text text;
		text.set("Calca chique");
		Post testAuxiliar2(blog_name,text);
		try {
			testAuxiliar.add_post(testAuxiliar2);
			errorOcurred = true;
		}
		catch(invalid_argument erro) {}
		if(errorOcurred) {
			throw invalid_argument ("Invalid Class!");
		}
	}

	void TestBlog::verify() {
		Name correct_name, incorrect_name;
		Name correct_blog_name, incorrect_blog_name;
		correct_name.set("Batata de bermuda");
		correct_blog_name.set("Queria uma calca");
		success_scenario(correct_name,correct_blog_name);
		failure_scenario(incorrect_name,incorrect_blog_name);
	}
