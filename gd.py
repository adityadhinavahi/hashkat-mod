import time
import pygephi
import sys
import socket                
import sys
from CppPythonSocket import Server
server = Server('127.0.0.1',3420)        
g = pygephi.GephiClient('http://127.0.0.1:8080/workspace1', autoflush=True)
g.clean()
count = 0
option=0
node_attributes = {"size":10, 'r':1.0, 'g':0.0, 'b':0, 'x':1}
node_attributes['y'] = (count%2)+1
#g.add_node("0",**node_attributes)
count+=1
edge_count = 1
print "add node 0"
# Create the snake!
while True:
	server.conn , server.addr = server.s.accept()
	while True:
		node_attributes = {"size":10, 'r':1.0, 'g':0.0, 'b':0, 'x':1, "timestamp":time.time()}
		edge_attributes = {"timestamp":time.time()}
		data = server.receive()
		#print "Recieved",data
		if data == "an":
			i = server.receive()
			print "add node",i
			node_attributes['y'] = (count%2)+1
			count+=1
			g.add_node(i,**node_attributes)
	
		elif data == "ae":
			s1 = server.receive()
			t = server.receive()
			print "add edge",s1,'-',t
			g.add_edge(edge_count,s1,t,**edge_attributes)
			edge_count = edge_count + 1
		elif data == 'exit':
			print "exit"
			exit(0)
	
		elif data=="a":
			break
	server.conn.close()



