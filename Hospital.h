// Hospital.h - MedicalSys for class CPP Programming
// version 0.1.1 rc1 - dev at 2020.06.25 - produce by aurorajc

#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Identity.h"
#include "Bill.h"

class Hospital :public Identity {
public:
	Hospital() {};
	Hospital(long long hospitalHid, string hospitalId, string hospitalName, int hospitalLevel, string hospitalArea);
	virtual void openMenu();
	void addBill();
	void showBill();
	void editBill();
	void deleteBill();
	bool checkRepeat(long long);
	bool checkRights(long long);
	friend class Admin;
	friend void printHospital(Hospital& h);
	vector<long long> rights;
private:
	long long hospitalHid;
	string hospitalId;
	string hospitalName;
	int hospitalLevel;
	string hospitalArea;
};