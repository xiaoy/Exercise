/*
 * PizzaStore.h
 *
 *  Created on: 2012-4-18
 *      Author: lfwu
 */

#ifndef PIZZASTORE_H_
#define PIZZASTORE_H_
#include <iostream>
class Pizza;
class PizzaStore {
public:
	PizzaStore();
	virtual ~PizzaStore();
	Pizza* CreatePizza(std::string pizza_type);
};

#endif /* PIZZASTORE_H_ */
