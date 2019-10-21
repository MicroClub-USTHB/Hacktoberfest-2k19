#serveur secret
import socket, threading, os
from time import sleep

host, port = '192.168.1.34', 5555
mysocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
mysocket.bind((host, port))
print(' Server is ready ..')
recu=1;
while (recu):
	mysocket.listen(5)
	conn, addr = mysocket.accept()
	file_name = 'somme2.txt' 
	fisomme = open(file_name, 'a')
	data=conn.recv(1024)
	fisomme.write(str(data)+"\n")
	recu-=1
	print data
fisomme.close()
file_name = 'somme2.txt' 
fisomme = open(file_name, 'r')
sommes=fisomme.read()
print sommes
