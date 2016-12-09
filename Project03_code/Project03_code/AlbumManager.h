#pragma once
#include "MusicAlbum.h"
#include "BaseManager.h"
class AlbumManager :
	public BaseManager
{
public:
	AlbumManager();
	~AlbumManager();

public:
	bool addMusicAlbumToFile(MusicAlbum addedMusicAlbum);
	bool setDBFromFile();
	bool writeFileFromDB();
	void showDB();
	MusicAlbum searchMusicAlbumByName(string _name);
	MusicAlbum searchMusicAlbumById(int _id);
	bool updateMusicAlbumSellCount(int albumId);
	vector<MusicAlbum>* getAllAlbumList();
	
private:
	vector<MusicAlbum> albumList;
};

