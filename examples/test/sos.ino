#include <MorseSensor.h>

Morse morse(13);

void setup()
{
  morse.begin();
}

void loop()
{
  // Send SOS in Morse code using the new sendMessage method
  morse.sendMessage("SOS");
  delay(3000);
}

