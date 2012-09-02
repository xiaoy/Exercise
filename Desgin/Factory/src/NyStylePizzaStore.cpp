/*
 * NyStylePizzaStore.cpp
 *
 *  Created on: 2012-4-7
 *      Author: lfwu
 */

#include "NyStylePizzaStore.h"
#include "Pizza.h"
#include "NyStyleChesePizza.h"
#include "NyStyleClamPizza.h"
#include "NyStylePepperoniPizza.h"
#include "NyStyleVeggiePizza.h"
NyStylePizzaStore::NyStylePizzaStore() {
	// TODO Auto-generated constructor stub

}

NyStylePizzaStore::~NyStylePizzaStore() {
	// TODO Auto-generated destructor stub
}

Pizza* NyStylePizzaStore::CreatePizza(PizzaStore::PizzaType type) {
	switch (type) {
	case PizzaStore::CHEESE: {
		pizza_ = new NyStyleChesePizza;
		break;
	}
	case PizzaStore::CLAM: {
		pizza_ = new NyStyleClamPizza;
		break;
	}
	case PizzaStore::PEPPERONI:{
		pizza_ = new NyStylePepperoniPizza;
		break;
	}
	case PizzaStore::VEGGIE:{
		pizza_ = new NyStyleVeggiePizza;
		break;
	}
	}
	return pizza_;
}
