#include "Bill.h"

// 构造函数
Bill::Bill() {

}

// 含参构造函数
Bill::Bill(long long billBid, string billBelongs, string billInfo, string billSource, double billValue, bool billStatus) {
	this->billBid = billBid;
	this->billBelongs = billBelongs;
	this->billInfo = billInfo;
	this->billSource = billSource;
	this->billValue = billValue;
	this->billStatus = billStatus;
}

// 初始化
void Bill::initVector() {
	billData.clear();

	ifstream ifs;
	ifs.open(BILL_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "读取数据失败！" << endl;
		return;
	}

	Bill b;
	while (ifs >> b.billBid && ifs >> b.billBelongs && ifs >> b.billInfo && ifs >> b.billSource && ifs >> b.billValue && ifs >> b.billStatus) {
		billData.push_back(b);
	}
	ifs.close();
}

// 
void Bill::updateBill() {
	if (this->billData.size() == 0) {
		return;
	}

	ofstream ofs;
	ofs.open(BILL_FILE, ios::out | ios::trunc);
	for (unsigned int i = 0; i < billData.size(); i++) {
		ofs << this->billData[i].billBid << " " << this->billData[i].billBelongs << " "
			<< this->billData[i].billInfo << " " << this->billData[i].billSource<< " "
			<< this->billData[i].billValue << " " << this->billData[i].billStatus << endl;
	}
	ofs.close();
}



