import socket

server = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)

server.bind((("74:97:79:88:42:1a"), 4)) 
server.listen(1)
#74:97:79:88:42:1a laptop bt adapter MAC address

client, addr = server.accept()

try:
	while True: 
		data = client.recv()
		if not data:
			break
		print(f"message: {data.decode('utf-8')}")
		message = input("Enter message:")

		client.send(message.encode("utf-8"))

except OSError as e:
	pass

client.close()
server.close()