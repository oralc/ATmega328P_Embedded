// include the library code:
//#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Joystick Pins
const int VRx = A0;
const int VRy = A1;
const int SW = 2;

// Create a custom character
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
  Serial.print("")

  // Determine the range of yValue
  lcd.clear();
  if (yValue >= 100 && yValue <= 500) {
    // Display custom character on the second row only
    for (int col = 0; col < 16; col++) {
      lcd.setCursor(col, 1);
      lcd.write(byte(0));
    }
  } else if (yValue >= 0 && yValue < 100) {
    // Display custom character on both rows
    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 16; col++) {
        lcd.setCursor(col, row);
        lcd.write(byte(0));
      }
    }
  }

  // Add a small delay to avoid bouncing
  delay(500);
}
