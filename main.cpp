#include <algorithm>
#include <iostream>
#include <vector>

struct Task {
    int deadline;
    double value;
};

double solve(std::vector<Task> tasks) {
    double result = 0;

    std::sort(tasks.begin(), tasks.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.value > rhs.value;
    });

    // Vector of "slots". 0 if no tasks scheduled for this slot, 1 otherwise
    std::vector<bool> dates(tasks.size());

    // Initialize it with all 0 (no tasks selected yet)
    std::fill(dates.begin(), dates.end(), 0);

    // Algorithm idea:
    // Select the most worth task and schedule it to the latest possible slot
    // (deadline <= slot)
    for (const auto& task : tasks) {
        int date_being_checked = task.deadline;
        while (date_being_checked >= 1) {
            // If slot (date) available:
            if (!dates[date_being_checked]) {
                dates[date_being_checked] = true;
                result += task.value;
                break;
            }

            // Else try previous slot (date)
            date_being_checked--;
        }
    }

    return result;
}

int main() {
    int N;  // Number of tasks to be inputed
    std::cin >> N;

    std::vector<Task> tasks;
    while (N--) {
        int deadline;
        std::cin >> deadline;

        tasks.push_back(Task{deadline});
    }
    for (auto& task : tasks) {
        double value;
        std::cin >> value;

        task.value = value;
    }

    std::cout << solve(tasks) << std::endl;
}