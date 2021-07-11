#include "wheat_land.h"

Wheat_land::Wheat_land()
{
}

void Wheat_land::Upgrade() 
{
    if (store->Get_object(1)>=1 && user->Get_coin()>=5 && user->Get_level()>=2) {
        store->Delete(1, 1);         
        user->Set_coin(user->Get_coin()-5);

        // Qtimer

        // after Qtimer finished :

        user->Set_experience(user->Get_experience()+3);
        space*=2;
    }
    else { // not enough resources for upgrading

        if(store->Get_object(1)<1) {  } // shovel needed
        else if (user->Get_coin()<5) { } // coin needed
        else { } // level needed
    }
}

void Wheat_land::Cultivation(int tedad) {
    if(status==0){
        if(silo->Get_wheat()>=tedad && space>=tedad){
            status=1;
            user->Set_experience(user->Get_experience()+tedad);
            silo->Delete(1,tedad);
            // Qtimer

            // after Qtimer finished :
            status=2;
            cultivated=tedad;
        }
        else {
            if (silo->Get_wheat()<tedad) { }
            else { }
        }
    }
    else {

    }
}

void Wheat_land::Harvesting(int tedad){
    if(status==2){
        if(cultivated>=tedad && silo->Add(1,2*tedad)==true){
              user->Set_experience(user->Get_experience()+tedad);
              cultivated-=tedad;
        }

      else {
          if (silo->Add(1,2*tedad)==false) { } // kambod ja
          else { } // meghdar vared shde sahih nist
      }
      if(cultivated==0) status=0;
   }
  else { // zamin dar vaziat digari ast

  }
}
