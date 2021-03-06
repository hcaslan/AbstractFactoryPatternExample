#include <stdexcept>
#include <iostream>
#include <memory>

class Pizza {
public:
	virtual int getPrice() const = 0;
	virtual ~Pizza() {};
};
//pizza nesnesinin i?eri?ini de?i?tirmek i?in olu?turulan alt s?n?flar
class HamAndMushroomPizza : public Pizza {
public:
	virtual int getPrice() const { return 850; };
	virtual ~HamAndMushroomPizza() {};
};

class DeluxePizza : public Pizza {
public:
	virtual int getPrice() const { return 1050; };
	virtual ~DeluxePizza() {};
};

class HawaiianPizza : public Pizza {
public:
	virtual int getPrice() const { return 1150; };
	virtual ~HawaiianPizza() {};
};

class PizzaFactory {
public:
	enum PizzaType {
		HamMushroom,
		Deluxe,
		Hawaiian
	};

	static std::unique_ptr<Pizza> createPizza(PizzaType pizzaType) {
		switch (pizzaType) {
		case HamMushroom: return std::make_unique<HamAndMushroomPizza>();
		case Deluxe:      return std::make_unique<DeluxePizza>();
		case Hawaiian:    return std::make_unique<HawaiianPizza>();
		}
		throw "invalid pizza type.";
	}
};

/*
* B?t?n pizza t?rlerini olu?turur ve fiyatlar?n? basar
*/
void pizza_information(PizzaFactory::PizzaType pizzatype)
{
	std::unique_ptr<Pizza> pizza = PizzaFactory::createPizza(pizzatype);
	std::cout << "Price of " << pizzatype << " is " << pizza->getPrice() << std::endl;
}

int main()
{
	pizza_information(PizzaFactory::HamMushroom);
	pizza_information(PizzaFactory::Deluxe);
	pizza_information(PizzaFactory::Hawaiian);
}
