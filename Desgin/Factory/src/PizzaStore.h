/*
 * PizzaStore.h
 *
 *  Created on: 2012-4-7
 *      Author: lfwu
 */

#ifndef PIZZASTORE_H_
#define PIZZASTORE_H_
class Pizza;
class PizzaStore {
public:
	enum PizzaType
	{
		CHEESE,
		PEPPERONI,
		CLAM,
		VEGGIE
	};
	PizzaStore();
	virtual ~PizzaStore();
	virtual Pizza* OrderPizza(PizzaType type);
	virtual Pizza* CreatePizza(PizzaType type) = 0;
protected:
	Pizza* pizza_;
};

#endif /* PIZZASTORE_H_ */
