/*
 * Pizza.h
 *
 *  Created on: 2012-4-18
 *      Author: lfwu
 */

#ifndef PIZZA_H_
#define PIZZA_H_
#include <iostream>
class Dough;
class Sauce;
class Chesse;
class Clam;
class Pizza {
public:
	Pizza();
	virtual ~Pizza();
	void SetName(std::string name);
	std::string GetName();
	virtual void Parpare() = 0;
	void Bake();
	void Cut();
	void Box();
private:
	std::string name_;
	Dough* dough_;
	Sauce* sauce_;
	Chesse* chesse_;
	Clam* clam_;
};

#endif /* PIZZA_H_ */
