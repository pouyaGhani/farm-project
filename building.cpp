#include "building.h"

Building::Building()
{

}

void Building::Set_total_storage(int _total_storage){
    total_storage = _total_storage;
}

int Building::Get_total_storage(){
    return total_storage;
}

int Building::Get_used_storage(){
    return used_storage;
}
