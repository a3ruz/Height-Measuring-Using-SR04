
#include <NewPing.h>
#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(11,10,9,2,3,4,5);  //Create Liquid Crystal Object called LCD


#define TRIGGER_PIN  13  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define BUZZER 7

NewPing SONAR(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

long height_,T_height;
void setup() 
{  
  
  LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
  LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print("HEIGHT");  //Print Message on First Row

   Serial.begin(9600);
  //repeat..................................................................................
   
   
   }

void loop() 
{
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  height=SONAR.ping_cm()
  Serial.print("Ping: ");
  Serial.print(height_); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  
  LCD.setCursor(0,1);  //Set cursor to first column of second row
  LCD.print("                "); //Print blanks to clear the row
  LCD.setCursor(0,1);   //Set Cursor again to first column of second row
  LCD.print(height_); //Print measured distance
  LCD.print(" cm");  //Print your units.
  
  
  delay(1000); //pause to let things settle
  
}

