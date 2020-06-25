// Hospital.cpp - MedicalSys for class CPP Programming
// version 0.1.1 rc1 - dev at 2020.06.25 - produce by aurorajc

#include "Hospital.h"

// ��ʾ��ʽ�趨����
void printBill(Bill& b);

// ���ι��캯��
Hospital::Hospital(long long hospitalHid, string hospitalId, string hospitalName, int hospitalLevel, string hospitalArea) {
	this->hospitalHid = hospitalHid;
	this->hospitalId = hospitalId;
	this->hospitalName = hospitalName;
	this->hospitalLevel = hospitalLevel;
	this->hospitalArea = hospitalArea;
}

// ����ҽԺ�˵�����
void Hospital::openMenu() {
	cout << "��ӭ����������ҽԺ��" << this->hospitalName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|             1.����˵�  2.�г��˵�  3.�޸��˵�         |\n"
		<< "|                                                        |\n"
		<< "|             4.ɾ���˵�             0.ע��              |\n"
		<< "|                                                        |\n"
		<< " --------------------------------------------------------\n"
		<< "��ѡ��";
}

// ����˵�����
void Hospital::addBill() {
	ofstream ofs;
	ofs.open(BILL_FILE, ios::out | ios::app);
	
	int addNum;
	cout << "����˵�������" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i + 1 << " �����˵�" << endl;

		long long w2billBid;
		cout << "�����˵���ţ�" << endl;
		cin >> w2billBid;

		if (checkRepeat(w2billBid)) {
			cout << "�˵�����Ѵ��ڣ�" << endl;
			continue;
		}

		string w2billBelongs;
		cout << "����Ӧ�ɷ���ҽ�����ţ�" << endl;
		cin >> w2billBelongs;

		string w2billInfo;
		cout << "�����˵���Ϣ��" << endl;
		cin >> w2billInfo;

		double w2billValue;
		cout << "�����˵���" << endl;
		cin >> w2billValue;

		cout << "����¼���˵���Ϣ..." << endl;
		ofs << w2billBid << " " << w2billBelongs << " " << w2billInfo << " " << this->hospitalId << " " << w2billValue << " " << "δ֧��" << endl;
		cout << "�˵���Ϣ¼��ɹ���" << endl;
		
		system("pause");
	}

	system("cls");
	ofs.close();
}

// �г��˵�����
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

// �༭�˵�����
void Hospital::editBill() {
	cout << "��ǰ�˵����£�" << endl;
	Bill a;
	vector<Bill> list;
	list.clear();
	rights.clear();
	a.initVector();

	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billSource == this->hospitalId) {
			list.push_back(*it);
			this->rights.push_back(it->billBid);
		}
	}

	if (list.empty()) {
		cout << "���˵����޸ģ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for_each(list.begin(), list.end(), printBill);

		long long id;
		cout << endl << "����Ŀ���˵���Bid:";
		cin >> id;

		if (!checkRights(id)) {
			cout << "��ǰBID���ɷ��ʣ�" << endl;
			system("pause");
			system("cls");
			return;
		}

		int choice;
		cout << "ѡ���޸����ݣ�" << endl
			<< "  1.����\n"
			<< "  2.���\n"
			<< "  3.֧��״̬" << endl;
		cin >> choice;

		if (choice == 1) {
			cout << "�������飺" << endl;
			for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
				if (id == it->billBid) {
					cin >> it->billInfo;
				}
			}
		}
		else if (choice == 2) {
			cout << "�����" << endl << "��";
			for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
				if (id == it->billBid) {
					cin >> it->billValue;
				}
			}
		}
		else if (choice == 3) {
			cout << "����֧��״̬����/�񣩣�" << endl;
			for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
				if (id == it->billBid) {
					string status;
					cin >> status;
					if (status == "��") {
						it->billStatus = "��֧��";
					}
					else {
						it->billStatus = "δ֧��";
					}
				}
			}
		}
		else {
			cout << "�������" << endl;
			system("pause");
			system("cls");
			return;
		}

		a.updateBill();
		cout << "�޸ĳɹ���" << endl;

		system("pause");
		system("cls");
	}
}

// ɾ���˵�����
void Hospital::deleteBill() {
	cout << "��ǰ�˵����£�" << endl;
	Bill a;
	vector<Bill> list;
	list.clear();
	rights.clear();
	a.initVector();

	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billSource == this->hospitalId) {
			list.push_back(*it);
			rights.push_back(it->billBid);
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
		cout << endl << "����Ŀ���˵���Bid:";
		cin >> id;

		if (!checkRights(id)) {
			cout << "��ǰBID���ɷ��ʣ�" << endl;
			system("pause");
			system("cls");
			return;
		}

		cout << "����ɾ��BidΪ" << id << " ���˵����Ƿ������(��/��)";
		string choice;
		cin >> choice;
		if (choice != "��") {
			cout << "������ȡ����" << endl;
			system("pause");
			system("cls");
			return;
		}

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

// �ظ���麯��
bool Hospital::checkRepeat(long long id) {
	Bill a;
	a.initVector();
	bool repeat = false;
	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (id == it->billBid)
			repeat = true;
	}

	return repeat;
}

// Ȩ�޼�麯��
bool Hospital::checkRights(long long id) {
	bool right = false;
	for (vector<long long>::iterator it = rights.begin(); it != rights.end(); it++ ) {
		if (id == *it) {
			right = true;
		}
	}
	return right;
}
