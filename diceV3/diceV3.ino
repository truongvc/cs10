//dice project
#include <Adafruit_CircuitPlayground.h>

#define DICE_COLOR          0xEA6292    // Dice digits color
int rollNum;
#define COLOR         0xFF0000    // change this to your favorite color    
#define SPIN_RATE     100         // lower is faster

int pixel1;
int pixel2;

int rollStartTime; 

/////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  Serial.println("Connected!");
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(5);
  randomSeed(CircuitPlayground.soundSensor()); 
    pixel1 = 0;
  pixel2 = 5;
}//end setup


///////////////////////////////////////////////////////////////////
void loop() {
  if (CircuitPlayground.rightButton()){
    
    rollStartTime = millis();
    while(millis() - rollStartTime < 1000){
      // Turn off all the NeoPixels
      CircuitPlayground.clearPixels();
     
      // Turn on two pixels to COLOR
      CircuitPlayground.setPixelColor(pixel1, COLOR);
      CircuitPlayground.setPixelColor(pixel2, COLOR);
     
      // Increment pixels to move them around the board
      pixel1 = pixel1 + 1;
      pixel2 = pixel2 + 1;
     
      // Check pixel values
      if (pixel1 > 9) pixel1 = 0;
      if (pixel2 > 9) pixel2 = 0;
     
      // Wait a little bit so we don't spin too fast
      delay(SPIN_RATE);
    }//end while
 
    CircuitPlayground.clearPixels();
    rollNum = random(1,7);
    CircuitPlayground.playTone(random(100,1000), 500);
    CircuitPlayground.playTone(random(100,1000), 500);
    CircuitPlayground.playTone(random(100,1000), 500);
    if(rollNum == 1){
      CircuitPlayground.setPixelColor(1, DICE_COLOR);  
    }
    if(rollNum == 2){
      CircuitPlayground.setPixelColor(2, DICE_COLOR);  
      CircuitPlayground.setPixelColor(7, DICE_COLOR);
    }
    if(rollNum == 3){
      CircuitPlayground.setPixelColor(0, DICE_COLOR); 
      CircuitPlayground.setPixelColor(4, DICE_COLOR);
      CircuitPlayground.setPixelColor(7, DICE_COLOR); 
    }
    if(rollNum == 4){
      CircuitPlayground.setPixelColor(1, DICE_COLOR);
      CircuitPlayground.setPixelColor(3, DICE_COLOR);
      CircuitPlayground.setPixelColor(6, DICE_COLOR);
      CircuitPlayground.setPixelColor(8, DICE_COLOR);
    }
    if(rollNum == 5){
      CircuitPlayground.setPixelColor(0, DICE_COLOR);
      CircuitPlayground.setPixelColor(2, DICE_COLOR);
      CircuitPlayground.setPixelColor(4, DICE_COLOR);
      CircuitPlayground.setPixelColor(6, DICE_COLOR);
      CircuitPlayground.setPixelColor(8, DICE_COLOR);    
    }
    if(rollNum == 6){
      CircuitPlayground.setPixelColor(0, DICE_COLOR);
      CircuitPlayground.setPixelColor(2, DICE_COLOR);
      CircuitPlayground.setPixelColor(4, DICE_COLOR);
      CircuitPlayground.setPixelColor(5, DICE_COLOR);
      CircuitPlayground.setPixelColor(7, DICE_COLOR);
      CircuitPlayground.setPixelColor(9, DICE_COLOR);  
    }
    
    Serial.println(CircuitPlayground.soundSensor());
   
  }//end if right btn
  
}//end loop
