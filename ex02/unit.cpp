#include "unit.h"

int					unit::_nb = 0;


unit::unit(void):
	_index(_nb),
	_name("Jim"),
	_type("Marine"),
	_x(0),
	_y(0),
	_dam(0),
	_cHP(0),
	_mHP(0)
{
	//std::cout << "[CREATED] Unit #" << _index << ": " << _type
//			  << " in " << _x << "/" << _y << " with " << _cHP << "/" << _mHP
	//		  << "HP damaging at " << _dam << "." << std::endl;
	_nb++;
}
unit::unit(std::string const &name,std::string const &type, int const x, int const y, 
		   int const dam, int const cHP, int const mHP):
	_index(_nb),
	_name(name),
	_type(type),
	_x(x),
	_y(y),
	_dam(dam),
	_cHP(cHP),
	_mHP(mHP)
{
//	std::cout << "[CREATED] Unit #" << _index << ": " << _type
	//		  << " in " << _x << "/" << _y << " with " << _cHP << "/" << _mHP
	//		  << "HP damaging at " << _dam << "." << std::endl;
	_nb++;
}

unit::unit(std::string const &name,int const x, int const y):
	_index(_nb),
	_name(name),
	_x(x),
	_y(y)
{
	_nb++;
}


unit::unit(unit const &u):
	_index(_nb)
{
	*this = u;
//	std::cout << "[CREATED] Unit #" << _index << ": " << _type
//			  << " in " << _x << "/" << _y << " with " << _cHP << "/" << _mHP
//			  << "HP damaging at " << _dam << "." << std::endl;
	_nb++;
}
unit::~unit(void)
{
	//std::cout << "[DESTRUCTED] Unit #" << _index << ": " << _type
	//		  << " in " << _x << "/" << _y << " with " << _cHP << "/" << _mHP
	//		  << "HP damaging at " << _dam << "." << std::endl;
}

unit		&unit::operator=(unit const &u)
{
	if (this != &u)
	{
		_name = u.getName();
		_type = u.getType();
		_x = u.getX();
		_y = u.getY();
		_dam = u.getDam();
		_cHP = u.getCHP();
		_mHP = u.getMHP();
	}
	return (*this);
}
unit		&unit::operator+=(int const i)
{
	_cHP += i;
	if (_cHP > _mHP)
		_cHP = _mHP;
	return (*this);
}
unit		&unit::operator-=(int const i)
{
	if (_cHP <= i)
		die();
	else
		_cHP -= i;
	return (*this);
}

int					unit::getIndex(void) const
{
	return (_index);
}

std::string	const	&unit::getName(void) const
{
	return (_name);
}

std::string	const	&unit::getType(void) const
{
	return (_type);
}
int					unit::getX(void) const
{
	return (_x);
}
int					unit::getY(void) const
{
	return (_y);
}
int					unit::getDam(void) const
{
	return (_dam);
}
int					unit::getCHP(void) const
{
	return (_cHP);
}
int					unit::getMHP(void) const
{
	return (_mHP);
}

void				unit::die(void)
{
	_cHP = 0;
	std::cout << "Unit #" << _index << " (" << _type
			  << ") died." << std::endl;
}
void				unit::move(int x, int y)
{
	std::cout << "unit #" << _index << " (" << _type
			  << ") is moving from " << _x << "/" << _y
			  << " to " << x << "/" << y << "." << std::endl;
	_x = x;
	_y = y;
}
void				unit::attack(unit &target) const
{
	if (_cHP <= 0)
		return ;
	std::cout << "unit #" << _index << " (" << _type
			  << ") damaged unit #" << target.getIndex() << " ("
			  << target.getType() << ")." << std::endl;
	target -= _dam;
}
std::ostream		&operator<<(std::ostream &os, unit const &u)
{
	/*os << "Unit #" << u.getIndex() << ": " << u.getType()
	   << " in " << u.getX() << "/" << u.getY() << " with "
	   << u.getCHP() << "/" << u.getMHP()
	   << "HP damaging at " << u.getDam() << ".";*/
	   
	     std::cout << u.getName() << " is a " << u.getType() << " in " << u.getX() << '/' << u.getY() << " with ";
    std::cout << u.getCHP() << '/' << u.getMHP() << "HP damaging at " << u.getDam() << '.';
 
	return (os);
}
