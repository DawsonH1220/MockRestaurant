#include <iostream>
#include <iomanip>
#include <vector>

double tax(double, double);
int main() {
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Welcome to my restaurant" << std::endl;
	const double hotDogPrice{ 2.20 };
	const double hamburgerPrice{ 3.99 };
	const double friesPrice{ 1.99 };
	const double drinkPrice{ 1.00 };
	double taxRate{};
	std::vector<std::string> order{};
	std::cout << "1. Hot dog\n  " << hotDogPrice << "\n2. Hamburger\n  " << hamburgerPrice << "\n3. Fries\n  " << friesPrice << "\n4. Soft Drink\n  " << drinkPrice << "\n" << std::endl;
	bool done{ false };
	int choice1{};
	char choice2{};
	double total{};
	bool valid{ true };
	while (!done) {
		std::cout << "Enter selection: ";
		std::cin >> choice1;
		switch (choice1) {
		case 1: {
			total += hotDogPrice;
			order.push_back("Hot Dog");
			break;
		}
		case 2: {
			total += hamburgerPrice;
			order.push_back("Hamburger");
			break;
		}
		case 3: {
			total += friesPrice;
			order.push_back("Fries");
			break;
		}
		case 4: {
			total += drinkPrice;
			order.push_back("Soft Drink");
			break;
		}
		default: {
			std::cout << "Invalid input" << std::endl;
			break;
		}
		}
		std::cout << "Current total: " << total << std::endl;
		std::cout << "Current order: ";
		for (size_t i{}; i < order.size(); i++) {
			std::cout << order.at(i) << ", ";
		}
		std::cout << "\nHave you completed your order? (Y/N)" << std::endl;
		std::cin >> choice2;
		if (choice2 == 'Y' || choice2 == 'y') {
			done = true;
		}
	}
	std::cout << "Enter taxrate: ";
	std::cin >> taxRate;
	std::cout << "Total with tax: " << tax(total, taxRate) << std::endl;
	system("pause");
	return 0;

}

double tax(double price, double rate) {
	rate /= 100;
	rate += 1;
	return price * rate;
}