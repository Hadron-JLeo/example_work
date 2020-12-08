// Example program
#include <iostream>
#include <string>
#include <vector>


int print(std::string input){
            std::cout << input << std::endl;
            return 0;
        }

class Fruit {
        public:
            virtual void information() { print("This is my Fruit info"); };
            virtual void plant_seeds() { print("Planting seeds!"); };
            
            Fruit() { 
                // Constructor
                std::cout << "A Fruit is being created" << std::endl;
            }  
            
            virtual ~Fruit() {
                // Destructor    
                std::cout << "A Fruit is thrown away!" << std::endl;
            } 
            
        protected:
            std::string name;
            std::string color;
    };

class Apple: public Fruit {
        public:
            Apple() {
                name = "Apple";
                color = "red";
            }
            
            void plant_seeds() override {
                    print(name + ": " + "A few seeds are in my core");
                    //print(name);
            }
            
    };

class Strawberry: public Fruit {
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
            Orange() {
                name = "Orange";
                color = "orange";
            }
            
            void plant_seeds() {
                    print(name + ": " + "I have lots of seeds spread around in my flesh");
                }
    };

enum Fruit_Types {
        apple = 1,
        strawberry = 2,
        melon = 3,
        orange = 4
    };


class Factory {
        
        public:        
            virtual Fruit* harvest_fruit(int choice);

    };

Fruit *Factory::harvest_fruit(int choice) {
        switch (choice) {
            case apple:
                print("hi");
                return new Apple();
            case strawberry:
                return new Strawberry;
            case melon:
                return new Melon;
            case orange:
                return new Orange();
            default:
                return new Apple();
        }

    }

int main()
{
    
    std::vector<Fruit*> fruits; 
    Factory factory;
    
    Fruit* apple1 = factory.harvest_fruit(apple);
    apple1->plant_seeds();
    
    Fruit* orange1 = factory.harvest_fruit(orange);
    orange1->plant_seeds();
    
    return 0;
}

// --------------- ################ NOTES ################ --------------- //
// std::vector<Fruit*> fruits; // -- Alternative to an array
// fruits.push_back(factory.harvest_fruit(apple)); -- add a fruit to the vector
// fruits[0] reference to a specific fruit
// --------------- ################ NOTES ################ --------------- //


