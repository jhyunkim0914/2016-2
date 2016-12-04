#pragma once
#include "BaseRecommendationAlg.h"
class RecommendTopTen :
	public BaseRecommendationAlg
{
public:
	RecommendTopTen();
	~RecommendTopTen();

	virtual vector<MusicAlbum> recommend();
};

