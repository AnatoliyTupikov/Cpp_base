

#include <iostream>
#include <map>
#include <vector>
#include <fmt/core.h>
#include <random>
#include <string>

int main()
{

    std::cout << "Game start! \nYou have to get 50 points.\n";
    int count{5};
	//std::cin >> count;
	std::random_device rd;  // случайное зерно от ОС
	std::mt19937 gen(rd()); // генератор (Mersenne Twister)
	std::uniform_int_distribution<> dist(-1, 1);
	std::uniform_int_distribution<> trg_dist(-3, 3);

    std::map<std::string, int> center;
	center["x"] = trg_dist(gen);
	center["y"] = trg_dist(gen);

	fmt::print("Target has rundom center's coordinates! \n");
	std::vector <std::pair<int, int>> zones; //radius, score
	zones.emplace_back(1, 10);
	zones.emplace_back(2, 5);
	zones.emplace_back(3, 1);
	int score{ 0 };
	

	
	int i{ 0 };
    while ( score <= 50)
    {
        int x{ 0 }, y { 0 };
        std::cout << "Specify shoot coordinates (format: x y) -> ";
		std::cin >> x >> y;
		x += dist(gen);
		y += dist(gen);

		int dist = (x - center["x"]) * (x - center["x"]) + (y - center["y"]) * (y - center["y"]);
		for (auto zone : zones) {
			if (dist <= zone.first * zone.first) {
				fmt::print("Shoot{num} x:{}, y:{} - {} score\n", x, y, zone.second);
				score += zone.second;
				break;
			}
			if (zone == zones.back()) {
				fmt::print( "Out of the target! \nShoot: x:{}, y:{} - 0 score\n",x, y );
			}
		}
		i++;
	}
	std::string level = (i <= 10) ? "\"Sniper\"" : (i <= 15) ? "\"Gunslinger\"" : "\"Beginner\"";
	
	fmt::print("Game over! Your total score is: {}\n", score);
	fmt::print("Count of shoots: {}. Your level is {}", i, level);



}


