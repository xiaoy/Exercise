/*
 * NyPizzaIngredientFactory.cc
 *
 *  Created on: 2012-4-18
 *      Author: lfwu
 */

#include "NyPizzaIngredientFactory.h"
#include "Dough.h"
NyPizzaIngredientFactory::NyPizzaIngredientFactory() {
	// TODO Auto-generated constructor stub

}

NyPizzaIngredientFactory::~NyPizzaIngredientFactory() {
	// TODO Auto-generated destructor stub
}

Dough* NyPizzaIngredientFactory::CreateDough()
{
	return new Dough;
}
