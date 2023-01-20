#include "MicroBit.h"
MicroBit uBit;
//define function prototyp
void piep(int modi, int dauer);
int main(){
    //initialise
    uBit.init();
    int toreTeam1 = 0;
    int buttonA = 0;
    int buttonB = 0;
    int buttonAB = 0;
    bool notBlockedA = true;
    bool notBlockedB = true;
    bool notBlockedAB = true;
    while(1){
        while(uBit.buttonA.isPressed()){
            //BUTTON Count down
            buttonA = 1;
            buttonB = 0;
            notBlockedA = true;
        }
        while(uBit.buttonB.isPressed()){
            //BUTTON Count up
            buttonA = 0;
            buttonB = 1;
            notBlockedB = true;
        }
        uBit.sleep(100);
        while(uBit.buttonAB.isPressed()){
            //reset BUTTON
            buttonA = 0;
            buttonB = 0;
            buttonAB = 1;
            notBlockedAB = true;
            uBit.sleep(200);
        }
        //write score to value toreTeam1
        if(toreTeam1 > 0 && buttonA == 1 && notBlockedA){
            //only count down if not already 0
            toreTeam1 = toreTeam1 - buttonA;
            buttonA = 0;
            notBlockedA = false;
        }else if(buttonAB == 1 && notBlockedAB){
            //reset score to 0 if buttonAB =1
            toreTeam1 = 0;
            buttonAB = 0;
            notBlockedAB = false;
        }else if(toreTeam1 < 9 && buttonB == 1 && notBlockedB){
            //only count up if score is not already 9
            toreTeam1 = toreTeam1 + buttonB;
            buttonB = 0;
            notBlockedB = false;
        }else if(toreTeam1 == 9 && buttonB == 1 && notBlockedB){
            //if score already 9 and you score, you win, put score back to 0 and do soundeffect
            toreTeam1 = 0;
            buttonB = 0;
            notBlockedB = false;
            piep(1, 200);
        }
        //display score with value toreTeam1
        uBit.display.print(toreTeam1);
        uBit.sleep(3);
    }
}
//set values for piep
void piep(int modi, int dauer){
    uBit.io.P0.isAnalog();
    uBit.io.P0.isOutput();
    if(modi == 1){
        uBit.io.P0.setAnalogValue(1000);
        uBit.io.P0.setAnalogPeriod(10);
    }
    uBit.sleep(dauer);
    uBit.io.P0.setAnalogValue(0);
    uBit.io.P0.setAnalogPeriod(0);
}