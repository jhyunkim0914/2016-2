#include "composerManager.h"

ComposerManager::ComposerManager()
{
	
}

ComposerManager::~ComposerManager()
{
}

bool ComposerManager::setDBFromFile()
{
	ifstream inFile(fileName, ios::in | ios::binary);

	int id = -1;
	int nameSize = -1;
	string name = "";

	Composer temp;

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
		//���̵� �Է�
		inFile.read((char *)&id, sizeof(int));
		cout << id << '\t';
		temp.setId(id);
		//�н����� ������ �Է�
		inFile.read((char *)&nameSize, sizeof(int));
		cout << nameSize << '\t';
		//�н����� �Է�
		name.resize(nameSize);
		inFile.read(&name[0], nameSize);
		cout << name << '\t';
		temp.setName(name);
		
		composerList.push_back(temp);
		cout << endl;
	}
	inFile.close();

	return true;
}

bool ComposerManager::writeFileFromDB()
{
	ofstream outFile(fileName, ios::out | ios::binary);
	if (!outFile)
	{
		cout << "Cannot open file.\n";
		return false;
	}
	for (vector<Composer>::iterator it = composerList.begin(); it != composerList.end(); it++)
	{
		int inTemp = -1;

		//���̵� �Է�
		inTemp = it->getId();
		outFile.write((char *)&inTemp, sizeof(int));
		//�̸� ������ �Է�
		inTemp = it->getName().size();
		outFile.write((char *)&inTemp, sizeof(int));
		//�̸� �Է�
		string insTemp = it->getName();
		outFile.write((char *)insTemp.c_str(), inTemp);
	}
	outFile.close();
	return true;
}

void ComposerManager::showDB()
{
	ifstream inFile(fileName, ios::in | ios::binary);

	int id = -1;
	int nameSize = -1;
	string name = "";

	Composer temp;

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
		//���̵� �Է�
		inFile.read((char *)&id, sizeof(int));
		cout << id << '\t';
		temp.setId(id);
		//�н����� ������ �Է�
		inFile.read((char *)&nameSize, sizeof(int));
		cout << nameSize << '\t';
		//�н����� �Է�
		name.resize(nameSize);
		inFile.read(&name[0], nameSize);
		cout << name << '\t';
		temp.setName(name);

		cout << endl;
	}
	inFile.close();

	return;
}

bool ComposerManager::addComposerToFile(Composer addedComposer)
{
	addedComposer.setId(composerList.size() + 1);
	composerList.push_back(addedComposer);

	writeFileFromDB();

	return true;
}

Composer ComposerManager::searchComposerByName(string _name)
{
	Composer temp;
	for (vector<Composer>::iterator it = composerList.begin(); it != composerList.end(); it++)
	{
		if (it->getName() == _name)
		{
			return *it;
		}
	}
	return temp;
}

Composer ComposerManager::searchComposerById(int _id)
{
	Composer temp;
	for (vector<Composer>::iterator it = composerList.begin(); it != composerList.end(); it++)
	{
		if (it->getId() == _id)
		{
			return *it;
		}
	}
	return temp;
}

vector<Composer>* ComposerManager::getAllComposerList()
{
	return &composerList;
}

void ComposerManager::showComposerList()
{
	for (vector<Composer>::iterator it = composerList.begin(); it != composerList.end(); it++)
	{
		cout << it->getId() << '\t' << it->getName() << endl;
	}
}
