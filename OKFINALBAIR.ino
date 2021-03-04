#include <FastLED.h>

#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>
#include <math.h>

//def LED values
#define LED_PIN 2
#define LED_COUNT 30

#define PIR_PIN 6
//declare neopixel values
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
float value, pinVal; 
float multiplier = 12;
float movementMultiplier = 30;

int LED_X = 5;
int LED_Y = 6;

int refreshRate = 1;

float timeStart, timeEnd;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(PIR_PIN, INPUT);
  
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(30); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  // Take 10 milliseconds of sound data to calculate
  
  //loud sound is defined as 500.00 ambient = 100.00
  value = CircuitPlayground.mic.soundPressureLevel(100);
  pinVal = digitalRead(PIR_PIN);
  movementFade(pinVal);

 colorTransform(value, movementMultiplier, refreshRate);
}


void movementFade(float pin){
  if(movementMultiplier > 0 && pin == 0){
    movementMultiplier -= 0.5;
  }else if(movementMultiplier < 150 && pin == 1){
    movementMultiplier += 5;
    //protect against burnout
    if(movementMultiplier > 150.0){
      movementMultiplier = 150;
    }
  }
}

float valTransformOne(float val){
  float t_val = multiplier*(val-50);
  return t_val;
}

float valTransformTwo(float val, float mult){
  //scale
  float t_val = valMap(val) * mult;
  return t_val;
}

float valMap(float val){
  float t_val = map(multiplier*(val-50), 0, 800, 30, 255);
  return t_val;
}
void colorTransform(float val, float movement, int wait){
   //color(255, 228, 171) <- soft orange yellow
  //color(255, 243, 23) <- bright yellow
  //color(255, 127, 23) <- fire orange

  //color(145, 185, 222) <-- bair blu
  //color(135, 48, 222) <--- bair purple
  //color(222,222,222) <--bair white
  
  for( int i = 0; i<LED_X; i++){
    float rowMil = millis() + i;
    for(int j = 0; j < LED_Y; j++){
      float noise = inoise8(0.1f*millis()*i*j)/500.01;
      float cosOutput = cos(rowMil);
      float r, g, b;
      /*
      if(cosOutput > 0){
        r = map(10*abs(cosOutput),0, 10, 135, 145);
        g = map(10*abs(cosOutput),0, 10, 48, 185);
        b = 222+noise;
      }else{
         r = map(10*abs(cosOutput),0, 10, 145, 222);
        g = map(10*abs(cosOutput),0, 10, 185, 222);
        b = 222+noise;
      }*/
     //r = map(10*cosOutput, -10, 10, 135, 145);
     //g = map(10*cosOutput, -10, 10, 48, 185);
     //b = 222-cosOutput;

    
    r = map(10*cos(rowMil*(100-val))+noise, -10, 10, 135, 222);
    g = map(10*cos(rowMil*(100-val))+noise, -10, 10, 48, 222)+ random(0,val-40);
    b = 222-(10*cos(rowMil*(100-val)));

    strip.setPixelColor((i*LED_Y) + j, strip.Color(r,g,b));
    //strip.setBrightness(inoise8(0.1f*millis()*j)-100);
      Serial.print(movement);
      Serial.print("\n");
      strip.setBrightness(movement);
    strip.show();                          //  Update strip to match
    delay(wait);   
    }
  }

}
