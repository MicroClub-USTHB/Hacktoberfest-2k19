from program import *
import socket, sys, threading
from time import sleep

degre_poly=5


if __name__=="__main__":
	Peers=['192.168.1.12']#,'192.168.1.2','192.168.1.3','192.168.1.4','192.168.1.5','192.168.1.6']
	id_peers=[1,2,3,4,5,6]
	
	host, port = '127.0.0.1', 4444
	mysocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	mysocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	#f=open("choix","r")
	#vote=f.readline()
	#vote=vote.strip("\n")
	#f.close()
	liste=generate_couples_of_shares(1,1)
	data=open("fichierSecret","w")
	j=0
	for item in liste:
		data.write("pc"+Peers[j]+":("+str(item[0])+","+str(item[1])+")")
		mysocket.connect((Peers[j], port))
		mysocket.send(str(item[0])+","+str(item[1]))
		j+=1
		
	

#liste=[[1, 12], [2, 118], [3, 596], [4, 2034], [5, 5452], [6, 12422]]
        
    #recevoir vote 
    #liste=generate_couples_of_shares(vote,degre_poly)  ==>  generate_polynom_of_secret(vote,degre_poly)
    #envoyer chaque element de la liste l moulah
    #recevoir les shares des autres ==> liste_recu
    #idf,a_envoyer = idf,calcule_somme_locale(liste_recu)
    #recevoir somme de chaque personne ==> liste_somme
    #x=calcule_secret(liste_somme,N)
    #print x
