/*
 * Pizza.cpp
 *
 *  Created on: 2012-4-7
 *      Author: lfwu
 */

#include "Pizza.h"

Pizza::Pizza() {
	// TODO Auto-generated constructor stub
	pizza_name_ = "";
}

Pizza::~Pizza() {
	// TODO Auto-generated destructor stub
}

std::string Pizza::GetPizzaName()
{
	return pizza_name_;
}
