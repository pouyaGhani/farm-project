#include "alfalfa_land.h"

Alfalfa_land::Alfalfa_land()
{
}

void Alfalfa_land::Upgrade()
{
    if (store->Get_object(1)>=2 && user->Get_coin()>=5 && user->Get_level()>=4) {
        store->Delete(1, 2);         
        user->Set_coin(user->Get_coin()-5);

        // Qtimer

        // after Qtimer finished :

        user->Set_experience(user->Get_experience()+3);
        space*=2;
    }
    else { // not enough resources for upgrading

        if(store->Get_object(1)<2) {  } // shovel needed
        else if (user->Get_coin()<5) { } // coin needed
        else { } // level needed
    }
}

void Alfalfa_land::Plow(int tedad) 
{
    if(status==0) { // zamin bikar
        if(user->Get_coin()>=5*tedad && space>=tedad && user->Get_level()>=3){
            user->Set_coin(user->Get_coin()-(5*tedad));
            status=1;
            // Qtimer

            // after Qtimer finished :
            status=2;
            plowable=tedad;
            user->Set_experience(user->Get_experience()+tedad);
        }
        else { // not enough resources for upgrading
            if (user->Get_coin()<5*tedad) { } // coin needed
            else if(space<tedad) { } // We do not have enough space
            else { } // level needed
        }
    }
    else { // zamin ra nemi shavad shokm zad

    }
}

void Alfalfa_land::Cultivation(int tedad) {
    if(status==2) { // zamin shokm zade shode va amade zerat ast
        if(store->Get_object(3)>=tedad && plowable>=tedad &&user->Get_level()>=3){
            status=3;
            plowable-=tedad;
            user->Set_experience(user->Get_experience()+tedad*2);
            store->Delete(3,tedad);
            // Qtimer

            // after Qtimer finished :
            status=4;
            cultivated=tedad;
        }
        else { // not enough resources for upgrading
            if (user->Get_coin()<5*tedad) { } 
            else if(plowable<tedad) { } 
            else { } 
        }
    }
    else { // zamin dar vaziat digari ast

    }
}

void Alfalfa_land::Harvesting(int tedad){
    if(status==4){
        if(store->Add(3,tedad*2)==true && cultivated>=tedad){
            user->Set_experience(user->Get_experience()+tedad*2);
            cultivated-=tedad;
        }
        else{
            if (store->Add(3,tedad*2)==false) { } // kambod ja
            else { } // meghdar vared shde sahih nist
        }
        if(cultivated==0) status=0;
    }
    else { // zamin dar vaziat digari ast

    }
}

void Alfalfa_land::Making(){
    if(user->Get_level()>=3){
        if(user->Get_coin()>=15){
            if(store->Get_object(1)>=1){
                if(store->Get_object(2)>=1){
                    user->Set_coin(user->Get_coin()-15);
                    store->Delete(1,1);
                    store->Delete(2,1);
                    // Qtimer

                    //
                    user->Set_experience(user->Get_experience()+6);
                    is_active=true;
                }
                else {}
            }
            else{}
        }
        else{}
    }
    else {}

}
