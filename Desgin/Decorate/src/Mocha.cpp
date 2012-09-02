/*
 * Mocha.cpp
 *
 *  Created on: 2012-4-6
 *      Author: lfwu
 */

#include "Mocha.h"
#include "Beverage.h"
Mocha::Mocha(Beverage* beverage) {
	// TODO Auto-generated constructor stub
	beverage_ = beverage;
}

Mocha::~Mocha() {
	// TODO Auto-generated destructor stub
}

double Mocha::GetCost()
{
	return 0.99 + beverage_->GetCost();
}

std::string Mocha::GetDescription()
{
	return beverage_->GetDescription() + std::string(", Mocha");
}
