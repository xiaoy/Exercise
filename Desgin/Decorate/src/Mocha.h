/*
 * Mocha.h
 *
 *  Created on: 2012-4-6
 *      Author: lfwu
 */

#ifndef MOCHA_H_
#define MOCHA_H_
#include "Condiment.h"
#include <iostream>
class Beverage;
class Mocha : public Condiment{
public:
	Mocha(Beverage* beverage);
	virtual ~Mocha();
	virtual double GetCost();
	virtual std::string GetDescription();
private:
	Beverage* beverage_;
};

#endif /* MOCHA_H_ */
