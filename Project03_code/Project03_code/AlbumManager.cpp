#include "AlbumManager.h"

AlbumManager::AlbumManager()
{
}

AlbumManager::~AlbumManager()
{
}

bool AlbumManager::addMusicAlbumToFile(MusicAlbum addedMusicAlbum)
{
	addedMusicAlbum.setId(albumList.size() + 1);
	albumList.push_back(addedMusicAlbum);

	writeFileFromDB();

	return true;
}

bool AlbumManager::setDBFromFile()
{
	ifstream inFile(fileName, ios::in | ios::binary);

	int id = -1;
	int composerId = -1;
	int buyCount = -1;
	int nameSize = -1;
	string name = "";

	MusicAlbum temp;

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
		//�۰ �Է�
		inFile.read((char *)&composerId, sizeof(int));
		cout << composerId << '\t';
		temp.setComposerId(composerId);
		//����Ƚ�� �Է�
		inFile.read((char *)&buyCount, sizeof(int));
		cout << buyCount << '\t';
		temp.setPurchasedCount(buyCount);
		//�̸� ������ �Է�
		inFile.read((char *)&nameSize, sizeof(int));
		cout << nameSize << '\t';
		//�̸� �Է�
		name.resize(nameSize);
		inFile.read(&name[0], nameSize);
		cout << name << '\t';
		temp.setName(name);

		albumList.push_back(temp);
		cout << endl;
	}
	inFile.close();

	return true;
}

bool AlbumManager::writeFileFromDB()
{
	ofstream outFile(fileName, ios::out | ios::binary);
	if (!outFile)
	{
		cout << "Cannot open file.\n";
		return false;
	}
	for (vector<MusicAlbum>::iterator it = albumList.begin(); it != albumList.end(); it++)
	{
		int inTemp = -1;

		//���̵� �Է�
		inTemp = it->getId();
		outFile.write((char *)&inTemp, sizeof(int));
		//�۰ �Է�
		inTemp = it->getComposerId();
		outFile.write((char *)&inTemp, sizeof(int));
		//����Ƚ�� �Է�
		inTemp = it->getPurchasedCount();
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

void AlbumManager::showDB()
{
	ifstream inFile(fileName, ios::in | ios::binary);

	int id = -1;
	int composerId = -1;
	int buyCount = -1;
	int nameSize = -1;
	string name = "";

	MusicAlbum temp;

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
		//�۰ �Է�
		inFile.read((char *)&composerId, sizeof(int));
		cout << composerId << '\t';
		temp.setComposerId(composerId);
		//����Ƚ�� �Է�
		inFile.read((char *)&buyCount, sizeof(int));
		cout << buyCount << '\t';
		temp.setPurchasedCount(buyCount);
		//�̸� ������ �Է�
		inFile.read((char *)&nameSize, sizeof(int));
		cout << nameSize << '\t';
		//�̸� �Է�
		name.resize(nameSize);
		inFile.read(&name[0], nameSize);
		cout << name << '\t';
		temp.setName(name);

		cout << endl;
	}
	inFile.close();

	return;
}

MusicAlbum AlbumManager::searchMusicAlbumByName(string _name)
{
	MusicAlbum temp;
	for (vector<MusicAlbum>::iterator it = albumList.begin(); it != albumList.end(); it++)
	{
		if (it->getName() == _name)
		{
			return *it;
		}
	}
	return temp;
}

MusicAlbum AlbumManager::searchMusicAlbumById(int _id)
{
	MusicAlbum temp;
	for (vector<MusicAlbum>::iterator it = albumList.begin(); it != albumList.end(); it++)
	{
		if (it->getId() == _id)
		{
			return *it;
		}
	}
	return temp;
}

bool AlbumManager::updateMusicAlbumSellCount(int albumId)
{
	for (vector<MusicAlbum>::iterator it = albumList.begin(); it != albumList.end(); it++)
	{
		if (it->getId() == albumId)
		{
			it->addPurchasedCount();
			writeFileFromDB();
			return true;
		}
	}
	return false;
}

vector<MusicAlbum>* AlbumManager::getAllAlbumList()
{
	return &albumList;
}
