#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Train {
private:
    string trainName;
    int trainNumber;
    string source;
    string destination;
    int seatsAvailable;
public:
    Train(string name, int number, string src, string dest, int seats)
        : trainName(name), trainNumber(number), source(src), destination(dest), seatsAvailable(seats) {}

    int getTrainNumber() const {
        return trainNumber;
    }

    string getSource() const {
        return source;
    }

    string getDestination() const {
        return destination;
    }

    int getSeatsAvailable() const {
        return seatsAvailable;
    }

    bool bookSeats(int numSeats) {
        if (seatsAvailable >= numSeats) {
            seatsAvailable -= numSeats;
            return true;
        }
        return false;
    }
};

class ReservationSystem {
private:
    vector<Train> trains;
public:
    void addTrain(const Train& train) {
        trains.push_back(train);
    }

    void displayTrains() const {
        cout << "Available Trains:\n";
        for (const auto& train : trains) {
            cout << "Train Name: " << train.getSource() << " to " << train.getDestination() << "\n";
            cout << "Train Number: " << train.getTrainNumber() << "\n";
            cout << "Seats Available: " << train.getSeatsAvailable() << "\n\n";
        }
    }

    bool makeReservation(int trainNumber, int numSeats) {
        for (auto& train : trains) {
            if (train.getTrainNumber() == trainNumber) {
                return train.bookSeats(numSeats);
            }
        }
        return false;
    }
};

int main() {
    ReservationSystem system;
    system.addTrain(Train("Express", 1234, "City A", "City B", 100));
    system.addTrain(Train("Fast Train", 5678, "City B", "City C", 50));
    system.addTrain(Train("Local", 91011, "City A", "City C", 200));

    system.displayTrains();

    int trainNumber, numSeats;
    cout << "Enter train number and number of seats to book: ";
    cin >> trainNumber >> numSeats;

    if (system.makeReservation(trainNumber, numSeats)) {
        cout << "Reservation successful!\n";
    } else {
        cout << "Failed to make reservation. Please try again later.\n";
    }

    return 0;
}
