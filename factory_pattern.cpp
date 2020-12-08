// Example program
#include <iostream>
#include <string>

class Fruit {
        public:
            virtual void tell();
            Fruit() {
                std::cout << " A Fruit is being created" << std::endl;
            }  // Constructor
            // ~Fruit(); // Destructor
    };
    
class Strawberry: public Fruit {
        public:
            
            void tell(){
                    std::cout << "hi";
                    
                }
    };


int main()
{
    Strawberry berry;
    berry.tell();
    return 0;
}
