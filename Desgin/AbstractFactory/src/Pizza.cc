/*
 * Pizza.cpp
 *
 *  Created on: 2012-4-18
 *      Author: lfwu
 */

#include "Pizza.h"

Pizza::Pizza() {
	// TODO Auto-generated constructor stub

}

Pizza::~Pizza() {
	// TODO Auto-generated destructor stub
}

std::string Pizza::GetName()
{
	return name_;
}

void Pizza::SetName(std::string name)
{
	name_ = name;
}

void Pizza::Bake()
{
	std::cout<<"Bake for 25 minutes at 350\n";
}

void Pizza::Cut()
{
	std::cout<<"Cutting the pizza into diagonal slices\n";
}

void Pizza::Box()
{
	std::cout<<"Place pizza in official PizzaStore box.\n";
}
