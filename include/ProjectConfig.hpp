/**
 * @file ProjectConfig.hpp
 * 
 * @brief Definition of Project Pins and other important constatnt Values
 */

#ifndef PROJECT_CONFIG_H
#define PROJECT_CONFIG_H

#define LUSMDL_DEBUGMODE // activates the debug function of the Serial Monitor 

#ifdef LUSMDL_DEBUGMODE
#warning This code is in DEBUG mode!!! The Macro 'LUSMDL_DEBUGMODE' in include/ProjectCofig.hpp has to be comment out
#warning The LCD feature is disabled because of the RAM storage
#endif


// MAIN.CPP Timing

#define  TIME_FAST              2
#define  TIME_NORMAL            8
#define  TIME_SLOW              256


// MY I²C

#define I2C_MY_ADDR         10

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
#define LCD_RS              8
#define LCD_EN              9
#define LCD_D4              4
#define LCD_D5              5
#define LCD_D6              6
#define LCD_D7              7

#define LCD_CHARS           16

#define LCD_BACKLIGHT       10


#endif // PROJECT_CONFIG_H
