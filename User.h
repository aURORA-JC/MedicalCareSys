// User.h - MedicalSys for class CPP Programming
// version 0.1.1 rc1 - dev at 2020.06.25 - produce by aurorajc

#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include "Hospital.h"

class User :public Identity {
public:
	User() {};
	User(long long usrUid, string usrMedicalCardNum, string usrName, int usrAge, string usrSex, string usrIdCardNum, string usrNation, string usrIdClass, string usrInHospital, double cardBalance, string MedicalCareBelongsArea);
	virtual void openMenu();
	void showInfo();
	void addCredit();
	void showBill();
	void payBill();
	void initVector();
	void updateUser();
	bool checkRights(long long);
	friend class Admin;
	friend void printUser(User&);
	vector<User> usrData;
	vector<long long> rights;
private:
	long long usrUid;
	string usrMedicalCardNum;
	string usrName;
	int usrAge;
	string usrSex;
	string usrIdCardNum;
	string usrNation;
	string usrIdClass;
	string usrInHospital;
	double usrCardBanlance;
	string usrCareArea;
};