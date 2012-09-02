/*
 * PizzaStore.cpp
 *
 *  Created on: 2012-4-7
 *      Author: lfwu
 */

#include "PizzaStore.h"
#include "Pizza.h"
PizzaStore::PizzaStore() {
	// TODO Auto-generated constructor stub

}

PizzaStore::~PizzaStore() {
	// TODO Auto-generated destructor stub
}

Pizza* PizzaStore::OrderPizza(PizzaType type)
{
	pizza_ = CreatePizza(type);
	return pizza_;
}
