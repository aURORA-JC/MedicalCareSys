#include "Admin.h"


Admin::Admin() {

}

Admin::Admin(string adminId, string adminName, string adminArea) {
	this->adminId = adminId;
	this->adminName = adminName;
	this->adminArea = adminArea;

	this->initVector();
}

void Admin::openMenu() {
	cout << "��ӭ����������Ա��" << this->adminName << endl;
	cout << " --------------------------------------------------------\n"
		<< "|                                                        |\n"
		<< "|         1.����û�  2.��Ӷ���ҽԺ  3.����˵�         |\n"
		<< "|                                                        |\n"
		<< "|         4.�г��û�  5.�г�����ҽԺ  6.�г��˵�         |\n"
		<< "|                                                        |\n"
		<< "|         7.�����û�  8.��������ҽԺ  9.�����˵�         |\n"
		<< "|                                                        |\n"
		<< "|         10.ɾ���û� 11.ɾ������ҽԺ 12.ɾ���˵�        |\n"
		<< "|                                                        |\n"
		<< "|         13.���ȫ������             0.ע��             |\n"
		<< " --------------------------------------------------------\n"
		<< "��ѡ��";
}

void Admin::addUser() {
	ofstream ofs;
	ofs.open(USER_FILE,ios::out | ios::app);
	
	int addNum;
	cout << "���Ͷ����������" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i+1 << " ����Ͷ����" << endl;

		string f2Id;
		cout << "����ҽ�����ţ�" << endl;
		cin >> f2Id;

		if (this->checkRepeat(f2Id, 1)) {
			cout << "ҽ�������ظ���¼����ֹ��" << endl;
			break;
		}

		string f2Name;
		cout << "����ҽ��ϵͳ�û�����" << endl;
		cin >> f2Name;

		string f2Pwd;
		cout << "����ҽ��ϵͳ���룺" << endl;
		cin >> f2Pwd;

		string f2usrName;
		cout << "����Ͷ����������" << endl;
		cin >> f2usrName;

		int f2age;
		cout << "����Ͷ�������䣺" << endl;
		cin >> f2age;

		string f2idCardNum;
		cout << "����Ͷ����֤���ţ�" << endl;
		cin >> f2idCardNum;

		string f2usrNation;
		cout << "����Ͷ�������壺" << endl;
		cin >> f2usrNation;

		string f2idClass;
		cout << "����Ͷ�������" << endl;
		cin >> f2idClass;

		bool f2inHosp;
		string statu;
		cout << "Ͷ���˵�ǰ�Ƿ�סԺ���ǡ��񣩣�" << endl;
		cin >> statu;
		if (statu == "��")
			f2inHosp = 0;
		else
			f2inHosp = 1;

		double f2cardBalance = 0;
		cout << "����ҽ�������" << endl;
		cin >> f2cardBalance;

		string f2medicalArea;
		cout << "����ҽ��������" << endl;
		cin >> f2medicalArea;

		cout << "��Ϣ¼����..." << endl;
		ofs << f2Id << " " << f2Name << " " << f2Pwd << " " << f2usrName << " " << f2age << " " << f2idCardNum << " " << f2usrNation << " " << f2idClass << " " << f2inHosp << " " << f2cardBalance << " " << f2medicalArea << endl;
		cout << "¼��ɹ���" << endl;

		system("pause");
		this->initVector();
	}

	system("cls");
	this->initVector();
	ofs.close();
}

void Admin::addHospital() {
	ofstream ofs;
	ofs.open(HOSPITAL_FILE, ios::out | ios::app);

	int addNum;
	cout << "��Ӷ���ҽԺ������" << endl;
	cin >> addNum;

	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i + 1 << " ��������ҽԺ" << endl;

		string f2Id;
		cout << "���붨��ҽԺ�����ţ�" << endl;
		cin >> f2Id;

		if (this->checkRepeat(f2Id, 1)) {
			cout << "����ҽԺ�������ظ���¼����ֹ��" << endl;
			break;
		}

		string f2Name;
		cout << "����ҽ��ϵͳ�û�����" << endl;
		cin >> f2Name;

		string f2Pwd;
		cout << "����ҽ��ϵͳ���룺" << endl;
		cin >> f2Pwd;

		string f2hospName;
		cout << "����ҽԺ���ƣ�" << endl;
		cin >> f2hospName;

		int f2level;
		cout << "����ҽԺ�ȼ���" << endl;
		cin >> f2level;

		string f2hospArea;
		cout << "����ҽԺ����������" << endl;
		cin >> f2hospArea;

		cout << "��Ϣ¼����..." << endl;
		ofs << f2Id << " " << f2Name << " " << f2Pwd << " " << f2hospName << " " << f2level << " " << f2hospArea << endl;
		cout << "¼��ɹ���" << endl;
		
		system("pause");
		this->initVector();
	}

	system("cls");
	this->initVector();
	ofs.close();
}

void Admin::addBill() {
	ofstream ofs;
	ofs.open(BILL_FILE, ios::out | ios::app);

	int addNum;
	cout << "����˵���Ŀ��";
	cin >> addNum;
	for (int i = 0; i < addNum; i++) {
		cout << "��ӵ� �� " << i + 1 << " �����˵�" << endl;

		string f2belong;
		cout << "����Ӧ֧����ҽ�����ţ�" << endl;
		cin >> f2belong;

		string f2about;
		cout << "������ϸ��Ϣ��" << endl;
		cin >> f2about;

		string f2hospital;
		cout << "�������ҽԺ��" << endl;
		cin >> f2hospital;

		double f2value;
		cout << "�����˵���" << endl;
		cin >> f2value;

		cout << "��Ϣ¼����..." << endl;
		ofs << f2belong << " " << f2about << " " << f2hospital << " " << f2value << endl;
		cout << "¼��ɹ���" << endl;

		system("pause");
	} 

	system("cls");
	ofs.close();
}

void printUser(User& u);
void printHospital(Hospital& h);

void Admin::showUser() {
	cout << "����Ͷ������Ϣ���£�" << endl;
	for_each(user.begin(), user.end(), printUser);
	system("pause");
	system("cls");
}

void Admin::showHospital() {
	cout << "���ж���ҽԺ��Ϣ���£�" << endl;
	for_each(hospital.begin(), hospital.end(), printHospital);
	system("pause");
	system("cls");
}

void Admin::showBill() {
}

void Admin::searchUser() {

}

void Admin::searchHospital() {

}

void Admin::searchBill() {

}

void Admin::deleteUser() {

}

void Admin::deleteHospital() {

}

void Admin::deleteBill() {

}

void Admin::deleteAll() {

}

void Admin::initVector() {
	ifstream ifs;
	ifs.open(USER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "��ȡ����ʧ�ܣ�" << endl;
		return;
	}

	user.clear();
	hospital.clear();

	User u;
	while (ifs >> u.userId && ifs >> u.userName && ifs >> u.userAge && ifs >> u.idCardNum && ifs >> u.userNation && ifs >> u.idClass && ifs >> u.inHsopital && ifs >> u.cardBanlance && ifs >> u.MedialCareBelongsArea) {
		user.push_back(u);
	}
	cout << "��ǰͶ������Ϊ��" << user.size() << " ��" << endl;
	ifs.close();

	ifs.open(HOSPITAL_FILE, ios::in);

	Hospital h;
	while (ifs >> h.hospitalId && ifs >> h.hospitalName && ifs >> h.hospitalLevel && ifs >> h.hospitalArea) {
		hospital.push_back(h);
	}
	cout << "��ǰ����ҽԺ����Ϊ��" << hospital.size()  << " ��"<< endl;
	ifs.close();
}

bool Admin::checkRepeat(string id, int type) {
	if (type == 1) {
		for (vector<User>::iterator it = user.begin(); it != user.end(); it++) {
			if (id == it->userId)
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


void printUser(User &u) {
	cout << "ҽ������:" << setw(20) << u.userId << resetiosflags
		<< "������" << setw(10) << u.userName << resetiosflags
		<< "���䣺" << setw(4) << u.userAge << resetiosflags
		// << "�Ա�" << setw(2) << u.userAge << resetiosflags
		<< "֤�����룺" << setw(20) << u.idCardNum << resetiosflags
		<< "���壺" << setw(5) << u.userNation << resetiosflags
		<< "���" << setw(5) << u.idClass << resetiosflags
		<< "��Ժ�����" << setw(2) << u.inHsopital << resetiosflags
		<< "��" << setw(10) << setiosflags(ios::fixed) << setprecision(2) << u.cardBanlance << resetiosflags
		<< "ҽ����������" << setw(10) << u.MedialCareBelongsArea << resetiosflags << endl;
}

void printHospital(Hospital& h) {
	cout << "����ҽԺ�����ţ�" << setw(10) << h.hospitalId << resetiosflags
		<< "ҽԺ����" << setw(25) << h.hospitalName << resetiosflags
		<< "ҽԺ�ȼ���" << setw(2) << h.hospitalLevel << resetiosflags
		<< "ҽԺ��������" << setw(10) << h.hospitalArea << resetiosflags << endl;
}