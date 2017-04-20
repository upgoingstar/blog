#include "test_domains.hpp"
#include "../hdr/domains.hpp"
#include <bits/stdc++.h>
using namespace std;


Test::Test() {}

Test::~Test() {}

void Test::verify(){
	success_scenario(correct);
	failure_scenario(incorrect);
}

TestName::TestName() {
	correct = "Abc Def";
	incorrect = "A1";
}

TestName::~TestName() {}

void TestName::success_scenario(string value){
	Name testAuxiliar;
	try{
		testAuxiliar.set(value);
		try{
			string testAuxiliar2 = testAuxiliar.get();
			if(testAuxiliar2 != value){
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(string erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(string erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestName::failure_scenario(string value){
	Name testAuxiliar;
	try{
		testAuxiliar.set(value);
		throw invalid_argument ("Invalid Class!");
	}
	catch(string erro){
		try{
			testAuxiliar.get();
			throw invalid_argument ("Invalid Class!");
		}
		catch(string erro){}
	}
}

TestPassword::TestPassword() {
	correct = "abc123";
	incorrect = "ab112";
}

TestPassword::~TestPassword() {}

void TestPassword::success_scenario(string value){
	Password testAuxiliar;
	try{
		testAuxiliar.set(value);
		try{
			string testAuxiliar2 = testAuxiliar.get();
			if(testAuxiliar2 != value){
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(string erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(string erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestPassword::failure_scenario(string value){
	Password testAuxiliar;
	try{
		testAuxiliar.set(value);
		throw invalid_argument ("Invalid Class!");
	}
	catch(string erro){
		try{
			testAuxiliar.get();
			throw invalid_argument ("Invalid Class!");
		}
		catch(string erro){}
	}
}

TestEmail::TestEmail() {
	correct = "a@a.a";
	incorrect = "a1@a.a";
}

TestEmail::~TestEmail() {}

void TestEmail::success_scenario(string value){
	Email testAuxiliar;
	try{
		testAuxiliar.set(value);
		try{
			string testAuxiliar2 = testAuxiliar.get();
			if(testAuxiliar2 != value){
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(string erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(string erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestEmail::failure_scenario(string value){
	Email testAuxiliar;
	try{
		testAuxiliar.set(value);
		throw invalid_argument ("Invalid Class!");
	}
	catch(string erro){
		try{
			testAuxiliar.get();
			throw invalid_argument ("Invalid Class!");
		}
		catch(string erro){}
	}
}

TestText::TestText() {
	correct = "Valid text with less than 50 characters!";
	incorrect = "Text too much looooooooooooooooooooooooooooooooooooooooooooooooooooooooooong";
}

TestText::~TestText() {}

void TestText::success_scenario(string value){
	Text testAuxiliar;
	try{
		testAuxiliar.set(value);
		try{
			string testAuxiliar2 = testAuxiliar.get();
			if(testAuxiliar2 != value){
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(string erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(string erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestText::failure_scenario(string value){
	Text testAuxiliar;
	try{
		testAuxiliar.set(value);
		throw invalid_argument ("Invalid Class!");
	}
	catch(string erro){
		try{
			testAuxiliar.get();
			throw invalid_argument ("Invalid Class!");
		}
		catch(string erro){}
	}
}


TestAvaliation::TestAvaliation() {}

TestAvaliation::~TestAvaliation() {}

void TestAvaliation::verify(){
	success_scenario(correct);
	failure_scenario(incorrect);
}

void TestAvaliation::success_scenario(int value){
	Avaliation testAuxiliar;
	try{
		testAuxiliar.set(value);
		try{
			int testAuxiliar2 = testAuxiliar.get();
			if(testAuxiliar2 != value){
				throw invalid_argument ("Invalid Class!");
			}
		}
		catch(string erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(string erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestAvaliation::failure_scenario(int value){
	Avaliation testAuxiliar;
	try{
		testAuxiliar.set(value);
		throw invalid_argument ("Invalid Class!");
	}
	catch(string erro){
		try{
			testAuxiliar.get();
			throw invalid_argument ("Invalid Class!");
		}
		catch(string erro){}
	}
}