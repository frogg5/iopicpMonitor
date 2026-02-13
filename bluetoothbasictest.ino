#include "BluetoothSerial.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"


BluetoothSerial serialBT;

char cmd;

void printDeviceAddress() {
 
  const uint8_t* point = esp_bt_dev_get_address();
 
  for (int i = 0; i < 6; i++) {
 
    char str[3];
 
    sprintf(str, "%02X", (int)point[i]);
    Serial.print(str);
 
    if (i < 5){
      Serial.print(":");
    }
 
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serialBT.begin("ESP32-BT");
  Serial.println("ready to pair bt");
  printDeviceAddress();
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(serialBT.available()){
    cmd = serialBT.read();
    Serial.println(cmd);
  }

  //Serial.println(cmd);

  if(cmd=='1'){
    digitalWrite(2, HIGH);
    Serial.println("1");
  }
  if(cmd=='2'){
    digitalWrite(2, LOW);
    Serial.println("0");
  }

  delay(20);

}
