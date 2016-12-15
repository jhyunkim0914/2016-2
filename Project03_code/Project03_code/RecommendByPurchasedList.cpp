#include "RecommendByPurchasedList.h"



RecommendByPurchasedList::RecommendByPurchasedList()
{
}

RecommendByPurchasedList::RecommendByPurchasedList(UserManager * um, ComposerManager * cm, AlbumManager * am, User * user)
{
	this->um = um; this->cm = cm; this->am = am; this->user = user;
}


RecommendByPurchasedList::~RecommendByPurchasedList()
{
}

vector<MusicAlbum> RecommendByPurchasedList::recommend()
{
	vector<MusicAlbum> result;
	vector<int> purchasedList = *(user->getPurchasedList());
	sort(purchasedList.begin(), purchasedList.end());
	vector<int>::iterator pos;
	pos = unique(purchasedList.begin(), purchasedList.end());
	purchasedList.erase(pos, purchasedList.end());
	// 겹치지 않는 구매목록 1,2,3
	// 전체 목록          1,2,3,4,5 
	
	vector<int> temp;

	for (vector<int>::iterator it = purchasedList.begin(); it != purchasedList.end(); it++)
	{
		MusicAlbum album = am->searchMusicAlbumById(*it); Composer composer = cm->searchComposerById(album.getComposerId());
		//해당 앨범의 작곡가를 찾는다.
		//작곡가의 앨범목록을 출력
		
		vector<MusicAlbum> composerMusicList = am->searchMusicAlbumByComposer(album.getComposerId());
		for (vector<MusicAlbum>::iterator it2 = composerMusicList.begin(); it2 != composerMusicList.end(); it2++)
		{
			temp.push_back(it2->getId());
		}
	}

	sort(temp.begin(), temp.end());
	vector<int>::iterator pos2;
	pos2 = unique(temp.begin(), temp.end());
	temp.erase(pos2, temp.end());

	for (std::vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++ )
	{
		bool isIn = false;
		for (vector<int>::iterator it2 = purchasedList.begin(); it2 != purchasedList.end(); it2++)
		{
			if (*iter == *it2)
				isIn = true;
		}
		if (isIn == false)
		{
			result.push_back(am->searchMusicAlbumById(*iter));
		}
	}
	
	return result;
}
