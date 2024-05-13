const int interval = 1000; // Interval between message transmissions (milliseconds)
unsigned long previousMillis = 0;
bool isRunning = true; // Control flag for running the simulation

void setup() {
  Serial.begin(9600);
  Serial.println("CAN Message Simulator Ready. Type 'start' to begin or 'stop' to halt.");
}

void loop() {
  // Check for commands from the Serial Monitor
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Remove any whitespace or newline characters

    if (command.equalsIgnoreCase("start")) {
      isRunning = true;
      Serial.println("Simulation started.");
    } else if (command.equalsIgnoreCase("stop")) {
      isRunning = false;
      Serial.println("Simulation stopped.");
    } else {
      Serial.println("Unknown command. Type 'start' to begin or 'stop' to halt.");
    }
  }

  // Simulate sending and receiving CAN messages if the simulation is running
  if (isRunning) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // Create a CAN-like message
      String canMessage = createCanMessage(0x100, "11 22 33 44 55 66 77 88");

      // Simulate sending the message
      sendCanMessage(canMessage);

      // Simulate receiving the message
      receiveCanMessage(canMessage);
    }
  }
}

String createCanMessage(int id, String data) {
  // Create a CAN-like message with an ID and data field
  return "ID:0x" + String(id, HEX) + " DATA:" + data;
}

void sendCanMessage(String message) {
  // Simulate sending the CAN message
  Serial.print("Sending CAN message: ");
  Serial.println(message);
}

void receiveCanMessage(String message) {
  // Simulate receiving the CAN message
  Serial.print("Received CAN message: ");
  Serial.println(message);

  // Process the received message (e.g., extract ID and data)
  int idIndex = message.indexOf("ID:0x") + 5;
  int dataIndex = message.indexOf("DATA:") + 5;

  String id = message.substring(idIndex, message.indexOf(' ', idIndex));
  String data = message.substring(dataIndex);

  // Print extracted ID and data
  Serial.print("Extracted ID: 0x");
  Serial.println(id);
  Serial.print("Extracted Data: ");
  Serial.println(data);
}
