#include "BLEDevice.h"

static BLEUUID serviceUUID("9ccabc1c-84ef-4728-8623-b04eaa51d6b9");
static BLEUUID charUUID("7e87c72f-ab7e-4a77-8f5d-32e9e9c27c34");

static boolean doConnect = false;
static boolean connected = false;
static boolean doScan = false;
static BLERemoteCharacteristic *pRemoteCharacteristic;
static BLEAdvertisedDevice *myDevice;



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
