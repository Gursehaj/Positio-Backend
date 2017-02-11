import serial
import time
import requests
ser = serial.Serial('/dev/ttyACM0',9600)
oldv=ser.read()
while True:
	
	read_serial=ser.read()
	if read_serial=='u' and oldv!='u':
		requests.post('http://www.akshaybaweja.com/positio/index.php?request=set&ultra1=0&ultra2=0')
		print('   Ping U')
	elif read_serial=='c' and oldv!='c':
		requests.post('http://www.akshaybaweja.com/positio/index.php?request=set&ultra1=1&ultra2=1')		
		print('   Ping C')
	elif read_serial=='i' and oldv!='i':
		requests.post('http://www.akshaybaweja.com/positio/index.php?request=set&ultra1=1&ultra2=0')		
		print('   Ping i')
	oldv=read_serial
