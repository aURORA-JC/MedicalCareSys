// Bill.cpp - MedicalSys for class CPP Programming
// version 0.1.2 fixed - dev at 2020.06.25 - produce by aurorajc

#include "Bill.h"

// ���ι��캯��
Bill::Bill(long long billBid, string billBelongs, string billInfo, string billSource, double billValue, string billStatus) {
	this->billBid = billBid;
	this->billBelongs = billBelongs;
	this->billInfo = billInfo;
	this->billSource = billSource;
	this->billValue = billValue;
	this->billStatus = billStatus;
}

// ������ʼ������
void Bill::initVector() {
	billData.clear();

	ifstream ifs;
	ifs.open(BILL_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "��ȡ����ʧ�ܣ�" << endl;
		return;
	}

	Bill b;
	while (ifs >> b.billBid && ifs >> b.billBelongs && ifs >> b.billInfo && ifs >> b.billSource && ifs >> b.billValue && ifs >> b.billStatus) {
		billData.push_back(b);
	}
	ifs.close();
}

// �������ݺ���
void Bill::updateBill() {
	if (this->billData.empty()) {
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
