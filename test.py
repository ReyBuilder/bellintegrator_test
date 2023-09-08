import socket

try:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.connect(("localhost", 28888))

        print(client_socket.recv(255).decode("utf-8"))

        while(1):
            query = input()
            if query == 'q':
                break
            client_socket.send(bytes(query, "utf-8"))
            print(client_socket.recv(255).decode("utf-8"))

except Exception as e:
    print(e)
