#pragma once
#include "Composer.h"
#include "BaseManager.h"
#include <fstream>
class ComposerManager :
	public BaseManager
{
public:
	ComposerManager();
	~ComposerManager();

public:
	bool addComposerToFile(Composer addedComposer);
	Composer searchComposerByName(string _name);
	Composer searchComposerById(int _id);
	vector<Composer> getAllComposerList();
};

