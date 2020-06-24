// User.h - MedicalSys for class CPP Programming
// version 0.0.3 - dev at Wan 2020.06.24 - produce by aurorajc

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
	void initVector();
	void updateUser();
	friend class Admin;
	friend void printUser(User&);
	vector<User> usrData;
private:
	long long usrUid;
	string usrMedicalCardNum;
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