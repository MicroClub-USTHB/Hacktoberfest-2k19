#serveur secret
import socket, threading, os
from time import sleep
from program import *

host, port = '192.168.1.34', 4444
mysocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
mysocket.bind((host, port))
print(' Server is ready ..')
recu=1;
while (recu):
	mysocket.listen(5)
	conn, addr = mysocket.accept()
	file_name = 'secret.txt' 
	secret = open(file_name, 'a')
	data=conn.recv(1024)
	secret.write(str(data)+"\n")
	recu-=1
	print recu
secret.close()
secret=open("secret.txt","r")
data=secret.readline().split("\n")
liste=[]
while(data[0]!=""):
	print data[0]
	data2=data[0].split(",")
	print data2
	liste.append(data2)
	data=secret.readline().split("\n")

Somme=calcule_somme_locale(liste)
print Somme
file_name = 'somme.txt' 
fisomme = open(file_name, 'a')
fisomme.write(str(Somme)+"\n")
fisomme.close()

Peers=['192.168.1.12']#,'192.168.1.2','192.168.1.3','192.168.1.4','192.168.1.5','192.168.1.6']
host, port = '127.0.0.1', 5555
mysocket2 = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysocket2.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

for i in Peers:
	mysocket2.connect((i, port))
	mysocket2.send(str(Somme))








