//dice project
#include <Adafruit_CircuitPlayground.h>

#define DICE_COLOR          0xEA6292    // Dice digits color
int rollNum;

void setup() {
  Serial.begin(9600);
  Serial.println("Connected!");
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(5);
  randomSeed(CircuitPlayground.soundSensor());
  
}

void loop() {
  if (CircuitPlayground.rightButton()){
    CircuitPlayground.clearPixels();
    rollNum = random(1,7);
    CircuitPlayground.playTone(random(100,1000), 500);
    CircuitPlayground.playTone(random(100,1000), 500);
    CircuitPlayground.playTone(random(100,1000), 500);
    CircuitPlayground.setPixelColor(rollNum, DICE_COLOR);
    Serial.println(CircuitPlayground.soundSensor());
   
  }//end if right btn
  
}
