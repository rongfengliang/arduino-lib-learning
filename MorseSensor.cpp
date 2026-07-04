/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Updated by Jason A. Cox, February 18, 2023.
  Refactored for better flexibility and maintainability.
  Released into the public domain.
*/

#include "Arduino.h"
#include "MorseSensor.h"

// Constructor with default timing
Morse::Morse(int pin)
{
  _pin = pin;
  _dotLength = MORSE_DEFAULT_DOT_LENGTH;
  _dashLength = MORSE_DEFAULT_DASH_LENGTH;
  _gapLength = MORSE_DEFAULT_GAP_LENGTH;
}

// Constructor with custom dot length
Morse::Morse(int pin, int dotLength)
{
  _pin = pin;
  _dotLength = dotLength;
  _dashLength = dotLength * 3;  // Standard ratio: dash = 3 * dot
  _gapLength = dotLength;        // Standard ratio: gap = dot
}

void Morse::begin()
{
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
}

// Internal helper: turn signal on
void Morse::_signalOn()
{
  digitalWrite(_pin, HIGH);
}

// Internal helper: turn signal off
void Morse::_signalOff()
{
  digitalWrite(_pin, LOW);
}

void Morse::dot()
{
  _signalOn();
  delay(_dotLength);
  _signalOff();
  delay(_gapLength);  
}

void Morse::dash()
{
  _signalOn();
  delay(_dashLength);
  _signalOff();
  delay(_gapLength);
}

// Timing control methods
void Morse::setDotLength(int length)
{
  _dotLength = length;
}

void Morse::setDashLength(int length)
{
  _dashLength = length;
}

void Morse::setGapLength(int length)
{
  _gapLength = length;
}

// Pause utilities (standard Morse timing)
void Morse::pause()
{
  delay(_gapLength);  // Intra-character gap
}

void Morse::letterPause()
{
  delay(_gapLength * 3);  // Inter-letter gap (3 dots)
}

void Morse::wordPause()
{
  delay(_gapLength * 7);  // Inter-word gap (7 dots)
}

// Get Morse code pattern for a character
const char* Morse::_getMorseCode(char c)
{
  c = toupper(c);
  
  switch(c)
  {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case ' ': return " ";  // Word separator
    default: return "";
  }
}

// Send a single character in Morse code
void Morse::sendChar(char c)
{
  const char* code = _getMorseCode(c);
  
  if (code[0] == ' ')
  {
    wordPause();
    return;
  }
  
  while (*code)
  {
    if (*code == '.')
      dot();
    else if (*code == '-')
      dash();
    
    code++;
    
    // Add intra-character pause if not at end
    if (*code)
      pause();
  }
  
  letterPause();
}

// Send a complete message string
void Morse::sendMessage(const char* message)
{
  while (*message)
  {
    sendChar(*message);
    message++;
  }
}