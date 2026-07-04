# Arduino Morse Sensor Library

A flexible and extensible Arduino library for flashing Morse code signals.

## Features

- **Configurable Timing**: Customize dot, dash, and gap lengths
- **Multiple Constructors**: Use default timing or specify custom dot length
- **Complete Morse Code Support**: All letters (A-Z) and numbers (0-9)
- **High-Level API**: Send complete messages with `sendMessage()`
- **Standard Timing Ratios**: Follows international Morse code standards
  - Dash = 3 × Dot length
  - Intra-character gap = 1 × Dot length
  - Inter-letter gap = 3 × Dot lengths
  - Inter-word gap = 7 × Dot lengths

## Installation

1. Download the library
2. Place it in your Arduino libraries folder
3. Restart Arduino IDE

## Usage

### Basic Example (SOS Signal)

```cpp
#include <MorseSensor.h>

Morse morse(13);  // Use pin 13

void setup()
{
  morse.begin();
}

void loop()
{
  morse.sendMessage("SOS");
  delay(3000);
}
```

### Advanced Example (Custom Timing)

```cpp
#include <MorseSensor.h>

// Create with custom dot length (100ms instead of default 250ms)
Morse morse(13, 100);

void setup()
{
  morse.begin();
  
  // Or adjust timing after creation
  morse.setDotLength(150);
  morse.setDashLength(450);
  morse.setGapLength(150);
}

void loop()
{
  // Send individual characters
  morse.sendChar('H');
  morse.sendChar('E');
  morse.sendChar('L');
  morse.sendChar('L');
  morse.sendChar('O');
  
  delay(5000);
  
  // Or send complete messages
  morse.sendMessage("HELLO WORLD");
  
  delay(5000);
}
```

### Low-Level Control

```cpp
#include <MorseSensor.h>

Morse morse(13);

void setup()
{
  morse.begin();
}

void loop()
{
  // Manual control
  morse.dot();
  morse.dot();
  morse.dot();
  morse.letterPause();
  
  morse.dash();
  morse.dash();
  morse.dash();
  morse.letterPause();
  
  morse.dot();
  morse.dot();
  morse.dot();
  morse.wordPause();
}
```

## API Reference

### Constructor

- `Morse(int pin)` - Create with default timing (250ms dot)
- `Morse(int pin, int dotLength)` - Create with custom dot length

### Initialization

- `void begin()` - Initialize the pin for output

### Basic Operations

- `void dot()` - Send a dot signal
- `void dash()` - Send a dash signal

### Timing Control

- `void setDotLength(int length)` - Set dot duration in milliseconds
- `void setDashLength(int length)` - Set dash duration in milliseconds
- `void setGapLength(int length)` - Set gap duration in milliseconds

### Pause Utilities

- `void pause()` - Intra-character pause (1 dot length)
- `void letterPause()` - Inter-letter pause (3 dot lengths)
- `void wordPause()` - Inter-word pause (7 dot lengths)

### High-Level Methods

- `void sendChar(char c)` - Send a single character in Morse code
- `void sendMessage(const char* message)` - Send a complete message string

## Supported Characters

- Letters: A-Z (case insensitive)
- Numbers: 0-9
- Spaces: Treated as word separators

## License

Released into the public domain.

## Authors

- Original: David A. Mellis (2007)
- Updated: Jason A. Cox (2023)
- Refactored: Current version

## Repository

https://github.com/rongfengliang/arduino-lib-learning
