/*
 Name:		BidirectionalCommunicationEsp2Raspberry.ino
 Created:	6/28/2023 2:29:19 PM
 Author:	Imami Joel Betofe
*/

#include <HardwareSerial.h>

HardwareSerial espSerial(1);
float data[5] = { 1.23, 4.56, 7.89, 0.12, 3.45 };

void setup() {
    // Initialize the serial port at 115200 baud
    Serial.begin(115200);
    // Initialize the software serial port at 9600 baud
    espSerial.begin(9600, SERIAL_8N1, 18, 19);
}

void loop() {
    // Send the array of float values to the Raspberry Pi
    espSerial.write((byte*)data, sizeof(data));

    // Wait for a response from the Raspberry Pi
    while (espSerial.available() < sizeof(data))
        ;

    // Read the multiplied values from the Raspberry Pi
    espSerial.readBytes((char*)data, sizeof(data));

    // Print the received multiplied values
    for (int i = 0; i < 5; i++) {
        Serial.print("Received: ");
        Serial.println(data[i]);
    }

    delay(1000);
}

