// Example program
#include <iostream>
#include <string>

int print(std::string input){
            std::cout << input << std::endl;
            return 0;
        }

class Fruit {
        public:
            static Fruit *harvest_fruit(int choice);

            virtual void information(){
                    print("This is my Fruit info");
                };
            virtual void plant_seeds() {
                    print("Planting seeds!");
                };
            Fruit() {
                std::cout << "A Fruit is being created" << std::endl;
            }  // Constructor
            // ~Fruit(); // Destructor
    };


class Strawberry: public Fruit {
        public:
            void plant_seeds() {
                    print("Seeds are dispersed from my flesh");
                }
    };

class Apple: public Fruit {
        public:
            void plant_seeds() {
                    print("Seeds are dispersed from my flesh");
                }
    };

class Melon: public Fruit {
        public:
            void plant_seeds() {
                    print("Seeds are dispersed from my flesh");
                }
    };

class Orange: public Fruit {
        public:
            void plant_seeds() {
                    print("Seeds are dispersed from my flesh");
                }
    };

enum Fruit_Types {
        apple = 1,
        strawberry = 2,
        melon = 3,
        orange = 4
    };

Fruit *Fruit::harvest_fruit(int choice) {
        switch (choice) {
            case apple:
                print("case 1");
                return new Apple;
            case strawberry:
                return new Strawberry;
            case melon:
                return new Melon;
            case orange:
                return new Orange;
            default:
                return new Apple;
        }

    }

int main()
{
    Strawberry berry;
    berry.plant_seeds();
    berry.information();
    return 0;
}
