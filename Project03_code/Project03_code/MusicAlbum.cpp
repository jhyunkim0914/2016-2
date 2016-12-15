#include "MusicAlbum.h"

MusicAlbum::MusicAlbum()
{
	id = -1;
	purchasedCount = 0;
	name = "";
}

MusicAlbum::~MusicAlbum()
{
}

int MusicAlbum::getId()
{
	return id;
}

void MusicAlbum::setId(int id)
{
	this->id = id;
}

string MusicAlbum::getName()
{
	return name;
}

void MusicAlbum::setName(string name)
{
	this->name = name;
}

int MusicAlbum::getComposerId()
{
	return composerId;
}

void MusicAlbum::setComposerId(int cid)
{
	this->composerId = cid;
}

int MusicAlbum::getPurchasedCount()
{
	return purchasedCount;
}

void MusicAlbum::setPurchasedCount(int count)
{
	this->purchasedCount = count;
}

void MusicAlbum::addPurchasedCount()
{
	purchasedCount++;
}

void MusicAlbum::setAlbumFromKB()
{
	cout << "¾Ù¹ü ÀÌ¸§ : ";
	cin >> name;
	return;
}

bool MusicAlbum::comp(MusicAlbum & t1, MusicAlbum & t2)
{
	return (t1.getPurchasedCount() > t2.getPurchasedCount());
}
