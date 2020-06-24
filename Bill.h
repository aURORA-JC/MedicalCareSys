// Bill.h - MedicalSys for class CPP Programming
// version 0.0.3 - dev at Wan 2020.06.24 - produce by aurorajc

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#include "gobalNeed.h"


class Bill {
public:
	Bill();
	Bill(long long billBid, string billBelongs, string billInfo, string billSource, double billValue, bool billStatus);
	void initVector();
	void updateBill();
	friend class User;
	friend class Hospital;
	friend void printBill(Bill& b);
	vector<Bill> billData;
private:
	long long billBid;
	string billBelongs;
	string billInfo;
	string billSource;
	double billValue;
	bool billStatus;
};
