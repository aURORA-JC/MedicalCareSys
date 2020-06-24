// Identity.h - MedicalSys for class CPP Programming
// version 0.0.3 - dev at Wan 2020.06.24 - produce by aurorajc

#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "gobalNeed.h"
using namespace std;

class Identity {
public:
	virtual void openMenu() = 0;
protected:
	string username;
	string passwd;
};