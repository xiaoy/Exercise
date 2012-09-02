/*
 * Condiment.h
 *
 *  Created on: 2012-4-5
 *      Author: lfwu
 */

#ifndef CONDIMENT_H_
#define CONDIMENT_H_
#include "Beverage.h"
class Condiment  : public Beverage{
public:
	Condiment();
	virtual ~Condiment();
	virtual std::string GetDescription() = 0;
};

#endif /* CONDIMENT_H_ */
