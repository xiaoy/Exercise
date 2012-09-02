//============================================================================
// Name        : Factory.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "PizzaStore.h"
#include "NyStylePizzaStore.h"
#include "Pizza.h"
#include <iostream>
int main() {
	PizzaStore *store = new NyStylePizzaStore;
	Pizza* pizza = store->OrderPizza(PizzaStore::VEGGIE);
	std::cout<<pizza->GetPizzaName()<<"\n";
}
