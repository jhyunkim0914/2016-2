#include "userManager.h"

UserManager::UserManager()
{
}

UserManager::~UserManager()
{
}

bool UserManager::setDBFromFile()
{
	ifstream inFile(fileName, ios::in | ios::binary);

	int isAdmin = -1;
	int id = -1;
	int passwordSize = -1;
	string password = "";
	int listSize = -1;
	int listSource = -1;
	vector<int> list;

	User temp;

	if (!inFile)
	{
		cout << "Cannot open file.\n";
		return false;
	}

	//���� ���̸� �����Ѵ�.
	inFile.seekg(0, inFile.end);
	std::streampos length = inFile.tellg();
	inFile.seekg(0, inFile.beg);

	//������ ������ �ݺ�, length��ġ ����!
	while (length != inFile.tellg())
	{
		//������ ���� �Է�
		inFile.read((char *)&isAdmin, sizeof(int));
		cout << isAdmin << '\t';
		temp.setIsAdmin(isAdmin);
		//���̵� �Է�
		inFile.read((char *)&id, sizeof(int));
		cout << id << '\t';
		temp.setId(id);
		//�н����� ������ �Է�
		inFile.read((char *)&passwordSize, sizeof(int));
		cout << passwordSize << '\t';
		//�н����� �Է�
		password.resize(passwordSize);
		inFile.read(&password[0], passwordSize);
		cout << password << '\t';
		temp.setPW(password);
		//����Ʈ ������ �Է�
		inFile.read((char *)&listSize, sizeof(int));
		cout << listSize << '\t';
		//����Ʈ �����ŭ �ݺ�
		for (int i = 0; i < listSize; i++)
		{
			//����Ʈ ���� �Է�
			inFile.read((char *)&listSource, sizeof(int));
			cout << listSource << '\t';
			list.push_back(listSource);
		}
		temp.setPurchasedList(list);
		userList.push_back(temp);
		cout << endl;
	}
	return true;
}

bool UserManager::writeFileFromDB()
{
	ofstream outFile(fileName, ios::out | ios::binary);
	if (!outFile)
	{
		cout << "Cannot open file.\n";
		return false;
	}
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		//������ ���� �Է�
		int inTemp = it->getIsAdmin();
		outFile.write((char *)&inTemp, sizeof(int));
		//���̵� �Է�
		inTemp = it->getId();
		outFile.write((char *)&inTemp, sizeof(int));
		//�н����� ������ �Է�
		inTemp = it->getPW().size();
		outFile.write((char *)&inTemp, sizeof(int));
		//�н����� �Է�
		string insTemp = it->getPW();
		outFile.write((char *)insTemp.c_str(), inTemp);
		//���Ը�� ������ �Է�
		inTemp = it->getPurchasedList()->size();
		outFile.write((char *)&inTemp, sizeof(int));
		//���Ը�� �Է�
		for (int i = 0; i < inTemp; i++)
		{
			//���Ը�� ���� �Է�
			int inTemp2 = it->getPurchasedList()->at(i);
			outFile.write((char *)&inTemp2, sizeof(int));
		}
	}
	outFile.close();
	return true;
}

void UserManager::showDB()
{
	ifstream inFile(fileName, ios::in | ios::binary);

	int isAdmin = -1;
	int id = -1;
	int passwordSize = -1;
	string password = "";
	int listSize = -1;
	int listSource = -1;
	vector<int> list;

	User temp;

	if (!inFile)
	{
		cout << "Cannot open file.\n";
		return;
	}

	//���� ���̸� �����Ѵ�.
	inFile.seekg(0, inFile.end);
	std::streampos length = inFile.tellg();
	inFile.seekg(0, inFile.beg);

	//������ ������ �ݺ�, length��ġ ����!
	while (length != inFile.tellg())
	{
		//������ ���� �Է�
		inFile.read((char *)&isAdmin, sizeof(int));
		cout << isAdmin << '\t';
		temp.setIsAdmin(isAdmin);
		//���̵� �Է�
		inFile.read((char *)&id, sizeof(int));
		cout << id << '\t';
		temp.setId(id);
		//�н����� ������ �Է�
		inFile.read((char *)&passwordSize, sizeof(int));
		cout << passwordSize << '\t';
		//�н����� �Է�
		password.resize(passwordSize);
		inFile.read(&password[0], passwordSize);
		cout << password << '\t';
		temp.setPW(password);
		//����Ʈ ������ �Է�
		inFile.read((char *)&listSize, sizeof(int));
		cout << listSize << '\t';
		//����Ʈ �����ŭ �ݺ�
		for (int i = 0; i < listSize; i++)
		{
			//����Ʈ ���� �Է�
			inFile.read((char *)&listSource, sizeof(int));
			cout << listSource << '\t';
			list.push_back(listSource);
		}
		cout << endl;
	}
	inFile.close();
}

bool UserManager::addUserToFile(User addedUser)
{
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (it->getId() == addedUser.getId())
		{
			return false;
		}
	}
	userList.push_back(addedUser); //userList�� �ش� ������ �߰��Ѵ�. (�޸�)
	
	writeFileFromDB(); //userDB�� ���� ����.
	return true;
}

User* UserManager::authenticateUser(int _id, string _pw)
{
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (it->getId() == _id)
		{
			if (it->getPW() == _pw)
				return &(*it);
			else
				return nullptr;
		}
	}
	return nullptr;
}

vector<int>* UserManager::getPurchasedListByUserId(int _id)
{
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (it->getId() == _id)
		{
			return it->getPurchasedList();
		}
	}
	return nullptr;
}

vector<User>* UserManager::getAllUserList()
{
	return &userList;
}

bool UserManager::addAlbumIdToPurchaseList(int _userId, int _albumId)
{
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (it->getId() == _userId)
		{
			it->getPurchasedList()->push_back(_albumId); //userList�� ���ų��� �߰� (�޸�)
			writeFileFromDB(); //userDB�� ���� ����.
			return true;
		}
	}
	return false;
}
