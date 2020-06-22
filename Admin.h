#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Identity.h"
#include "User.h"
#include "Hospital.h"

class Admin :public Identity {
public:
	Admin();
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
	void deleteUser();
	void deleteHospital();
	void deleteBill();
	void deleteAll();
	void initVector();
	bool checkRepeat(string, int);
	vector<User> user;
	vector<Hospital> hospital;
private:
	string adminId;
	string adminName;
	string adminArea;
};