//============================================================================
// Name        : Decorate.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Beverage.h"
#include "Espresso.h"
#include "Mocha.h"
int main() {
	Beverage* beverage = new Espresso;
	Beverage* temp = beverage;
	beverage = new Mocha(beverage);
	beverage = new Mocha(beverage);
	cout<<beverage->GetDescription()<<"  $"<<beverage->GetCost()<<endl;
	delete beverage;
	delete temp;
}
