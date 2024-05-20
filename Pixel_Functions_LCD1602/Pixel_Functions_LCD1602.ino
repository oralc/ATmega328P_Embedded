// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Joystick Pins
const int VRx = A0;
const int VRy = A1;
const int SW = 2;

// RGB LED Pins
const int redPin = 3;
const int greenPin = 4;
const int bluePin = 5;

// Custom Character
byte customChar[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

// Thresholds for joystick values
const int xLeftThreshold = 500;
const int xRightThreshold = 530;
const int yBottomThreshold = 300;
const int yMiddleThreshold = 500;

// Colors
const int BLUE[3] = {255, 0, 0}; //used to be red - changable  
const int WHITE[3] = {0, 255, 0}; //used to be green - changable  
const int RED[3] = {0, 0, 255}; //used to be blue - changable  
const int GREEN[3] = {255, 255, 255}; //used to be white - changable  

// Brightness level (0-255)
const int brightness = 128; // 50% brightness

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Initialize the joystick pins
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Initialize the RGB LED pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Create the custom character
  lcd.createChar(0, customChar);

  // Clear the display initially
  lcd.clear();
  
  // Initialize Serial communication
  Serial.begin(9600);

  // Set initial LED color to white (neutral) with specified brightness
  setRGBColor(WHITE, brightness);
}

void loop() {
  // Read the joystick values
  int xValue = analogRead(VRx);
  int yValue = analogRead(VRy);
  int buttonState = digitalRead(SW);

  // Print values to the Serial Monitor
  Serial.print("xValue: ");
  Serial.print(xValue);
  Serial.print(", yValue: ");
  Serial.print(yValue);
  Serial.print(", buttonState: ");
  Serial.println(buttonState);

  // Check if the button is pressed
  if (buttonState == 0) {
    // Display the welcoming message
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Servus Grias Di!");
    lcd.setCursor(0, 1);
    lcd.print("   PALFINGER   ");
    setRGBColor(GREEN, brightness); // Set RGB LED to Green for welcoming message
    delay(4000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ich bin der Teo!");
    lcd.setCursor(0, 1);
    lcd.print("Freut mich");
    delay(4000);
    lcd.clear(); // Clear the display after showing the message
    setRGBColor(WHITE, brightness); // Set RGB LED to White (Neutral)
    return; // Skip the rest of the loop to avoid flickering
  }

  bool isNeutral = true;

  // Determine the display based on yValue
  lcd.clear();
  if (yValue >= yBottomThreshold && yValue <= yMiddleThreshold) {
    // Display custom character on the second row only
    for (int col = 0; col < 16; col++) {
      lcd.setCursor(col, 1);
      lcd.write(byte(0));
    }
    setRGBColor(BLUE, brightness); // Set RGB LED to Blue for yValue changes
    isNeutral = false;
  } else if (yValue >= 0 && yValue < yBottomThreshold) {
    // Display custom character on both rows
    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 16; col++) {
        lcd.setCursor(col, row);
        lcd.write(byte(0));
      }
    }
    setRGBColor(BLUE, brightness); // Set RGB LED to Blue for yValue changes
    isNeutral = false;
  }

  // Determine the display based on xValue
  if (xValue < xLeftThreshold) {
    // Display custom character on the left half
    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 8; col++) {
        lcd.setCursor(col, row);
        lcd.write(byte(0));
      }
    }
    setRGBColor(RED, brightness); // Set RGB LED to Red for xValue changes
    isNeutral = false;
  } else if (xValue > xRightThreshold) {
    // Display custom character on the right half
    for (int row = 0; row < 2; row++) {
      for (int col = 8; col < 16; col++) {
        lcd.setCursor(col, row);
        lcd.write(byte(0));
      }
    }
    setRGBColor(RED, brightness); // Set RGB LED to Red for xValue changes
    isNeutral = false;
  }

  // If joystick is in neutral position
  if (isNeutral) {
    setRGBColor(WHITE, brightness); // Set RGB LED to White (Neutral)
  }

  // Add a small delay to avoid bouncing
  delay(500);
}

// Function to set RGB LED color with brightness
void setRGBColor(const int color[3], int brightness) {
  int red = map(color[0], 0, 255, 0, brightness);
  int green = map(color[1], 0, 255, 0, brightness);
  int blue = map(color[2], 0, 255, 0, brightness);

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}