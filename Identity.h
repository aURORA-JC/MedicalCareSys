// Identity.h - MedicalSys for class CPP Programming
// version 0.1.2 fixed - dev at 2020.06.25 - produce by aurorajc

#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "gobalNeed.h"
using namespace std;

class Identity {
public:
	virtual void openMenu() = 0;
protected:
	string username;
	string passwd;
};