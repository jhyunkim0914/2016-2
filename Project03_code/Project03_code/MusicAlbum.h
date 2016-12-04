#pragma once
#include <string>
using namespace std;

class MusicAlbum
{
public:
	MusicAlbum();
	~MusicAlbum();

private:
	int id;
	string name;
	int composerId;
	int purchasedCount;
};

