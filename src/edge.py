import time
import pygephi
import sys
import socket                
import sys
from CppPythonSocket import Server
server = Server('127.0.0.1',3421)
g = pygephi.GephiClient('http://127.0.0.1:8080/workspace1', autoflush=True)
while True:
	server.conn , server.addr = server.s.accept()
	while True:
		if data == "a":
			s1 = server_one.receive()
			t = server.receive()
			print "add edge",s1,'-',t
			g.add_edge(s1,s1,t)
