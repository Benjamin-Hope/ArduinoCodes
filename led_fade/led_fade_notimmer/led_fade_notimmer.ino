int led = 9;           // PWM pin for the LED
int brightness = 0;     // Setting the brightness of the LED in %
int fadeAmount = 5;     // Fading step (0-255)
int previousBrightness = -1;  // Variable to store the previous brightness

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // Check if there is data available on the serial port
  while(Serial.available()) {
    // Read the integer value from the serial port
    int integerPercentage = Serial.parseInt();

    // Check if the value is within the valid range (0-100)
    if (integerPercentage > 0 && integerPercentage <= 100) {
      // Map the percentage to the PWM range (0-255)
      brightness = map(integerPercentage, 0, 100, 0, 255);
      
      // Check if the new brightness is different from the previous one
      if (brightness != previousBrightness) {
        // Update the LED brightness
        analogWrite(led, brightness);

        //
        // Print the new brightness to the serial port
        Serial.print("New brightness: ");
        Serial.println(brightness);

        // Update the previous brightness
        previousBrightness = brightness;
      }}
    else if (integerPercentage == 0){
      Serial.println("Type 200 to set the led to 0");
    }else if (integerPercentage == 200){
      analogWrite(led, LOW);
    } else {
      // Print an error message if the value is out of range
      Serial.println("Invalid brightness value. Please enter a value between 0 and 100.");
    }
  }

  // Add a short delay to avoid overwhelming the serial port

}
