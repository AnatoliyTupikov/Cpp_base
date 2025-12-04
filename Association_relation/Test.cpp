#include <iostream>
#include <string>
#include <fstream> 

#include <sstream>
#include <thread>
#include <chrono>


int main() 
{

	//std::string str = "Hello world!"; //немного поменяли инфу в потоке
	//std::string test;
	//std::string test2;;
	//std::string test3;
	//
	//std::stringstream ss(str);
	//ss >> test; //здесь считывание произошло до H, не включительно
	//std::cout << test << std::endl;	// 123
	//std::cout << "Good" << ss.good() << std::endl; //1
	//std::cout << "EOF" << ss.eof() << std::endl; //0
	//std::cout << "Fail" << ss.fail() << std::endl;//0
	//std::cout << "Stream to bool" << static_cast<bool>(ss) << std::endl;
	//std::cout << "===============test==================" << std::endl;
	//ss >> test2; //здесь мы продолжаем считывание с того же потока, а значит с того же места
	//std::cout << test2 << std::endl; //0 - дефолтное значение для int, данные не были переданы в переменную, считавание закончилось сразу
	//std::cout << "Good" << ss.good() << std::endl; //0
	//std::cout << "EOF" << ss.eof() << std::endl; //0
	//std::cout << "Fail" << ss.fail() << std::endl; //1
	//std::cout << "Stream to bool" << static_cast<bool>(ss) << std::endl; 
	//std::cout << "===============test2==================" << std::endl;
	////примерно здесь закончился пример выше
	////ss.clear(); //сброс флагов ошибок
	//ss >> test3; //эта операция не была выполнена. Нет исключения не возникнет, просто, никакого эффекта не будет
	//std::cout << test3 << std::endl; // ничего
	//std::cout << "Good" << ss.good() << std::endl; //0
	//std::cout << "EOF" << ss.eof() << std::endl; //0
	//std::cout << "Fail" << ss.fail() << std::endl; //1
	//std::cout << "Stream to bool" << static_cast<bool>(ss) << std::endl;
	//std::cout << "===============test3==================" << std::endl;
	
	
	std::ofstream file;
	file.open("example.txt", std::ios::binary);
	if (!file.is_open())
	{
		std::cout << "error opening file" << std::endl;
		return 1;
	}
	const int aSIZE = 5;
	int a[aSIZE] = {1, 2, 3, 4, 5};

	file.write(reinterpret_cast<char*>(&a), sizeof(a));	
	file.close();

	std::ifstream fin; 
	fin.open("example.txt", std::ios::binary);

	if (!fin.is_open()) //check if file is open
	{ 
		std::cout << "File open error" << std::endl; 
		return 1;
	}
	

	int b[5];
	fin.read(reinterpret_cast<char*>(&b), sizeof(b));
	std::cout << "b3 = " << b[3] << std::endl;
		
	
	





	return 0;
}