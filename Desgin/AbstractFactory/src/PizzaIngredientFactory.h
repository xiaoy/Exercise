/*
 * PizzaIngredientFactory.h
 *
 *  Created on: 2012-4-18
 *      Author: lfwu
 */

#ifndef PIZZAINGREDIENTFACTORY_H_
#define PIZZAINGREDIENTFACTORY_H_
class Dough;
class PizzaIngredientFactory {
public:
	PizzaIngredientFactory();
	virtual ~PizzaIngredientFactory();
	virtual Dough* CreateDough() = 0;
};

#endif /* PIZZAINGREDIENTFACTORY_H_ */
