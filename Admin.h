// Admin.h - MedicalSys for class CPP Programming
// version 0.1.1 rc1 - dev at 2020.06.25 - produce by aurorajc

#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "gobalNeed.h"
#include "Identity.h"
#include "User.h"
#include "Hospital.h"
#include "Bill.h"

class Admin :public Identity {
public:
	Admin() {};
	Admin(string adminId, string adminName, string adminArea);
	virtual void openMenu();
	void addUser();
	void addHospital();
	void addBill();
	void showUser();
	void showHospital();
	void showBill();
	void searchUser();
	void searchHospital();
	void searchBill();
	void editUser();
	void editHospital();
	void deleteUser();
	void deleteHospital();
	void deleteBill();
	void deleteAll();
	void initVector();
	bool checkRepeat(long long, string, int, int);
	void updateData(int);
	vector<User> user;
	vector<Hospital> hospital;
	vector<Bill> bill;
	vector<User> usrList;
	vector<Hospital> hospitalList;
	vector<Bill> billList;
private:
	string adminId;
	string adminName;
	string adminArea;
};