import subprocess
import time

# Step 1: Bind rfcomm to ESP32
device_mac = "8C:4F:00:3C:9C:46"  # Replace with your ESP32 MAC address

def bind_rfcomm():
    try:
        subprocess.run(["rfcomm", "release", "rfcomm0"], stderr=subprocess.DEVNULL)
        subprocess.run(["rfcomm", "bind", "rfcomm0", device_mac], check=True)
        print("rfcomm bound to ESP32")
    except subprocess.CalledProcessError:
        print("Failed to bind rfcomm")
        exit(1)

# Step 2: Send "1" to the ESP32 via serial
def send_data():
    try:
        with open("/dev/rfcomm0", "w") as bt:
            bt.write("1")
            bt.flush()
            print("Sent '1' to ESP32")
    except Exception as e:
        print(f"Error sending data: {e}")

# Step 3: Main
bind_rfcomm()
time.sleep(2)  # Wait for connection to stabilize
send_data()
