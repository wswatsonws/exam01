#ifndef UNIT_CLASS_HPP
# define UNIT_CLASS_HPP

# include <string>
# include <iostream>

class unit
{
protected:
	int			_index;
	std::string	_name;
	std::string	_type;
	int			_x;
	int			_y;
	int			_dam;
	int			_cHP;
	int			_mHP;
	static int	_nb;
public:
	unit(void);
	unit(unit const &u);
	unit(std::string const &name,std::string const &type, int const x, int const y,
		 int const dam, int const cHP, int const mHP);
		 
	unit(std::string const &name,int const x, int const y);
	virtual ~unit(void);

	unit				&operator=(unit const &u);
	unit				&operator+=(int const i);
	unit				&operator-=(int const i);

	int					getIndex(void) const;
	std::string const	&getName(void) const;
	std::string const	&getType(void) const;
	int					getX(void) const;
	int					getY(void) const;
	int					getDam(void) const;
	int					getCHP(void) const;
	int					getMHP(void) const;

	virtual void		die(void);
	virtual void		move(int x, int y);
	void				attack(unit &target) const;
};

std::ostream		&operator<<(std::ostream &os, unit const &u);

#endif
