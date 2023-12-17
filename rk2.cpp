#include <iostream>
#include <list>
#include <memory>

class Vehicle {
protected:
    std::string brand;
    std::string model;

public:
    Vehicle(const std::string& brand, const std::string& model)
        : brand(brand), model(model) {}

    virtual void display() const {
        std::cout << "Brand: " << brand << ", Model: " << model << std::endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(const std::string& brand, const std::string& model, int numDoors)
        : Vehicle(brand, model), numDoors(numDoors) {}

    void display() const override {
        Vehicle::display();
        std::cout << "Number of Doors: " << numDoors << std::endl;
    }
};

class Motorcycle : public Vehicle {
private:
    std::string type;

public:
    Motorcycle(const std::string& brand, const std::string& model, const std::string& type)
        : Vehicle(brand, model), type(type) {}

    void display() const override {
        Vehicle::display();
        std::cout << "Type: " << type << std::endl;
    }
};

// Функция для изменения характеристик любого транспортного средства
void modifyVehicle(Vehicle* vehicle) {
    // В данном примере функция ничего не делает, можно добавить логику изменений
}

int main() {
    // Создание контейнера для хранения указателей на объекты классов Vehicle
    std::list<std::unique_ptr<Vehicle>> vehicles;

    // Добавление объектов Car и Motorcycle в контейнер
    vehicles.push_back(std::make_unique<Car>("Toyota", "Camry", 4));
    vehicles.push_back(std::make_unique<Motorcycle>("Scoda", "Octavia", "Sport"));

    // Вывод информации о каждом транспортном средстве с использованием итераторов STL
    for (const auto& vehicle : vehicles) {
        vehicle->display();
    }

    // Применение функции для изменения характеристик транспортного средства
    for (const auto& vehicle : vehicles) {
        modifyVehicle(vehicle.get());
    }

    return 0;
}
