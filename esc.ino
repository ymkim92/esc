#include <Servo.h>

Servo esc;
int input_degree;

void setup()
{
    Serial.begin(9600); // Comms with computer
    Serial.print("Started...\r\n");

    esc.attach(PWMOUT1);
}

void loop()
{
    Serial.print("Input your degree (0 - 179) for PWMOUT1: ");
    while (!Serial.available()) {}
    input_degree = Serial.parseInt();
    Serial.println(input_degree, DEC);
    esc.write(input_degree);
}

