/*
 * Pizza.h
 *
 *  Created on: 2012-4-7
 *      Author: lfwu
 */

#ifndef PIZZA_H_
#define PIZZA_H_
#include <iostream>
class Pizza {
public:
	Pizza();
	virtual ~Pizza();
	virtual std::string GetPizzaName();
protected:
	std::string pizza_name_;
};

#endif /* PIZZA_H_ */
