#include "User.h"

void printBill(Bill& b);

User::User() {

}

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

void User::openMenu() {
	cout << "��ӭ�������û���" << this->usrName << endl;
		cout << " --------------------------------------------------------\n"
			<< "|                                                        |\n"
			<< "|             1.������Ϣ  2.����ֵ  3.�г��˵�         |\n"
			<< "|                                                        |\n"
			<< "|             4.�����˵�  5.֧���˵�  0.ע��             |\n"
			<< "|                                                        |\n"
			<< " --------------------------------------------------------\n"
			<< "��ѡ��";
}

void User::showInfo() {
	printUser(*this);
	system("pause");
	system("cls");
}

void User::addCredit() {
	double add;
	cout << "�����ֵ��";
	cin >> add;

	string status;
	cout << "��ǰ���� " << this->usrCardBanlance << endl
		<< "������ֵ���� " << add << " �Ƿ��ֵ������/��";
	cin >> status;
	if (status == "��") {
		this->usrCardBanlance += add;
		cout << "��ֵ�ɹ���" << endl
			<< "��ǰ���� " << this->usrCardBanlance << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "������ȡ����" << endl;
		system("pause");
		system("cls");
	}

}

void User::showBill() {
	Bill a;
	vector<Bill> list;
	list.clear();
	a.initVector();
	for (vector<Bill>::iterator it = a.billData.begin(); it != a.billData.end(); it++) {
		if (it->billSource == this->usrMedicalCardNum) {
			list.push_back(*it);
		}
	}
	for_each(list.begin(), list.end(), printBill);
	system("pause");
	system("cls");
}

void User::payBill() {

}



