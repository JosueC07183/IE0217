#include <iostream>
using namespace std;

class finca
{
private:
    /* data */
public:
    int num_Edificios;
    int edificio_Park;
    int edificio_Room;

    finca(int num_Edificios, int edificio_Park, int edificio_Room);
    ~finca();

    finca(){
    
    }

    void setNum_Edificio(int num_Edificios);
    int getNum_Edificio();

    void setNum_Edificio_Park(int edificio_Park);
    int getNum_Edificio_Park();

    void setNum_Edificio_Room(int edificio_Room);
    int getNum_Edificio_Room();




};



/*
finca::finca(){}

finca::~finca(){}*/
