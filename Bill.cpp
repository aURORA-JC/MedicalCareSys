#include "Bill.h"

Bill::Bill() {

}

Bill::Bill(long long billBid, string billBelongs, string billInfo, string billSource, double billValue, bool billStatus) {
	this->billBid = billBid;
	this->billBelongs = billBelongs;
	this->billInfo = billInfo;
	this->billSource = billSource;
	this->billValue = billValue;
	this->billStatus = billStatus;

}

void Bill::initVector() {
	billData.clear();

	ifstream ifs;
	ifs.open(BILL_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "¶ÁÈ¡Êý¾ÝÊ§°Ü£¡" << endl;
		return;
	}

	Bill b;
	while (ifs >> b.billBid && ifs >> b.billBelongs && ifs >> b.billInfo && ifs >> b.billSource && ifs >> b.billValue && ifs >> b.billStatus) {
		billData.push_back(b);
	}
	ifs.close();
}

void Bill::updateBill() {
	if (this->billData.size() == 0) {
		return;
	}

	ofstream ofs;
	ofs.open(BILL_FILE, ios::out | ios::trunc);
	for (int i = 0; i < billData.size(); i++) {
		//ofs << this->billBid << " " << this->billBelongs << " " 
		//	<< this->billInfo << " " << this->billSource<< " " 
		//	<< this->billValue << " " << this->billStatus << endl;
	}
	ofs.close();
}



