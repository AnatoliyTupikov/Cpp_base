#include <iostream>
//#include <windows.h>

int main()
{
	//SetConsoleOutputCP(CP_UTF8);
	//SetConsoleCP(CP_UTF8);
	int n {1};
	int s {3};
	//std::string s{ "Nothing" };
	bool b = static_cast<bool>(std::cin >> n >> s);	
    std::cout << "Привет мир!\n" << "N var:" << n;
	std::cout << "S var:" << s << "\n";
}

//#include <iostream> 
//#include <chrono> 
//#include <thread> 
//int main()
//{
//	std::cout.sync_with_stdio(false);
//	std::cout << "this is " << std::endl;;
//	std::this_thread::sleep_for(std::chrono::seconds(10));
//	std::cout << "AAAA!!!" << std::endl;
//	return 0;
//}