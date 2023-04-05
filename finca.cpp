#include <iostream>
using namespace std;
#include "finca.hpp"

finca::finca(int num_Edificios, int edificio_Park, int edificio_Room){
    this-> num_Edificios=num_Edificios;
    this->edificio_Park=edificio_Park;
    this->edificio_Room=edificio_Room;
}

void finca::setNum_Edificio(int num_Edificios){
     this-> num_Edificios=num_Edificios;
}

int finca::getNum_Edificio(){
    return num_Edificios;
}

void finca::setNum_Edificio_Park(int edificio_Park){
     this-> edificio_Park=edificio_Park;
}

int finca::getNum_Edificio_Park(){
    return edificio_Park;
}

void finca::setNum_Edificio_Room(int edificio_Room){
     this-> edificio_Room=edificio_Room;
}

int finca::getNum_Edificio_Room(){
    return edificio_Room;
}
finca::~finca(){

}