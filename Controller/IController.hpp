#ifndef ICONTROLLER_H
# define ICONTROLLER_H

# include "Input.hpp"

class IController
{
	public:
	virtual IController * update(const Input &) = 0;
	virtual void render() const = 0;
	virtual ~IController() {}
};
#endif
