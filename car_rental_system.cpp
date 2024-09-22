#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Car {
public:
string brand;
string model;
int year;
double dailyRate;
bool available;
Car(string b, string m, int y, double d)
{
brand=b;
model=m;
year=y;
dailyRate=d;
available=true;
}
};
class CarRentalSystem {
private:
vector<Car>cars;
public:
void addCar(string brand, string model, int year, double dailyRate) {
cars.push_back(Car(brand, model, year, dailyRate));
}
void rentCar(int index) {
if (index >= 0 && index < cars.size() && cars[index].available) {
cars[index].available = false;
cout << "\n\t|You have rented the " << cars[index].brand << " " <<
cars[index].model << ".|\n" << endl;
} else {
cout << "Car not available for rent." << endl;
}
}
void returnCar(int index) {
if (index >= 0 && index < cars.size() && !cars[index].available) {
cars[index].available = true;
cout << "\n\t|You have returned the " << cars[index-1].brand << " " <<
cars[index].model << ".|\n" << endl;
} else {
cout << "Invalid car or car is already available." << endl;
}
}
void displayAvailableCars() {
cout<<"-----------------------------------------------\n";
cout << "\t\tAvailable Cars:" << endl;
cout<<"-----------------------------------------------\n";
for (int i = 0; i < cars.size(); ++i) {
if (cars[i].available) {
cout << i << ". " << cars[i].brand << " " << cars[i].model << " (Year: " <<
cars[i].year << ", Daily Rate: Rs." << cars[i].dailyRate << ")" << endl;
}
}
}
};
int main() {
CarRentalSystem rentalSystem;
rentalSystem.addCar("Toyota", "Camry", 2020, 5000);
rentalSystem.addCar("Honda", "Civic", 2019, 4500);
rentalSystem.addCar("Ford", "Focus", 2021, 5500);
rentalSystem.addCar("Tata", "Nexus", 2022, 6000);
rentalSystem.addCar("Tata", "Nano",2020,2000);
int choice;
cout<<"\t\t\t\t\t\t\t|CAR RENTAL SYSTEM|"<<endl;
do {
cout<<"--------------------------------\n";
cout << "Car Rental System Menu:\n";
cout<<"--------------------------------\n";
cout << "1. Rent a Car\n";
cout << "2. Return a Car\n";
cout << "3. Display Available Cars\n";
cout << "4. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
rentalSystem.displayAvailableCars();
cout << "Enter the index of the car you want to rent: ";
int rentIndex;
cin >> rentIndex;
rentalSystem.rentCar(rentIndex);
break;
case 2:
cout << "Enter the index of the car you want to return: ";
int ret;
cin >> ret;
rentalSystem.returnCar(ret);
break;
case 3:
rentalSystem.displayAvailableCars();
break;
case 4:
cout << "\nExiting the Car Rental System. Goodbye!\n" << endl;
break;
default:
cout << "Invalid choice. Please try again." << endl;
}
}
while (choice != 4);
return 0;}