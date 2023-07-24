#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> dis_list;

void time_accumulation(const std::vector<int>& time, std::vector<bool> status, bool torch, int dis = 0) {

    if (std::all_of(status.begin(), status.end(), [](bool s) { return s; })) {
        dis_list.push_back(dis);
        return;
    }

    if (torch == 0) {
        for (size_t i = 0; i < status.size(); ++i) {
            if (status[i] == 0) {
                for (size_t j = i + 1; j < status.size(); ++j) {
                    if (status[j] == 0) {

                        std::vector<bool> status_copy = status;
                        status_copy[i] = true;
                        status_copy[j] = true;

                        time_accumulation(time, status_copy, true, dis + std::max(time[i], time[j]));
                    }
                }
            }
        }
    }

    if (torch == 1) {
        for (size_t i = 0; i < status.size(); ++i) {
            if (status[i] == 1) {

                std::vector<bool> status_copy = status;
                status_copy[i] = false;

                time_accumulation(time, status_copy, false, dis + time[i]);
            }
        }
    }
}

int main() {
    std::vector<int> time = { 1, 2, 5, 10 };
    std::vector<bool> status(4, false);
    bool torch = false;

    time_accumulation(time, status, torch);

    for (int dis : dis_list) {
        std::cout << dis << " ";
    }
    std::cout << std::endl;

    return 0;
}
