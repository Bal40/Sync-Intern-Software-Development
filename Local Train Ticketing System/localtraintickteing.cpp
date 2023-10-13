#include <iostream>
#include <string>
#include <vector>

struct TrainSchedule {
    std::string source;
    std::string destination;
    std::string time;
    double fare;
};

struct UserAccount {
    std::string username;
    std::string password;
    double balance;
};

TrainSchedule findTrain(const std::vector<TrainSchedule>& schedules, const std::string& source, const std::string& destination) {
    for (const TrainSchedule& schedule : schedules) {
        if (schedule.source == source && schedule.destination == destination) {
            return schedule;
        }
    }
    throw std::runtime_error("Train schedule not found.");
}

void bookTicket(UserAccount& user, const TrainSchedule& schedule, int numPassengers) {
    double totalFare = schedule.fare * numPassengers;
    if (user.balance < totalFare) {
        std::cout << "Insufficient balance. Please add funds to your account." << std::endl;
        return;
    }

    user.balance -= totalFare;
    std::cout << "Ticket booked successfully. Total fare: " << totalFare << std::endl;
}

int main() {
    std::vector<TrainSchedule> schedules = {
        { "Station A", "Station B", "09:00 AM", 10.0 },
        { "Station B", "Station C", "11:30 AM", 15.0 }
    };

    UserAccount user = { "username", "password", 100.0 };

    std::cout << "Welcome to the Train Ticketing System" << std::endl;

    std::string source, destination;
    int numPassengers;

    std::cout << "Enter source station: ";
    std::cin >> source;
    std::cout << "Enter destination station: ";
    std::cin >> destination;
    std::cout << "Enter number of passengers: ";
    std::cin >> numPassengers;

    try {
        TrainSchedule schedule = findTrain(schedules, source, destination);
        bookTicket(user, schedule, numPassengers);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
