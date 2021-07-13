#define USE_ARDUINO_INTERRUPTS true   
#include <PulseSensorPlayground.h>       


const int PulseWire = A5;      
const int led = 13;          
int Threshold = 550;           

PulseSensorPlayground pulseSensor;  


void setup() {   

  Serial.begin (112500);       

  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(led);       
  pulseSensor.setThreshold(Threshold);   

   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");    
  }
}



void loop() {

 int myBPM = pulseSensor.getBeatsPerMinute();  
 

 if (pulseSensor.sawStartOfBeat()) {             
 Serial.println("♥  A HeartBeat Happened ! "); 
 Serial.print("BPM: ");                       
 Serial.println(myBPM);                         
}
  delay(1000);                    

}

  
