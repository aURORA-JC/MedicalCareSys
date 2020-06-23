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
	void showUser();
	void showHospital();
	void searchUser();
	void searchHospital();
	void deleteUser();
	void deleteHospital();
	void deleteAll();
	void initVector();
	bool checkRepeat(string, int);
	vector<User> user;
	vector<Hospital> hospital;
	vector<User> usrList;
	vector<Hospital> hospitalList;
private:
	string adminId;
	string adminName;
	string adminArea;
};