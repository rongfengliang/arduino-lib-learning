/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Updated by Jason A. Cox, February 18, 2023.
  Refactored for better flexibility and maintainability.
  Released into the public domain.
*/
#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

// Default timing values (in milliseconds)
#define MORSE_DEFAULT_DOT_LENGTH    250
#define MORSE_DEFAULT_DASH_LENGTH   750
#define MORSE_DEFAULT_GAP_LENGTH    250

class Morse
{
  public:
    // Constructor with pin number
    Morse(int pin);
    
    // Constructor with pin and custom dot length
    Morse(int pin, int dotLength);
    
    // Initialize the Morse code library
    void begin();
    
    // Basic Morse code elements
    void dot();
    void dash();
    
    // Timing control
    void setDotLength(int length);
    void setDashLength(int length);
    void setGapLength(int length);
    
    // Utility methods
    void pause();
    void letterPause();
    void wordPause();
    
    // Send a complete character
    void sendChar(char c);
    
    // Send a message string
    void sendMessage(const char* message);

  private:
    int _pin;
    int _dotLength;
    int _dashLength;
    int _gapLength;
    
    // Internal helper methods
    void _signalOn();
    void _signalOff();
    const char* _getMorseCode(char c);
};

#endif