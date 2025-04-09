#include "SetupDisplay.hpp"


SetupDisplay::SetupDisplay():
    page_(0)
{}


SetupDisplay::~SetupDisplay() {}


void SetupDisplay::begin() {

    // initialize the library by associating any needed LCD interface pin
    // with the arduino pin number it is connected to
    lcd_ = new LiquidCrystal(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

    // set up the LCD's number of columns and rows:
    lcd_->begin(16, 2);
    // Print a message to the LCD.
    lcd_->print("hello, world!");

    pinMode(LCD_BACKLIGHT, OUTPUT);
    digitalWrite(LCD_BACKLIGHT, HIGH);
}

void SetupDisplay::clearLine(uint8_t line) {

    lcd_->setCursor(0,line);
    lcd_->print(TXT_CLEAR);
}


void SetupDisplay::printLine(uint8_t line, String txt) {

    lcd_->setCursor(0, line);
    String data = txt.substring(0, LCD_CHARS); // truncate to 16 characters if longer
    while (data.length() < LCD_CHARS) { // pad with spaces if shorter
        data += " ";
    }
    lcd_->print(data);
}

void SetupDisplay::dark() {

    digitalWrite(LCD_BACKLIGHT, LOW);
}

void SetupDisplay::setPage(uint8_t first_line, int second_line) {

    page_ = first_line;
    value_ = second_line;
}

void SetupDisplay::run() {

    printLine(0, "Page: " + String(page_));
    printLine(1, "Value: " + String(value_));

    switch (page_) {

    case 255:
        dark();
        break;
    
    default:
        break;
    }
}

























/*
uint8_t SetupDisplay::runSetup() {
    
switch (page_) {
    
case 0 :
setupSteeringZero();
break;

case 1 : // ask user, if want´s to make setup wizard
if(askForSetup()) {
    
// begin with wizard

clearLine(0);
clearLine(1);

page_++;
}
else {
    
// no setup needed
return 0;
}
break;

case 2 : // Rotary X Axis
setupRxMax();            
break;

case 3 : // Rotary X Axis
setupRxMin();
break;

case 4 : // Rotary Y Axis
setupRyMax();            
break;

case 5 : // Rotary Y Axis
setupRyMin();
break;

case 6 :
setupSteeringTurn();
break;

case 7 :
setupThrottleMax();
break;

case 8 :
setupThrottleMin();
break;

case 9 :
setupBrakeMax();
break;

case 10 :
setupBrakeMin();
break;

default:

_delay_ms(1500);
joyst_->setRxCenter(joyst_->rotationX_.getData().act);
eeprom_->put(STORE_ADDR_RX_CENTER, joyst_->getRxCenter());
joyst_->setRyCenter(joyst_->rotationY_.getData().act);
eeprom_->put(STORE_ADDR_RY_CENTER, joyst_->getRyCenter());
printLine(0,TXT_RESET);

return 2;
break;
}
return 1;
}

void SetupDisplay::showSteering() {
    
printLine(1,"   " + String(encoder_->getData().act));
}

bool SetupDisplay::askForSetup() {
    
// clear everything

printLine(0, TXT_BOOTING);

// loading bar

uint8_t wait {0};
lcd_->setCursor(0,1);
while(wait < LCD_CHARS) {
    
if (joyst_->getButtonStatus().pushed) {
    
// run setup wizard

waitForButtonRelease();

return true; // feedback, that the user want´s to run the setup wizard
}

lcd_->print(".");
_delay_ms(200);
wait++;
}

// end

lcd_->clear();
lcd_->setCursor(0,0);
#ifndef LUSMDL_DEBUGMODE
lcd_->print(TXT_BOOT_DONE);
#endif
#ifdef LUSMDL_DEBUGMODE
lcd_->print(TXT_DEBUG);
#endif

_delay_ms(500);

//lcd_->noBacklight(); don´t switch off the light
lcd_->clear();

return false; // feedback, that no setup wizard is needed
}


void SetupDisplay::clearLine(uint8_t line) {
    
lcd_->setCursor(0,line);
lcd_->print(TXT_CLEAR);
}


void SetupDisplay::printLine(uint8_t line, String txt) {

lcd_->setCursor(0, line);
String data = txt.substring(0, LCD_CHARS); // truncate to 16 characters if longer
while (data.length() < LCD_CHARS) { // pad with spaces if shorter
    data += " ";
}
lcd_->print(data);
}



void SetupDisplay::waitForButtonRelease() {
    
    while (joyst_->getButtonStatus().pushed){}
}


void SetupDisplay::setupRxMax() {
    
    if(joyst_->getButtonStatus().pushed) {
        
        waitForButtonRelease();
        
        printLine(0, TXT_DONE);
        printLine(1, String(joyst_->rotationX_.getData().act));
        eeprom_->put(STORE_ADDR_RX_MAX, joyst_->rotationX_.setMax(MAX_AXIS));
        
        _delay_ms(500);
        
        clearLine(0);
        clearLine(1);
        
        page_++;
    }
    else {
        
        lcd_->setCursor(0,0);
        lcd_->print("set Rx Max");
        printLine(1, String(joyst_->rotationX_.getData().act));
    }
}

void SetupDisplay::setupRxMin() {
    
    if(joyst_->getButtonStatus().pushed) {
        
        waitForButtonRelease();
        
        
        printLine(0, TXT_DONE);
        printLine(1, String(joyst_->rotationX_.getData().act));
        eeprom_->put(STORE_ADDR_RX_MIN, joyst_->rotationX_.setMin(MIN_AXIS));
        
        _delay_ms(500);
        
        clearLine(0);
        clearLine(1);
        
        page_++;
    }
    else {
        
        lcd_->setCursor(0,0);
        lcd_->print("set Rx Min");
        printLine(1, String(joyst_->rotationX_.getData().act));
    }
}

void SetupDisplay::setupRyMax() {
    
    if(joyst_->getButtonStatus().pushed) {
        
        waitForButtonRelease();
        
        printLine(0, TXT_DONE);
        printLine(1, String(joyst_->rotationY_.getData().act));
        eeprom_->put(STORE_ADDR_RY_MAX, joyst_->rotationY_.setMax(MAX_AXIS));
        
        _delay_ms(500);
        
        clearLine(0);
        clearLine(1);
        
        page_++;
    }
    else {
        
        lcd_->setCursor(0,0);
        lcd_->print("set Ry Max");
        lcd_->setCursor(0,1);
        printLine(1, String(joyst_->rotationY_.getData().act));
    }
}

void SetupDisplay::setupRyMin() {
    
    if(joyst_->getButtonStatus().pushed) {
        
        waitForButtonRelease();
        
        
        printLine(0, TXT_DONE);
        printLine(1, String(joyst_->rotationY_.getData().act));
        eeprom_->put(STORE_ADDR_RY_MIN, joyst_->rotationY_.setMin(MIN_AXIS));
        
        _delay_ms(500);
        
        clearLine(0);
        clearLine(1);
        
        page_++;
    }
    else {
        
        lcd_->setCursor(0,0);
        lcd_->print("set Ry Min");
        printLine(1, String(joyst_->rotationY_.getData().act));
    }
}

void SetupDisplay::setupSteeringZero() {
    
    if(joyst_->getButtonStatus().pushed) {
        
        waitForButtonRelease();
        
        encoder_->setZero();
        printLine(0, TXT_DONE);
        printLine(1, String(encoder_->getPosition()));
        
        _delay_ms(500);
        
        clearLine(0);
        clearLine(1);
        
        page_++;
    }
    else {
        
        lcd_->setCursor(0,0);
        lcd_->print("set wheel 0");
        printLine(1, String(encoder_->getPosition()));
    }
}

void SetupDisplay::setupSteeringTurn() {
    
    if(joyst_->getButtonStatus().pushed) {
        
        waitForButtonRelease();
        
        printLine(0, TXT_DONE);
        printLine(1, String(encoder_->getPosition()));
        eeprom_->put(STORE_ADDR_FACTOR, encoder_->setFactor());
        
        _delay_ms(500);
        
        clearLine(0);
        clearLine(1);
        
        page_++;
    }
    else {
        
        lcd_->setCursor(0,0);
        lcd_->print("set wheel 360 deg");
        printLine(1, String(encoder_->getPosition()));
    }
}

void SetupDisplay::setupThrottleMax() {
    
    if(joyst_->getButtonStatus().pushed) {
        
        waitForButtonRelease();
        
        printLine(0, TXT_DONE);
        printLine(1, String(pedal_->throttle_.getData().act));
        eeprom_->put(STORE_ADDR_THROTTLE_MAX, pedal_->throttle_.setMax(MAX_AXIS));
        
        _delay_ms(500);
        
        clearLine(0);
        clearLine(1);
        
        page_++;
    }
    else {
        
        lcd_->setCursor(0,0);
        lcd_->print("set Thottle Max");
        lcd_->setCursor(0,1);
        printLine(1, String(pedal_->throttle_.getData().act));
    }
}

void SetupDisplay::setupThrottleMin() {
    
    if(joyst_->getButtonStatus().pushed) {
        
        waitForButtonRelease();
        
        
        printLine(0, TXT_DONE);
        printLine(1, String(pedal_->throttle_.getData().act));
        eeprom_->put(STORE_ADDR_THROTTLE_MIN, pedal_->throttle_.setMin(MIN_AXIS));
        
        _delay_ms(500);
        
        clearLine(0);
        clearLine(1);
        
        page_++;
    }
    else {
        
        lcd_->setCursor(0,0);
        lcd_->print("set Throttle Min");
        printLine(1, String(pedal_->throttle_.getData().act));
    }
}

void SetupDisplay::setupBrakeMax() {
    
    if(joyst_->getButtonStatus().pushed) {
        
        waitForButtonRelease();
        
        printLine(0, TXT_DONE);
        printLine(1, String(pedal_->brake_.getData().act));
        eeprom_->put(STORE_ADDR_BRAKE_MAX, pedal_->brake_.setMax(MAX_AXIS));
        
        _delay_ms(500);
        
        clearLine(0);
        clearLine(1);
        
        page_++;
    }
    else {
        
        lcd_->setCursor(0,0);
        lcd_->print("set Brake Max");
        lcd_->setCursor(0,1);
        printLine(1, String(pedal_->brake_.getData().act));
    }
}

void SetupDisplay::setupBrakeMin() {
    
    if(joyst_->getButtonStatus().pushed) {
        
        waitForButtonRelease();
        
        
        printLine(0, TXT_DONE);
        printLine(1, String(pedal_->brake_.getData().act));
        eeprom_->put(STORE_ADDR_BRAKE_MIN, pedal_->brake_.setMin(MIN_AXIS));
        
        _delay_ms(500);
        
        clearLine(0);
        clearLine(1);
        
        page_++;
    }
    else {
        
        lcd_->setCursor(0,0);
        lcd_->print("set Brake Min");
        printLine(1, String(pedal_->brake_.getData().act));
    }
}
*/
