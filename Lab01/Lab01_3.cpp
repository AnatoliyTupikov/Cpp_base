// Lab01_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <numbers>
#include <cmath>
#include <fmt/core.h>
#include <string> 
int main() {
	int x = 42;

	std::string name = "Alice";
	// Печать с форматированием 
	fmt::print("Hello, {}, the answer is {}!\n", name, x);
	fmt::print("Hex: {:#x}\n", x);
	fmt::print("|{:>10}|\n", 42);  // выравнивание вправо 
	fmt::print("|{:<10}|\n", 42);  // выравнивание влево 
	fmt::print("|{:^10}|\n", 42);  // выравнивание по центру
	fmt::print("Fixed: {:.2f}\n", M_PI);  // 2 знака после запятой 
	fmt::print("Scientific: {:.3e}\n", M_PI); // экспоненциальный формат
	
	std::string s = fmt::format("Pi ≈ {:.3f}", 3.14159);//форматирование без вывода
	fmt::print("{}\n", s);
	return 0;
}

