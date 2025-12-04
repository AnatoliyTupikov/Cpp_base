

#include <iostream>

int reFun(int n, int k = 1)
{
    if (n == 0) return 0;
    int res = n * k;
	return res + reFun(n - 1, k);
}

int main()
{
	std::cout << reFun(3, 5) << std::endl;
}


