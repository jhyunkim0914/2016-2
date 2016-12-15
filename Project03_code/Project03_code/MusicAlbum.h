#pragma once
#include <iostream>
#include <string>
using namespace std;

class MusicAlbum
{
public:
	MusicAlbum();
	~MusicAlbum();
	int getId();
	void setId(int id);
	string getName();
	void setName(string name);
	int getComposerId();
	void setComposerId(int cid);
	int getPurchasedCount();
	void setPurchasedCount(int count);
	void addPurchasedCount();
	void setAlbumFromKB();
	static bool comp(MusicAlbum &t1, MusicAlbum &t2);
private:
	int id;
	string name;
	int composerId;
	int purchasedCount;
};

