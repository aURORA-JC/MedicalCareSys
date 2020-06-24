// Hospital.h - MedicalSys for class CPP Programming
// version 0.0.3 - dev at Wan 2020.06.24 - produce by aurorajc

#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Identity.h"
#include "Bill.h"

class Hospital :public Identity {
public:
	Hospital();
	Hospital(long long hospitalHid, string hospitalId, string hospitalName, int hospitalLevel, string hospitalArea);
	virtual void openMenu();
	void addBill();
	void showBill();
	void deleteBill();
	friend class Admin;
	friend void printHospital(Hospital& h);
private:
	long long hospitalHid;
	string hospitalId;
	string hospitalName;
	int hospitalLevel;
	string hospitalArea;
};