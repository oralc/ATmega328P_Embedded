// git add .
// git commit -m "Message"
// git push origin main || GIT_SSL_NO_VERIFY=true git push origin main

// git checkout main
// git pull origin main
// git merge <branch-name>
// Then follow the first 3 steps



#include <LCD.I2C.h>

// Initialize the LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Joystick pins
const int vrxPin = A0;
const int vryPin = A1;
const int swPin = 2;

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Set the joystick switch pin as input
  pinMode(swPin, INPUT_PULLUP);
  // Initialize the LCD with a welcome message
  lcd.print("Move Joystick");

}

void loop() {
  
  // Read the joystick values
  int vrxValue = analogRead(vrxPin);
  int vryValue = analogRead(vryPin);

  // Determine joystick direction and display message
  if (vryValue > 800) {
    lcd.setCursor(0, 0);  // Set cursor to top row
    lcd.clear();          // Clear the display
    lcd.print("Top Row Active");  // Display message on top row
  } else if (vryValue < 200) {
    lcd.setCursor(0, 1);  // Set cursor to bottom row
    lcd.clear();          // Clear the display
    lcd.print("Bottom Row Active");  // Display message on bottom row
  }
  
  delay(200); // Delay for readability

}
