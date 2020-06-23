#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include "Hospital.h"

class User :public Identity {
public:
	User();
	User(long long usrUid, string usrMedicalCardNum, string usrName, int usrAge, string usrSex, string usrIdCardNum, string usrNation, string usrIdClass, bool usrInHospital, double cardBalance, string MedicalCareBelongsArea);
	virtual void openMenu();
	void showInfo();
	void addCredit();
	void showBill();
	void payBill();
	friend class Admin;
	friend void printUser(User&);
private:
	string usrMedicalCardNum;
	long long usrUid;
	string usrName;
	int usrAge;
	string usrSex;
	string usrIdCardNum;
	string usrNation;
	string usrIdClass;
	bool usrInHospital;
	double usrCardBanlance;
	string usrCareArea;
};