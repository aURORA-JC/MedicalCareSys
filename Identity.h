#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "gobalNeed.h"
#include "Bill.h"
using namespace std;

class Identity {
public:
	virtual void openMenu() = 0;
protected:
	string username;
	string passwd;
};