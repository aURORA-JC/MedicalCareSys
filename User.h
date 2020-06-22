#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include "Hospital.h"

class User :public Identity {
public:
	User();
	User(string userId, string userName, int userAge, string idCardNum, string userNation, string idClass, bool inHospital, double cardBalance, string MedicalCareBelongsArea);
	virtual void openMenu();
	void addCredit();
	void showBill();
	void searchBill();
	void payBill();
	friend class Admin;
	friend void printUser(User&);
private:
	string userId;
	string userName;
	int userAge;
	// string userSex;
	string idCardNum;
	string userNation;
	string idClass;
	bool inHsopital;
	double cardBanlance;
	string MedialCareBelongsArea;
};