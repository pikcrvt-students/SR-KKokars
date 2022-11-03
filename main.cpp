#include <iostream>
#include "player_inp.h"
#include <chrono>

int main() {
    bool quit = false;
    bool gen = true;
    int score;
    int p_x = 19;
    int p_y = 10;
    int level = 0;
    std::srand(time(nullptr));
    char map[21][21];
    int spike_chance;
    int zelts = 0;
    auto start = std::chrono::steady_clock::now();
    while (!quit) {
        if (gen) {
            auto start = std::chrono::steady_clock::now();
            gen = false;
            spike_chance = 3;
            for (int x = 0; x < 21; x++) {
                for (int y = 0; y < 21; y++) {
                    if (x == 0 || x == 20 || y == 0 || y == 20) {
                        if (y == 10 && x == 0)
                            map[x][y] = '*';
                        else
                            map[x][y] = '#';
                    }
                    else if (rand() % 60 - level <= spike_chance && (x != 1 || y != 10) && (x != 19 || y != 10))
                        map[x][y] = '/';

                    else if (rand() % 100 - level <= 3)
                        map[x][y] = '$';

                    else
                        map[x][y] = '.';
                }
            }
        }
        for (int x = 0; x < 21; x++) {
            for (int y = 0; y < 21; y++) {
                if (x == p_x && y == p_y) {
                    if (map[p_x][p_y] == '/')
                        quit = true;
                    else if (map[x][y] == '$') {
                        map[x][y] = '.';
                        zelts += 3;
                    }
                    std::cout << '@';
                }
                else
                    std::cout << map[x][y];
            }
            std::cout << std::endl;
        }
        auto end = std::chrono::steady_clock::now();
        double elapsed = double (std::chrono::duration_cast<std::chrono::seconds> (end - start).count());
        std::cout << elapsed << " / 30 sec";
        player_inp(&quit, &p_x, &p_y, &gen, &level);
        system("cls");
        if (elapsed > 30)
            quit = true;
    }
    score = level^3 + zelts;
    std::cout << "GAME ENDED, YOUR SCORE: " << score << std::endl;
    std::cin >> level;
    return 0;
};
