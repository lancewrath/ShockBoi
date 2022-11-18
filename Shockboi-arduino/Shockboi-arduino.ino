//#define USEAPI
//#define USE_TWITCH
#define USE_SERIAL
#ifdef USEAPI
#include <Arduino_JSON.h>

#ifdef USE_TWITCH
#include <Create Twitch Library here>
#endif

#endif



#define relayPin 4


void setup()
{
    pinMode(relayPin,OUTPUT);
    #ifdef USE_SERIAL
        Serial.begin(9600);
    #endif
}




void loop()
{
    handleSerial();
}

void relaycontrol(bool val)
{
    switch(val)
    {
        case true:
            digitalWrite(relayPin,HIGH);
        break;
        case false:
            digitalWrite(relayPin,LOW);
        break;

    }
}

void handleSerial()
{
#ifdef USE_SERIAL
    while (Serial.available() > 0) 
    {
        char incomingCharacter = Serial.read();
        switch (incomingCharacter) 
        {
            case '+':
            relaycontrol(true);
            break;

            case '-':
            relaycontrol(false);
            break;
        }
    }
#endif
}
