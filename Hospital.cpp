// Hospital.cpp - MedicalSys for class CPP Programming
// version 0.0.3 - dev at Wan 2020.06.24 - produce by aurorajc

#include "Hospital.h"

// �˵���ʾ��ʽ
void printBill(Bill& b);

// ���캯��
Hospital::Hospital() {

}

// ���ι��캯��
Hospital::Hospital(long long hospitalHid, string hospitalId, string hospitalName, int hospitalLevel, string hospitalArea) {
	this->hospitalHid = hospitalHid;
	this->hospitalId = hospitalId;
	this->hospitalName = hospitalName;
	this->hospitalLevel = hospitalLevel;
	this->hospitalArea = hospitalArea;
}

// ����ҽԺ�˵�
void Hospital::openMenu() {
	cout << "��ӭ����������ҽԺ��" << this->hospitalName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|             1.����˵�  2.�г��˵�  3.ɾ���˵�         |\n"
		<< "|                                                        |\n"
		<< "|                          0.ע��                        |\n"
		<< "|                                                        |\n"
		<< " --------------------------------------------------------\n"
		<< "��ѡ��";
}

// ����˵�
void Hospital::addBill() {
	ofstream ofs;
	ofs.open(BILL_FILE, ios::out | ios::app);
	
	int addNum;
	cout << "����˵�������" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i + 1 << " �����˵�" << endl;

		long long w2billBid;
		cout << "�����˵�ID��" << endl;
		cin >> w2billBid;

		string w2billBelongs;
		cout << "����Ӧ�ɷ���ҽ�����ţ�" << endl;
		cin >> w2billBelongs;

		string w2billInfo;
		cout << "�����˵���Ϣ��" << endl;
		cin >> w2billInfo;

		double w2billValue;
		cout << "�����˵����" << endl;
		cin >> w2billValue;

		cout << "����¼���˵���Ϣ..." << endl;
		ofs << w2billBid << " " << w2billBelongs << " " << w2billInfo << " " << this->hospitalId << " " << w2billValue << " " << 1 << endl;
		cout << "�˵���Ϣ¼��ɹ���" << endl;
		
		system("pause");
	}

	system("cls");
	ofs.close();
}

// �г��˵�
void Hospital::showBill() {
	Bill a;
	vector<Bill> list;
	list.clear();
	a.initVector();
	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billSource == this->hospitalId) {
			list.push_back(*it);
		}
	}
	
	if (list.empty()) {
		cout << "��" << endl;
	}
	else {
		for_each(list.begin(), list.end(), printBill);
	}
	
	system("pause");
	system("cls");
}

// ɾ���˵�
void Hospital::deleteBill() {
	cout << "��ǰ�˵����£�" << endl;
	Bill a;
	vector<Bill> list;
	list.clear();
	a.initVector();

	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billSource == this->hospitalId) {
			list.push_back(*it);
		}
	}

	if (list.empty()) {
		cout << "���˵���ɾ����" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for_each(list.begin(), list.end(), printBill);
	
		long long id;
		cout << endl << "����Ŀ���˵�Bid:";
		cin >> id;
		cout << "����ɾ��BidΪ" << id << " ���˵���";
		system("pause");

		cout << "����ɾ��..." << endl;
		list.clear();
		for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
			if (id == it->billBid) {
				continue;
			}
			else {
				list.push_back(*it);
			}	
		}
		a.billData.clear();
		a.billData.assign(list.begin(), list.end());
		a.updateBill();
		cout << "ɾ���ɹ���" << endl;
		system("pause");
		system("cls");
		return;
	}
}