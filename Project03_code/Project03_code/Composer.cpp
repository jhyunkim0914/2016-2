#include "Composer.h"

Composer::Composer()
{
	id = -1;
}

Composer::~Composer()
{
}

bool Composer::setComposerFromKB()
{
	cout << "���ǰ� �̸� : ";
	cin >> name;
	return true;
}

int Composer::getId()
{
	return id;
}

string Composer::getName()
{
	return name;
}

void Composer::setId(int id)
{
	this->id = id;
}

void Composer::setName(string name)
{
	this->name = name;
}
