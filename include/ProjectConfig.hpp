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

// MY I²C

#define I2C_MY_ADDR         10



#endif // PROJECT_CONFIG_H
