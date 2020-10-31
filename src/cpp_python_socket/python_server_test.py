from python.CppPythonSocket.server import Server


if __name__ == "__main__":
  server = Server("127.0.0.1", 5002)
  message = server.receive()
  print("[Client]:", message)
  server.send("Shut up and send an image")


