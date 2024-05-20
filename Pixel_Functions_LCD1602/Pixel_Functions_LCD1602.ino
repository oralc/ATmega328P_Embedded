// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Joystick Pins
const int VRx = A0;
const int VRy = A1;
const int SW = 2;

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
const int delay_bounce = 500;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Initialize the joystick pins
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Create the custom character
  lcd.createChar(0, customChar);

  // Clear the display initially
  lcd.clear();
  
  // Initialize Serial communication
  Serial.begin(9600);
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
    delay(4000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ich bin der Teo");
    lcd.setCursor(0, 1);
    lcd.print("Freut mich!");
    delay(4000);
    lcd.clear(); // Clear the display after showing the message
    return; // Skip the rest of the loop to avoid flickering
  }

  // Determine the display based on yValue
  lcd.clear();
  if (yValue >= yBottomThreshold && yValue <= yMiddleThreshold) {
    // Display custom character on the second row only
    for (int col = 0; col < 16; col++) {
      lcd.setCursor(col, 1);
      lcd.write(byte(0));
    }
  } else if (yValue >= 0 && yValue < yBottomThreshold) {
    // Display custom character on both rows
    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 16; col++) {
        lcd.setCursor(col, row);
        lcd.write(byte(0));
      }
    }
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
  } else if (xValue > xRightThreshold) {
    // Display custom character on the right half
    for (int row = 0; row < 2; row++) {
      for (int col = 8; col < 16; col++) {
        lcd.setCursor(col, row);
        lcd.write(byte(0));
      }
    }
  }

  // Add a small delay to avoid bouncing
  delay(delay_bounce);
}
