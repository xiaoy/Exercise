/*
 * Espresso.h
 *
 *  Created on: 2012-4-5
 *      Author: lfwu
 */

#ifndef ESPRESSO_H_
#define ESPRESSO_H_
#include "Beverage.h"
class Espresso : public Beverage{
public:
	Espresso();
	virtual ~Espresso();
	virtual double GetCost();
};

#endif /* ESPRESSO_H_ */
