/*
 * NyStyleVeggiePizza.cpp
 *
 *  Created on: 2012-4-7
 *      Author: lfwu
 */

#include "NyStyleVeggiePizza.h"

NyStyleVeggiePizza::NyStyleVeggiePizza() {
	// TODO Auto-generated constructor stub
	pizza_name_ = "New York Veggie Pizza";
}

NyStyleVeggiePizza::~NyStyleVeggiePizza() {
	// TODO Auto-generated destructor stub
}

std::string NyStyleVeggiePizza::GetPizzaName()
{
	return pizza_name_;
}
