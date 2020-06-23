#include "Admin.h"

// ��ʾ��ʽ�趨
void printUser(User& u);
void printHospital(Hospital& h);
void printBill(Bill& b);

// ���캯��
Admin::Admin() {

}

// ���ι��캯��
Admin::Admin(string adminId, string adminName, string adminArea) {
	this->adminId = adminId;
	this->adminName = adminName;
	this->adminArea = adminArea;

	// ��ʼ���ڴ�
	this->initVector();
}

// ����Ա�˵�
void Admin::openMenu() {
	cout << "��ӭ����������Ա��" << this->adminName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|            1.����û�         2.��Ӷ���ҽԺ           |\n"
		<< "|                                                        |\n"
		<< "|            3.�г��û�         4.�г�����ҽԺ           |\n"
		<< "|                                                        |\n"
		<< "|            5.�����û�         6.��������ҽԺ           |\n"
		<< "|                                                        |\n"
		<< "|            7.ɾ���û�         8.ɾ������ҽԺ           |\n"
		<< "|                                                        |\n"
		<< "|            9.���ȫ������     0.ע��                   |\n"
		<< "|                                                        |\n"
		<< " --------------------------------------------------------\n"
		<< "��ѡ��";
}

// ����û�
void Admin::addUser() {
	ofstream ofs;
	ofs.open(USER_FILE,ios::out | ios::app);
	
	int addNum;
	cout << "����û�������" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i+1 << " �����û�" << endl;

		long long w2usrUid;
		cout << "�����û���ţ�" << endl;
		cin >> w2usrUid;

		string w2usrMedicalCardNum;
		cout << "����ҽ�����ţ�" << endl;
		cin >> w2usrMedicalCardNum;

		if (checkRepeat(w2usrMedicalCardNum, 1)) {
			cout << "ҽ�������Ѵ��ڣ�" << endl;
			continue;
		}

		string w2sysName;
		cout << "����ҽ��ϵͳ�û�����" << endl;
		cin >> w2sysName;

		string w2sysPassword;
		cout << "����ҽ��ϵͳ���룺" << endl;
		cin >> w2sysPassword;

		string w2usrName;
		cout << "�����û�������" << endl;
		cin >> w2usrName;

		int w2usrAge;
		cout << "�����û����䣺" << endl;
		cin >> w2usrAge;

		string w2usrSex;
		cout << "�����û��Ա�" << endl;
		cin >> w2usrSex;

		string w2usrIdCardNum;
		cout << "�����û�֤���ţ�" << endl;
		cin >> w2usrIdCardNum;

		string w2usrNation;
		cout << "�����û����壺" << endl;
		cin >> w2usrNation;

		string w2usrIdClass;
		cout << "�����û����" << endl;
		cin >> w2usrIdClass;

		bool w2usrInHospital;
		string status;
		cout << "�û���ǰ�Ƿ�סԺ���ǡ��񣩣�" << endl;
		cin >> status;
		if (status == "��") {
			w2usrInHospital = 0;
		}
		else {
			w2usrInHospital = 1;
		}

		double w2usrCardBalance = 0;
		cout << "����ҽ�������" << endl;
		cin >> w2usrCardBalance;

		string w2usrCareArea;
		cout << "����ҽ��������" << endl;
		cin >> w2usrCareArea;

		cout << "��Ϣ¼����..." << endl;
		ofs << w2usrUid << " " << w2sysName << " " << w2sysPassword << " " << w2usrMedicalCardNum << " "<< w2usrName << " " << w2usrAge << " " << w2usrSex << " " << w2usrIdCardNum << " " << w2usrNation << " " << w2usrIdClass << " " << w2usrInHospital << " " << w2usrCardBalance << " " << w2usrCareArea << endl;
		cout << "¼��ɹ���" << endl;

		system("pause");
		this->initVector();
	}

	system("cls");
	ofs.close();
}

// ��Ӷ���ҽԺ
void Admin::addHospital() {
	ofstream ofs;
	ofs.open(HOSPITAL_FILE, ios::out | ios::app);

	int addNum;
	cout << "��Ӷ���ҽԺ������" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i + 1 << " ��������ҽԺ" << endl;

		long long w2hospitalHid;
		cout << "����ҽԺ��ţ�" << endl;
		cin >> w2hospitalHid;
		
		string w2hospitalId;
		cout << "���붨��ҽԺ�����ţ�" << endl;
		cin >> w2hospitalId;

		if (checkRepeat(w2hospitalId, 1)) {
			cout << "����ҽԺ�������Ѵ��ڣ�" << endl;
			continue;
		}

		string w2hospitalUsrName;
		cout << "����ҽ��ϵͳ�û�����" << endl;
		cin >> w2hospitalUsrName;

		string w2hospitalPasswd;
		cout << "����ҽ��ϵͳ���룺" << endl;
		cin >> w2hospitalPasswd;

		string w2hospitalName;
		cout << "����ҽԺ���ƣ�" << endl;
		cin >> w2hospitalName;

		int w2hospiatlLevel;
		cout << "����ҽԺ�ȼ���" << endl;
		cin >> w2hospiatlLevel;

		string w2hosptialArea;
		cout << "����ҽԺ����������" << endl;
		cin >> w2hosptialArea;

		cout << "��Ϣ¼����..." << endl;
		ofs << w2hospitalHid << " " << w2hospitalUsrName << " " << w2hospitalPasswd << " " << w2hospitalId << " " << w2hospitalName << " " << w2hospiatlLevel << " " << w2hosptialArea << endl;
		cout << "¼��ɹ���" << endl;
		
		system("pause");
		this->initVector();
	}

	system("cls");
	ofs.close();
}

// ��ʾ�����û���Ϣ
void Admin::showUser() {
	cout << "�����û���Ϣ���£�" << endl;
	for_each(user.begin(), user.end(), printUser);
	system("pause");
	system("cls");
}

// ��ʾ���ж���ҽԺ��Ϣ
void Admin::showHospital() {
	cout << "���ж���ҽԺ��Ϣ���£�" << endl;
	for_each(hospital.begin(), hospital.end(), printHospital);
	system("pause");
	system("cls");
}

// �����û�
void Admin::searchUser() {
	int choice;
	
	usrList.clear();
	cout << "ѡ���������ݣ�" << endl
		<< "  1.ҽ������\n"
		<< "  2.����\n"
		<< "  3.֤����" << endl
		<< "�����룺";
	cin >> choice;
	if (choice == 1) {
		string id;
		cout << "����ҽ�����ţ�";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrMedicalCardNum)
				usrList.push_back(*it);
		}
	}
	else if (choice == 2) {
		string id;
		cout << "����������";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrName)
				usrList.push_back(*it);
		}
	}
	else if (choice == 3) {
		string id;
		cout << "����֤���ţ�";
		cin >> id;
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrIdCardNum)
				usrList.push_back(*it);
		}
	}
	else {
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����������£�" << endl;
	if (usrList.size() != 0) {
		for_each(usrList.begin(), usrList.end(), printUser);
	}
	else {
		cout << "��" << endl;
	}

	system("pause");
	system("cls");
}

// ��������ҽԺ
void Admin::searchHospital() {
	int choice;
	
	hospitalList.clear();
	cout << "ѡ���������ݣ�" << endl
		<< "  1.������\n"
		<< "  2.����" << endl
		<< "�����룺";
	cin >> choice;
	if (choice == 1) {
		string id;
		cout << "��������ţ�";
		cin >> id;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalId)
				hospitalList.push_back(*it);
		}
	}
	else if (choice == 2) {
		string id;
		cout << "����ҽԺ����";
		cin >> id;
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalName)
				hospitalList.push_back(*it);
		}
	}
	else {
		cout << "�������" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����������£�" << endl;
	if (hospitalList.size() != 0) {
		for_each(hospitalList.begin(), hospitalList.end(), printHospital);
	}
	else {
		cout << "��" << endl;
	}

	system("pause");
	system("cls");
}

// ɾ���û���Ϣ
void Admin::deleteUser() {
	this->searchUser();


	this->initVector();
}

// ɾ��ҽԺ��Ϣ
void Admin::deleteHospital() {
	this->searchHospital();


	this->initVector();
}

// �����������
void Admin::deleteAll() {
	cout << "���棡����׼������������ݣ��˲��������棡" << endl;

	string choice;
	cout << "�Ƿ���������������롮�ǡ�" << endl;
	cin >> choice;

	if (choice == "��") {
		ofstream ofs;
		ofs.open(USER_FILE, ios::trunc);
		ofs.close();

		ofs.open(HOSPITAL_FILE, ios::trunc);
		ofs.close();

		ofs.open(BILL_FILE, ios::trunc);
		ofs.close();

		cout << "����ɹ���" << endl;
		
		this->initVector();
		system("pause");
		system("cls");
	}
	else {
		cout << "������ȡ����" << endl;
		system("pause");
		system("cls");
		return;
	}
}

// ��ʼ����������
void Admin::initVector() {
	user.clear();
	hospital.clear();

	ifstream ifs;
	ifs.open(USER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "��ȡ����ʧ�ܣ�" << endl;
		return;
	}

	User u;
	while (ifs >> u.usrUid && ifs >> u.username && ifs >> u.passwd && ifs >> u.usrMedicalCardNum && ifs >> u.usrName && ifs >> u.usrAge && ifs >> u.usrSex && ifs >> u.usrIdCardNum && ifs >> u.usrNation && ifs >> u.usrIdClass && ifs >> u.usrInHospital && ifs >> u.usrCardBanlance && ifs >> u.usrCareArea) {
		user.push_back(u);
	}
	cout << "��ǰ�û���Ϊ��" << user.size() << " ��" << endl;
	ifs.close();

	ifs.open(HOSPITAL_FILE, ios::in);

	Hospital h;
	while (ifs >> h.hospitalHid && ifs >> h.username && ifs >> h.passwd && ifs >> h.hospitalId && ifs >> h.hospitalName && ifs >> h.hospitalLevel && ifs >> h.hospitalArea) {
		hospital.push_back(h);
	}
	cout << "��ǰ����ҽԺ����Ϊ��" << hospital.size()  << " ��"<< endl;
	ifs.close();
}

// ����ȥ�غ���
bool Admin::checkRepeat(string id, int type) {
	if (type == 1) {
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->usrMedicalCardNum)
				return true;
		}
	}
	else {
		for (vector<Hospital>::iterator it = hospital.begin(); it != hospital.end(); it++) {
			if (id == it->hospitalId)
				return true;
		}
	}
	return false;
}
