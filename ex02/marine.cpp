#include "marine.h"

marine::marine(void):
	unit("Watson", "Marine", 0, 0, 6, 40, 40)
{
	std::cout  << "Do you want a piece of me, boy ?" << std::endl;
}
marine::marine(marine const &m):unit(m._name,m._type,m._x,m._y,m._dam,m._cHP,m._mHP)
{
	*this = m;
	std::cout  << "Do you want a piece of me, boy ?" << std::endl;
}
/*marine::marine(std::string const &name,int const x, int const y):
	unit("Jim", "Marine",23,56,40,40,40)
{
	std::cout  << "Do you want a piece of me, boy ?" << std::endl;
}*/
marine::~marine(void)
{
	std::cout  << "Aaaargh..." << std::endl;
}

marine	&marine::operator=(marine const &m)
{
	if (this != &m)
	{
		_name = m.getName();
		_type = m.getType();
		_x = m.getX();
		_y = m.getY();
		_dam = m.getDam();
		_cHP = m.getCHP();
		_mHP = m.getMHP();
	}
	return (*this);
}


void	marine::die(void)
{
	//std::cout << "unit #" << _index << " (" << _type
	//		  << ") died." << std::endl;
	//_cHP = 0;
	std::cout  << "Aaaargh..." << std::endl;
}

void	marine::move(int x, int y)
{
	//std::cout << "unit #" << _index << " (" << _type
		//	  << ") is moving from " << _x << "/" << _y
			//  << " to " << x << "/" << y << "." << std::endl;
	std::cout << "Rock'n'roll !!!" << std::endl;
	_x = x;
	_y = y;
}

void	marine::stimpack(void)
{
	_dam *= 2;
	if (_cHP < 11 && _cHP > 0)
		_cHP = 1;
	else
		_cHP -= 10;
	std::cout  << "Ho yeah..." << std::endl;
}

