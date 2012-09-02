/*
 * NyStylePizzaStore.h
 *
 *  Created on: 2012-4-7
 *      Author: lfwu
 */

#ifndef NYSTYLEPIZZASTORE_H_
#define NYSTYLEPIZZASTORE_H_
#include "PizzaStore.h"
class Pizza;
class NyStylePizzaStore : public PizzaStore{
public:
	NyStylePizzaStore();
	virtual ~NyStylePizzaStore();
	virtual Pizza* CreatePizza(PizzaStore::PizzaType type);
};

#endif /* NYSTYLEPIZZASTORE_H_ */
