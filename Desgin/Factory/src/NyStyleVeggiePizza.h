/*
 * NyStyleVeggiePizza.h
 *
 *  Created on: 2012-4-7
 *      Author: lfwu
 */

#ifndef NYSTYLEVEGGIEPIZZA_H_
#define NYSTYLEVEGGIEPIZZA_H_
#include "Pizza.h"
class NyStyleVeggiePizza : public Pizza{
public:
	NyStyleVeggiePizza();
	virtual ~NyStyleVeggiePizza();
	virtual std::string GetPizzaName();
};

#endif /* NYSTYLEVEGGIEPIZZA_H_ */
