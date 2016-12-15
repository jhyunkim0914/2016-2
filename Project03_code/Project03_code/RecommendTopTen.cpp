#include "RecommendTopTen.h"

RecommendTopTen::RecommendTopTen()
{
}

RecommendTopTen::RecommendTopTen(UserManager * um, ComposerManager * cm, AlbumManager * am, User * user)
{
	this->um = um; this->cm = cm; this->am = am; this->user = user;
}

RecommendTopTen::~RecommendTopTen()
{
}

vector<MusicAlbum> RecommendTopTen::recommend()
{
	vector<MusicAlbum> *topten = am->getAllAlbumList();
	vector<MusicAlbum> temp = *topten;

	sort(temp.begin(), temp.end(), MusicAlbum::comp);

	if (temp.size() > 10)
	{
		vector<MusicAlbum>::iterator begin = temp.begin();
		vector<MusicAlbum>::iterator end = temp.end();
		temp.erase(begin + 10, end);
	}

	return temp;
}
