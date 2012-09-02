/*
 * Beverage.h
 *
 *  Created on: 2012-4-5
 *      Author: lfwu
 */

#ifndef BEVERAGE_H_
#define BEVERAGE_H_
#include <iostream>
class Beverage {
public:
	Beverage();
	virtual ~Beverage();
	virtual std::string GetDescription();
	virtual double GetCost() = 0;
protected:
	std::string description_;
	double cost_;
};

#endif /* BEVERAGE_H_ */
