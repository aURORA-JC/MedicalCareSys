#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"


class Hospital :public Identity {
public:
	Hospital();
	Hospital(string hospitalId, string hospitalName, int hospitalLevel, string hospitalArea);
	virtual void openMenu();
	void addBill();
	void deleteBill();
	void showBill();
	void searchBill();
	friend class Admin;
	friend void printHospital(Hospital& h);
private:
	string hospitalId;
	string hospitalName;
	int hospitalLevel;
	string hospitalArea;
};