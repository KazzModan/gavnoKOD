#include "Water.h"
#include <iostream>

using namespace std;

Water::Water()
{
	lenght = 0;
	weight = 0;
	depth = 0;
	name = "Noname\n";
	type = NONE;

}

Water::~Water()
{
}

Water::Water(int depth, int weight, int lenght, Type type, string name)
{
	setDepth(depth);
	setWeight(weight);
	setLenght(lenght);
	setType(type);
	setName(name);
}

void Water::setName(string name)
{
	if (!(name.empty()))
		this->name = name;
}

void Water::setLenght(int lenght)
{
	if (lenght > 0)
		this->lenght = lenght;
}

void Water::setWeight(int weight)
{
	if (weight > 0)
		this->weight = weight;
}

void Water::setDepth(int depth)
{
	if (depth > 0)
		this->depth = depth;
}
Water::Type Water::setType(Type type)
{
	if (type >= OCEAN && type <= NONE)
		return type;
}

int Water::getLenght()const
{
	return this->lenght;
}

int Water::getDepth()const
{
	return this->depth;
}

int Water::getWeight()const
{
	return this->weight;
}

string Water::getType() const
{
	switch (type)
	{
	case Water::OCEAN:
		return "OCEAN";
	case Water::SEA:
		return "SEA";
	case Water::LAKE:
		return "LAKE";
	case Water::RIVER:
		return "RIVER";
	case Water::SWAMP:
		return "SWAMP";
	case Water::NONE:
		return "NONE";
	default:
		break;
	}
}

void Water::print()
{
	cout << "Name of water: " << getName() << endl;
	cout << " lenght of water " << getLenght() << endl;
	cout << "Weight of water " << getWeight() << endl;
	cout << "Depth of water " << getWeight() << endl;
	cout << "Type of water" << getType() << endl;
}

string Water::getName() const
{
	return this->name;
}

void Water::square()
{
	cout << "square of this water is:" << getLenght() * getWeight();
}

void Water::volume()
{
	cout << "volume of this water is:" << getLenght() * getWeight() * getDepth();
}

int Water::findSame(Water fWater, Water sWater)
{
	if (fWater.type == sWater.type)
		return 0;
	return 1;
}

int Water::bigestSquar(Water fWater, Water sWater)
{
	if (fWater.square > sWater.square)
		return 1;
	if (fWater.square == sWater.square)
		return 0;
	return -1;
}

void Water::BiggestSquareInArray(Water* water, size_t size)
{
	int choose = 0;
	int index = 0;
	int min = 0;
	cout << "Enter type of water in numbers: ";
	cin >> choose;
	switch (choose)
	{
	case 0:
		for (size_t i = 0; i < size; i++)
		{
			if (water[i].type == OCEAN)
			{
				if (min < water[i].square)
					index = i;
				min = water[i].square;
			}
		}
	case 1:
		for (size_t i = 0; i < size; i++)
		{
			if (water[i].type == SEA)
			{
				if (min < water[i].square)
					index = i;
				min = water[i].square;
			}
		}
	case 2:
		for (size_t i = 0; i < size; i++)
		{
			if (water[i].type == LAKE)
			{
				if (min < water[i].square)
					index = i;
				min = water[i].square;
			}
		}
	case 3:
		for (size_t i = 0; i < size; i++)
		{
			if (water[i].type == RIVER)
			{
				if (min < water[i].square)
					index = i;
				min = water[i].square;
			}
		}
	case 4:
		for (size_t i = 0; i < size; i++)
		{
			if (water[i].type == SWAMP)
			{
				if (min < water[i].square)
					index = i;
				min = water[i].square;
			}
		}
	default:
		break;
	}
}
