#include <iostream>
#include <string>

using namespace std;

class Car
{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
public:
    Car(string a, string b){
        this->brand= a;
        this->model=b;
        isEngineOn=false;
        currentSpeed=0;
    }
    virtual void startEngine(){
        cout<<"Starting engine"<<endl;
    } // only declaring thats what virtual is here for.
   
    virtual ~Car() {}
};

class MannualCar: public Car{
    private:
        int currentGear;
    public:
        MannualCar(string a, string b): Car(a,b) {
            this->currentGear=0;
        }
        void shiftGear(int gear){
            currentGear= gear;
            cout<<currentGear;
        }
};

int main()
{
    MannualCar* wagnor = new MannualCar("ford","mustang");
    
    
    return 0;
}