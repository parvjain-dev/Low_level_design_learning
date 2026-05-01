#include <iostream>
#include <string>

using namespace std;

class Car{
    public:
        virtual void startEngine()=0;// only declaring thats what virtual is here for. 
        virtual void shiftGear(int gear)=0;
        virtual void accelerate()=0;
        virtual void brake()=0;
        virtual void stopEngine()=0;
        virtual ~Car() {}
};

class SportsCar : public Car{
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    SportsCar(string b, string m){
        this->brand= b;
        this-> model= m;
        isEngineOn=false;
        currentSpeed=0;
        currentGear=0;
    }
    void startEngine(){
        isEngineOn=true;
        cout<<brand<<" "<<model<<" "<<"Engine is on !"<<endl;
    }
    void shiftGear(int gear){
        if(!isEngineOn){
            cout<<"Kindly start the engine"<<endl;

        }
        currentGear = gear;
        cout << "shifted to gear: " << currentGear << endl;
    }
    void accelerate(){
        if (!isEngineOn)
        {
            cout << "Kindly start the engine" << endl;
        }
        currentSpeed = currentSpeed + 20;
        cout << "you are accelerating , you current speed is: " << currentSpeed << endl;
    }
    void brake(){
        currentSpeed = currentSpeed - 20;
        if(currentSpeed<0) currentSpeed=0;
        cout << "you are braking , you current speed is: " << currentSpeed << endl;
    }
    void stopEngine(){
        if(isEngineOn){
            isEngineOn=false;

        }
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << "your car is off" << endl;
    }
};

int main(){
    Car* mycar= new SportsCar("BMW","M4");
    mycar->startEngine();
    mycar->accelerate();
    mycar->shiftGear(2);
    mycar->accelerate();
    mycar->shiftGear(3);
    mycar->brake();
    mycar->stopEngine();
    mycar->~Car();
    return 0;
}