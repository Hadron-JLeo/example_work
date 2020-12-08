// Example program
#include <iostream>
#include <string>

int print(std::string input){
            std::cout << input << std::endl;
            return 0;
        }

class Fruit {
        public:
            virtual void information(){
                    print("This is my Fruit info");
                };
            virtual void plant_seeds() {
                    print("Planting seeds!");
                };
            Fruit() {
                std::cout << " A Fruit is being created" << std::endl;
            }  // Constructor
            // ~Fruit(); // Destructor
    };


class Strawberry: public Fruit {
        public:
            
        
    };

int main()
{
    Strawberry berry;
    berry.plant_seeds();
    berry.information();
    return 0;
}
