#include "test_domains.hpp"
#include "domains.hpp"
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------
// Method Implementation of Class TestDomain
// ------------------------------------------------

TestDomain::TestDomain() {}

TestDomain::~TestDomain() {}

void TestDomain::success_scenario(string value,Domain &testAuxiliar) throw(invalid_argument) {
	try {
		testAuxiliar.set(value);
		try {
			string testAuxiliar2 = testAuxiliar.get();
			if(testAuxiliar2 != value) {
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
}

void TestDomain::failure_scenario(string value,Domain &testAuxiliar) throw(invalid_argument) {
	bool errorOcurred = false;
	try {
		testAuxiliar.set(value);
		errorOcurred = true;
	}
	catch(invalid_argument erro) {
		try{
			testAuxiliar.get();
			errorOcurred = true;
		}
		catch(invalid_argument erro) {}
	}
	if(errorOcurred) {
		throw invalid_argument ("Invalid Class!");
	}
}

// ------------------------------------------------
// Method Implementation of Class TestName
// ------------------------------------------------

TestName::TestName() {}

TestName::~TestName() {}

void TestName::verify() {
	{
		Name testAuxiliar;
		success_scenario(correct,testAuxiliar);
	}

	Name testAuxiliar;
	failure_scenario(incorrect,testAuxiliar);
}

// ------------------------------------------------
// Method Implementation of Class TestPassword
// ------------------------------------------------

TestPassword::TestPassword() {}

TestPassword::~TestPassword() {}

void TestPassword::verify() {
	{
		Password testAuxiliar;
		success_scenario(correct,testAuxiliar);
	}

	Password testAuxiliar;
	failure_scenario(incorrect,testAuxiliar);
}

// ------------------------------------------------
// Method Implementation of Class TestEmail
// ------------------------------------------------

TestEmail::TestEmail() {}

TestEmail::~TestEmail() {}

void TestEmail::verify() {
	{
		Email testAuxiliar;
		success_scenario(correct,testAuxiliar);
	}

	Email testAuxiliar;
	failure_scenario(incorrect,testAuxiliar);
}

// ------------------------------------------------
// Method Implementation of Class TestText
// ------------------------------------------------

TestText::TestText() {}

TestText::~TestText() {}

void TestText::verify() {
	{
		Text testAuxiliar;
		success_scenario(correct,testAuxiliar);
	}

	Text testAuxiliar;
	failure_scenario(incorrect,testAuxiliar);
}

// ------------------------------------------------
// Method Implementation of Class TestAvaliation
// ------------------------------------------------

TestAvaliation::TestAvaliation() {}

TestAvaliation::~TestAvaliation() {}

void TestAvaliation::success_scenario(int value) throw(invalid_argument) {
	Avaliation testAuxiliar;
	try {
		testAuxiliar.set(value);
		try {
			int testAuxiliar2 = testAuxiliar.get();
			if(testAuxiliar2 != value){
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
}

void TestAvaliation::failure_scenario(int value) throw(invalid_argument) {
	Avaliation testAuxiliar;
	bool errorOcurred = false;
	try {
		testAuxiliar.set(value);
		errorOcurred = true;
	}
	catch(invalid_argument erro) {}
	if(errorOcurred) {
		throw invalid_argument ("Invalid Class!");
	}
}

void TestAvaliation::verify() {
	success_scenario(correct);
	failure_scenario(incorrect);
}
