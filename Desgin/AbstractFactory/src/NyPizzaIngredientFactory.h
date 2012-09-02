/*
 * NyPizzaIngredientFactory.h
 *
 *  Created on: 2012-4-18
 *      Author: lfwu
 */

#ifndef NYPIZZAINGREDIENTFACTORY_H_
#define NYPIZZAINGREDIENTFACTORY_H_
#include "PizzaIngredientFactory.h"
class Dough;
class NyPizzaIngredientFactory : public PizzaIngredientFactory{
public:
	NyPizzaIngredientFactory();
	virtual ~NyPizzaIngredientFactory();
	virtual Dough* CreateDough();
};

#endif /* NYPIZZAINGREDIENTFACTORY_H_ */
