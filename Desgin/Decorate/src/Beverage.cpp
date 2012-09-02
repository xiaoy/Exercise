/*
 * Beverage.cpp
 *
 *  Created on: 2012-4-5
 *      Author: lfwu
 */

#include "Beverage.h"

Beverage::Beverage() {
	// TODO Auto-generated constructor stub
	cost_ = 0;
	description_ = "Unkonwn Beverage!!!";
}

Beverage::~Beverage() {
	// TODO Auto-generated destructor stub
}

std::string Beverage::GetDescription()
{
	return description_;
}
