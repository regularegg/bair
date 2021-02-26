#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

//def LED values
#define LED_PIN 6
#define LED_COUNT 30

//declare neopixel values
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
float value; 
float multiplier = 12;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  // Take 10 milliseconds of sound data to calculate
  
  //loud sound is defined as 500.00 ambient = 100.00
  value = CircuitPlayground.mic.soundPressureLevel(10);
  
  //Serial.print("Sound Sensor SPL: ");
  //Serial.println(value);

  delay(90);

  colorWipe(value, 10);
}

void displaySound(){
  
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
  Serial.print(t_val);
  Serial.print("\n");
  return t_val;
}

void colorWipe(float val, int wait) {

  //color(255, 228, 171) <- soft orange yellow
  //color(255, 243, 23) <- bright yellow
  //color(255, 127, 23) <- fire orange
  float sameVal = valMap(val);

  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    //generic red morph
    strip.setPixelColor(i, strip.Color(val,i,i));         //  Set pixel's color (in RAM)

    //Orange surprise
    strip.setPixelColor(i, strip.Color(255,valTransformTwo(val, i),23));         //  Set pixel's color (in RAM)

    //Red to yellow
    //strip.setPixelColor(i, strip.Color(255,i,i));         //  Set pixel's color (in RAM)

    //All the same
    float tempVal = valMap(val);
    //strip.setPixelColor(i, strip.Color(sameVal, sameVal, sameVal));   


    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
