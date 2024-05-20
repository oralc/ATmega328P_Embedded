# Arduino LCD Joystick RGB LED Controller

This Arduino sketch is designed to control an LCD, a joystick, and an RGB LED. It utilizes the LiquidCrystal library for the LCD display and analogRead for the joystick input. The RGB LED changes color based on the joystick movement and displays messages on the LCD screen.

## Hardware Setup

### Components Used:
- LCD Display
- Joystick
- RGB LED
- Arduino Board

### Pin Connections:
- LCD:
  - RS (Register Select) pin to Arduino pin 7
  - Enable pin to Arduino pin 8
  - D4, D5, D6, D7 pins to Arduino pins 9, 10, 11, 12 respectively
- Joystick:
  - VRx to Arduino analog pin A0
  - VRy to Arduino analog pin A1
  - SW (Switch) to Arduino digital pin 2
- RGB LED:
  - Red pin to Arduino pin 3
  - Green pin to Arduino pin 4
  - Blue pin to Arduino pin 5

## Code Overview

The code initializes the LCD, joystick pins, and RGB LED pins in the `setup()` function. It defines custom characters for the LCD, sets initial configurations, and begins serial communication.

In the `loop()` function:
1. It reads joystick values and button state.
2. Prints values to Serial Monitor.
3. Displays a welcoming message on LCD when the button is pressed.
4. Changes LCD display and RGB LED color based on joystick movement.
5. Sets the LED to neutral (white) if the joystick is in the center position.

## Customization

- **Thresholds**: Adjust thresholds for joystick movement (`xLeftThreshold`, `xRightThreshold`, `yBottomThreshold`, `yMiddleThreshold`) as per your joystick's range.
- **Colors**: Modify color values (`RED`, `WHITE`, `BLUE`, `GREEN`) for RGB LED as desired.
- **Brightness**: Set the brightness level (`brightness`) for the LED (0-255).

## Dependencies

- [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal) library for controlling the LCD.

## Usage

1. Connect the hardware components as per the pin connections mentioned.
2. Upload the sketch to your Arduino board.
3. Open Serial Monitor to view joystick values.
4. Press the joystick button to trigger the welcoming message.

## License

This code is provided under the MIT License. See the [LICENSE](LICENSE) file for details.
