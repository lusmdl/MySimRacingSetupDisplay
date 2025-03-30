
#ifndef SETUP_DISPLAY_HPP
#define SETUP_DISPLAY_HPP

#include "ProjectConfig.hpp"
#include <LiquidCrystal_I2C.h>
#include <avr/delay.h>
#include "TextBoxes.h"

class SetupDisplay {

    public:

        SetupDisplay();
        ~SetupDisplay();
        void begin();
        void run();
        void dark();

    private:
        LiquidCrystal_I2C *lcd_;

        uint8_t page_;

        void clearLine(uint8_t line);
        void printLine(uint8_t line, String txt);

        // pages

        void setupRxMax();
        void setupRxMin();
        void setupRyMax();
        void setupRyMin();
        void setupSteeringZero();
        void setupSteeringTurn();
        void setupThrottleMax();
        void setupThrottleMin();
        void setupBrakeMax();
        void setupBrakeMin();

};






#endif