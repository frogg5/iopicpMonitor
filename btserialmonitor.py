import bluetooth

esp32 = "ESP32-BT"
address = "8C:4F:00:3C:9C:46"

devices = bluetooth.discover_devices(lookup_names=True)
print(devices)
#for addr in devices:
#	if esp32 == bluetooth.lookup_name(addr):
#		address = addr
#		print("Address:", address)
#		break

port = 4
#sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
sock = bluetooth.BluetoothSocket()
sock.connect((address,port))
sock.send(bytes(12))
sock.close()