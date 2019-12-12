import time
import pygephi
import sys
import socket                
import sys
import zmq
context = zmq.Context()
s = context.socket(zmq.REP)
port = 196
s.bind(('',"196"))         
print "socket binded to %s" %(port) 
g = pygephi.GephiClient('http://localhost:8080/workspace1', autoflush=True)
g.clean()
count = 0
option=0
# Create the snake!
while True:
	node_attributes = {"size":10, 'r':1.0, 'g':0.0, 'b':0, 'x':1}
	data = s.recv()
	print "Recieved",data
	if data == "an":
		i = s.recv()
		print "add node",i
		node_attributes['y'] = (count%2)+1
		count+=1
		g.add_node(i,**node_attributes)
	elif data == "ae":
		s1 = s.recv()
		t = s.recv()
		print "add edge",s1+t
		g.add_edge(s1,s1,t)
	elif data == 'a':
		break
		


	c.close()
	


