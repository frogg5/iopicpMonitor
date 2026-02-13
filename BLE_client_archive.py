import asyncio
from bleak import BleakScanner
from bleak import BleakClient

async def main():
    devices = await BleakScanner.discover()
    for device in devices:
        print(device)

    #ble_address = "9ccabc1c-84ef-4728-8623-b04eaa51d6b9"
    ble_address = "8C:4F:00:3C:9C:46"
    characteristic_uuid = "7e87c72f-ab7e-4a77-8f5d-32e9e9c27c34"

    async with BleakClient(ble_address) as client:
        data = await client.read_gatt_char(characteristic_uuid)
        print("Read data:")
        print(data)
        print(int.from_bytes(data))

    async with BleakClient(ble_address) as client:
        data = await client.read_gatt_char(characteristic_uuid)
        data[0] = 1
        await client.write_gatt_char(characteristic_uuid, data)
        print("new data written")

    async with BleakClient(ble_address) as client:
        data = await client.read_gatt_char(characteristic_uuid)
        print("Read data 2:")
        print(data)
        print(int.from_bytes(data))
    

asyncio.run(main())

