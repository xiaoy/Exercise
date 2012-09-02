/*
 * PizzaStore.cc
 *
 *  Created on: 2012-4-18
 *      Author: lfwu
 */

#include "PizzaStore.h"
#include "Pizza.h"
#include "PizzaIngredientFactory.h"
#include "NyPizzaIngredientFactory.h"
PizzaStore::PizzaStore() {
	// TODO Auto-generated constructor stub

}

PizzaStore::~PizzaStore() {
	// TODO Auto-generated destructor stub
}

Pizza* PizzaStore::CreatePizza(std::string pizza_type)
{
	if(pizza_type.equal("Ny") == 0)
	{
		PizzaIngredientFactory* factory = new NyPizzaIngredientFactory;
		return  factory->CreateDough();
	}
	return NULL;
}
