#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

//uuid gen website https://www.uuidgenerator.net/version4
#define SERVICE_UUID "9ccabc1c-84ef-4728-8623-b04eaa51d6b9"
#define CHARACTERISTIC_UUID "7e87c72f-ab7e-4a77-8f5d-32e9e9c27c34"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting BLE");

  BLEDevice::init("ESP32BLESERVER"); //BLE device name
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);

  int charVal = 0;

  BLECharacteristic *pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);
  //pCharacteristic->setValue("HELLO WORLD");
  pCharacteristic->setValue(charVal);
  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("characteristic defined and advertising");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  //Serial.println(BLECharacteristic->readValue());

}
