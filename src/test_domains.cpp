#include "../hdr/test_domains.hpp"
#include "../hdr/domains.hpp"
#include <bits/stdc++.h>
using namespace std;

void TestName::verify(){
	success_scenario(correct);
	failure_scenario(incorrect);
}

TestName::TestName() {}

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
		catch(invalid_argument erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestName::failure_scenario(string value){
	Name testAuxiliar;
	bool daerro = false;
	try{
		testAuxiliar.set(value);
		daerro = true;
	}
	catch(invalid_argument erro){
		try{
			testAuxiliar.get();
			daerro = true;
		}
		catch(invalid_argument erro){}
	}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
}

void TestPassword::verify(){
	success_scenario(correct);
	failure_scenario(incorrect);
}

TestPassword::TestPassword() {}

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
		catch(invalid_argument erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestPassword::failure_scenario(string value){
	Password testAuxiliar;
	bool daerro = false;
	try{
		testAuxiliar.set(value);
		daerro = true;
	}
	catch(invalid_argument erro){
		try{
			testAuxiliar.get();
			daerro = true;
		}
		catch(invalid_argument erro){}
	}
	if(daerro)
			throw invalid_argument ("Invalid Class!");

}


void TestEmail::verify(){
	success_scenario(correct);
	failure_scenario(incorrect);
}

TestEmail::TestEmail() {}

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
		catch(invalid_argument erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestEmail::failure_scenario(string value){
	Email testAuxiliar;
	bool daerro = false;
	try{
		testAuxiliar.set(value);
		daerro = true;
	}
	catch(invalid_argument erro){
		try{
			testAuxiliar.get();
			daerro = true;
		}
		catch(invalid_argument erro){}
	}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
}


void TestText::verify(){
	success_scenario(correct);
	failure_scenario(incorrect);
}

TestText::TestText() {}

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
		catch(invalid_argument erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestText::failure_scenario(string value){
	Text testAuxiliar;
	bool daerro = false;
	try{
		testAuxiliar.set(value);
		daerro = true;
	}
	catch(invalid_argument erro){
		try{
			testAuxiliar.get();
			daerro = true;
		}
		catch(invalid_argument erro){}
	}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
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
		catch(invalid_argument erro){
			throw invalid_argument ("Invalid Class!");
		}
	}
	catch(invalid_argument erro){
		throw invalid_argument ("Invalid Class!");
	}
}

void TestAvaliation::failure_scenario(int value){
	Avaliation testAuxiliar;
	bool daerro = false;
	try{
		testAuxiliar.set(value);
		daerro = true;
	}
	catch(invalid_argument erro){
		try{
			testAuxiliar.get();
			daerro = true;
		}
		catch(invalid_argument erro){}
	}
	if(daerro)
			throw invalid_argument ("Invalid Class!");
}

