#include "userManager.h"

UserManager::UserManager()
{
}

UserManager::UserManager(string fileName)
{
	setFileName(fileName);
}

UserManager::~UserManager()
{
}

bool UserManager::setDBFromFile()
{
	ifstream inFile("userDB", ios::in | ios::binary);

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
	int length = inFile.tellg();
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
		inFile.read(&password[0], sizeof(passwordSize));
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

bool UserManager::addUserToFile(User addedUser)
{
	for (vector<User>::iterator it = userList.begin(); it != userList.end(); it++)
	{
		if (it->getId() == addedUser.getId())
		{
			return false;
		}
	}
	userList.push_back(addedUser);
	return true;
}

bool UserManager::authenticateUser(int _id, string _pw)
{
	return false;
}

vector<int> UserManager::getPurchasedListByUserId(int _id)
{
	return vector<int>();
}

vector<User> UserManager::getAllUserList()
{
	return userList;
}

bool UserManager::addAlbumIdToPurchaseList(int _userId, int _albumId)
{
	return false;
}
