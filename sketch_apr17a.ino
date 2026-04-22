#include <Wire.h>
#define Addr 0x78

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  delay(300);
}

void loop()
{
  unsigned int data[4];

  // Request 4 bytes of data
  Wire.requestFrom(Addr, 4);

  // Read 4 bytes of data
  // pressure msb, pressure lsb, temp msb, temp lsb
  if (Wire.available() == 4)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
    data[2] = Wire.read();
    data[3] = Wire.read();
  }

  // Convert the data
  float pressure = ((data[0] & 0xFF) * 256 + (data[1] & 0xFF));
  float temp = ((data[2] & 0xFF) * 256 + (data[3] & 0xFF));
  Serial.println("========================");
  Serial.print("Pressure float: ");
  Serial.println(pressure);

  pressure = ((pressure - 3277.0) / ((26214.0) / 0.8)); // - 0.8;
  pressure = (pressure + 0.0278) / 1.124;
  float cTemp = ((temp - 3277.0) / ((26214.0) / 110.0)) - 25.0;
  float fTemp = (cTemp * 1.8 ) + 32;

  // Output data to serial monitor
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" PSI");

  delay(500);

  /*
  Serial.print("Temperature in Celsius : ");
  Serial.print(cTemp);
  Serial.println(" C");
  Serial.print("Temperature in Fahrenheit : ");
  Serial.print(fTemp);
  Serial.println(" F");
  delay(500); */
}