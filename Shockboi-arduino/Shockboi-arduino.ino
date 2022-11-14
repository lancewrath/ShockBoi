//#define USEAPI
//#define USE_TWITCH
#define USE_SERIAL
#ifdef USEAPI
#include <Arduino_JSON.h>

#ifdef USE_TWITCH
#include <Create Twitch Library here>
#endif

#endif



#define relayPin 11


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
        case TRUE:
            digitalWrite(relayPin,HIGH);
        break;
        case FALSE:
            digitalWrite(relayPin,LOW);
        break;

    }
}

void handleSerial()
{
#ifdef USE_SERIAL
    while (Serial.available() > 0) 
    {
        char incomingCharacter = serial.Read();
        switch (incomingCharacter) 
        {
            case '+':
            relaycontrol(TRUE);
            break;

            case '-':
            relaycontrol(FALSE);
            break;
        }
    }
#endif
}