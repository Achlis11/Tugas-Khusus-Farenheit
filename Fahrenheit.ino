/* This code works with MLX90614 (GY906) and OLED screen
 * It measures both ambient and object temperature in Fahrenheit and display it on the screen
 * Please visit www.surtrtech.com for more details
 */
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
const int buttonPin = 12; 
unsigned long timb=millis();
int rsts=0;
void setup() {  
  mlx.begin(); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  display.clearDisplay();
  display.display();
pinMode(buttonPin, INPUT_PULLUP);
 display.setTextSize(2);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,13);                
  display.println("Ready");
  display.display();
}

void loop() {
  display.clearDisplay();
  
  
  if (digitalRead(12)==LOW)
  {if((timb+800)<millis())
  {
  display.setTextSize(2);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,13);                
  display.println("Suhu"); 
  
  display.setTextSize(2);
  display.setCursor(55,13);
  display.println(mlx.readObjectTempC(),1);
  
  display.setCursor(110,13);
  display.println("C");
  
  display.display();
  timb=millis();
  }}
  else if((timb+10000)<millis())
  { display.setTextSize(2);                    
  display.setTextColor(WHITE);             
  display.setCursor(0,13);                
  display.println("Ready");
  display.display();}
  
}
