#include <iostream>;
#include <string>;
#include <fstream>;
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "ru"); //for using national language in console
    
    std::string line;
    std::string text;


	std::cout << "Enter text (Ctrl+Z to end input):\n";

	SetConsoleCP(1251); //set console to Russian code page to input Russian chars
	while (std::getline(std::cin, line)) { //read until EOF (Ctrl+Z)
		text += line + "\n";
    }
	SetConsoleCP(866); //set console back to original code page

    

    std::cout << "\nYou entered:\n" << text;

    std::ofstream out("input.txt", std::ios::out | std::ios::binary); //creat an object without new, because it is created on stack
    if (!out) {
        std::cout << "Can't open the file\n";
        return 1;
    }
	out.write(text.c_str(), text.size());

	return 0;
}