// User.h - MedicalSys for class CPP Programming
// version 0.0.3 - dev at Wan 2020.06.24 - produce by aurorajc

#include "User.h"

using namespace std;

void printUser(User& u);
void printBill(Bill& b);

// ���캯��
User::User() {

}

// ���ι��캯��
User::User(long long usrUid, string usrMedicalCardNum, string usrName, int usrAge, string usrSex, string usrIdCardNum, string usrNation, string usrIdClass, bool usrInHospital, double usrCardBalance, string usrCareArea) {
	this->usrMedicalCardNum = usrMedicalCardNum;
	this->usrUid = usrUid;
	this->usrName = usrName;
	this->usrAge = usrAge;
	this->usrSex = usrSex;
	this->usrIdCardNum = usrIdCardNum;
	this->usrNation = usrNation;
	this->usrIdClass = usrIdClass;
	this->usrInHospital = usrInHospital;
	this->usrCardBanlance = usrCardBalance;
	this->usrCareArea = usrCareArea;
}

// �û��˵�
void User::openMenu() {
	cout << "��ӭ�������û���" << this->usrName << endl;
		cout << " --------------------------------------------------------\n"
			<< "|                                                        |\n"
			<< "|             1.������Ϣ  2.����ֵ  3.�г��˵�         |\n"
			<< "|                                                        |\n"
			<< "|             4.֧���˵�              0.ע��             |\n"
			<< "|                                                        |\n"
			<< " --------------------------------------------------------\n"
			<< "��ѡ��";
}

// ��ʾ��Ϣ
void User::showInfo() {
	User u;
	vector<User> list;
	list.clear();
	u.initVector();

	for (vector<User>::iterator it = u.usrData.begin(); it != u.usrData.end(); it++) {
		if (this->usrMedicalCardNum == it->usrMedicalCardNum) {
			list.push_back(*it);
		}
	}

	for_each(list.begin(), list.end(), printUser);

	system("pause");
	system("cls");
}

// ��ֵ
void User::addCredit() {
	User u;
	vector<User> list;
	list.clear();
	u.initVector();
	double add;
	cout << "�����ֵ��";
	cin >> add;

	string status;
	cout << "��ǰ���� " << setiosflags(ios::fixed) << setprecision(2) << this->usrCardBanlance << endl
		<< "������ֵ���� " << add << " �Ƿ��ֵ������/��" << resetiosflags(ios::fixed);
	cin >> status;
	if (status == "��") {
		for (vector<User>::iterator it = u.usrData.begin(); it != u.usrData.end(); it++) {
			if (this->usrMedicalCardNum == it->usrMedicalCardNum) {
				it->usrCardBanlance += add;
			}
		}

		u.updateUser();
		cout << "��ֵ�ɹ���" << endl
			<< "��ǰ���� " << setiosflags(ios::fixed) << setprecision(2) << this->usrCardBanlance + add << resetiosflags(ios::fixed) << endl;

		system("pause");
		system("cls");
	}
	else {
		cout << "������ȡ����" << endl;
		system("pause");
		system("cls");
	}

}

// ��ʾ�˵�
void User::showBill() {
	Bill a;
	vector<Bill> list;
	list.clear();
	a.initVector();

	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billBelongs == this->usrMedicalCardNum) {
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

// ֧���˵�
void User::payBill() {
	cout << "��ǰ��֧���˵����£�" << endl;
	Bill a;
	User u;
	vector<Bill> list;
	list.clear();
	a.initVector();
	u.initVector();

	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billBelongs == this->usrMedicalCardNum && it->billStatus == 1) {
			list.push_back(*it);
		}
	}

	if (list.empty()) {
		cout << "���˵���֧����" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for_each(list.begin(), list.end(), printBill);

		long long id;
		cout << endl << "����Ŀ���˵�Bid:";
		cin >> id;
		cout << "����֧��BidΪ" << id << " ���˵���";
		system("pause");

		cout << "����֧��..." << endl;
		double value = 0;

		for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
			if (id == it->billBid) {
				it->billStatus = 0;
				value = it->billValue;
			}
		}

		for (vector<User>::iterator it = u.usrData.begin(); it != u.usrData.end(); it++) {
			if (this->usrMedicalCardNum == it->usrMedicalCardNum) {
				it->usrCardBanlance -= value;
			}
		}

		a.updateBill();
		u.updateUser();
		cout << "֧���ɹ���" << endl;
		system("pause");
		system("cls");
		return;
	}

	system("pause");
	system("cls");
}

// ��ʼ��
void User::initVector() {
	usrData.clear();

	ifstream ifs;
	ifs.open(USER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "��ȡ����ʧ�ܣ�" << endl;
		return;
	}

	User u;
	while (ifs >> u.usrUid && ifs >> u.username && ifs >> u.passwd && ifs >> u.usrMedicalCardNum && ifs >> u.usrName && ifs >> u.usrAge && ifs >> u.usrSex && ifs >> u.usrIdCardNum && ifs >> u.usrNation && ifs >> u.usrIdClass && ifs >> u.usrInHospital && ifs >> u.usrCardBanlance && ifs >> u.usrCareArea) {
		usrData.push_back(u);
	}
	ifs.close();
}

// ����
void User::updateUser(){
	if (this->usrData.size() == 0) {
		return;
	}

	ofstream ofs;
	ofs.open(USER_FILE, ios::out | ios::trunc);
	for (unsigned int i = 0; i < usrData.size(); i++) {
		ofs << this->usrData[i].usrUid << " " << this->usrData[i].username << " "
			<< this->usrData[i].passwd << " " << this->usrData[i].usrMedicalCardNum << " " << this->usrData[i].usrName << " "
			<< this->usrData[i].usrAge << " " << this->usrData[i].usrSex << " "
			<< this->usrData[i].usrIdCardNum << " " << this->usrData[i].usrNation << " "
			<< this->usrData[i].usrIdClass << " " << this->usrData[i].usrInHospital << " "
			<< this->usrData[i].usrCardBanlance << " " << this->usrData[i].usrCareArea << endl;
	}
	ofs.close();
}

