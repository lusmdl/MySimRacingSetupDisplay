/**
 * @file main.cpp
 * @brief Main file for MySimRacingCore project.
 */

// libs

#include <Arduino.h>
#include <Wire.h>

// include
#include "ProjectConfig.hpp"

// source code modules

#include "Core/SetupDisplay.hpp"


// objects

SetupDisplay display;


// variables

unsigned int numberOfCycle  {0}; // count the cycles


// forward declaration of public functions

void loopFast();
void loopNormal();
void loopSlow();
void receiveEvent(int bytes);


/**
 * @brief Arduino setup function.
 * 
 * This function is called once when the Arduino starts.
 */
void setup() {
    
    Wire.begin(I2C_MY_ADDR);
    Wire.onReceive(receiveEvent);
    
    #ifdef LUSMDL_DEBUGMODE
    Serial.begin(9600);
    #endif

    display.begin();
}


/**
 * @brief Arduino loop function.
 * 
 * This function is called repeatedly in an infinite loop.
 */
void loop() {

    numberOfCycle++;
    
    if((numberOfCycle % TIME_FAST) == 0) {
        
        // here are task which has priority
        
        loopFast();
    }
    
    if((numberOfCycle % TIME_NORMAL) == 0) {
        
        // here are task which has no priority
        
        loopNormal();
    }
    
    if((numberOfCycle % TIME_SLOW) == 0) {
        
        // here are tasks which slow down the code
        
        loopSlow();
    }
}

void loopFast() {}

void loopNormal() {}

void loopSlow() {
    
    display.run();
}

void receiveEvent(int bytes) {

    uint8_t A;
    int B;

    if (bytes >= 3) {  // Sicherstellen, dass mindestens 3 Bytes ankommen (1 für A, 2 für B)

        A = Wire.read();  // Erstes Byte als uint8_t einlesen

        byte buffer[sizeof(int)];

        for (int i = 0; i < sizeof(int); i++) {

            buffer[i] = Wire.read();  // Die nächsten 2 Bytes für int lesen
        }
        memcpy(&B, buffer, sizeof(int));  // Byte-Array in int umwandeln

        #ifdef LUSMDL_DEBUGMODE
        Serial.print("Empfangen: A = ");
        Serial.print(A);
        Serial.print(", B = ");
        Serial.println(B);
        #endif

        display.setPage(A, B);
    }
    else {

        display.setPage(0,0);
    }
}