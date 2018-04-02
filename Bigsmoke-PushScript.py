import urllib2
import time
from datetime import datetime
from openhab import openHAB



# Set up the Arduino IP address
ArduinoIP = "172.16.2.44"
OpenHabURL = "http://172.16.2.41:8880/rest"

# Send startup message to show big smoke has launched the 
# script up


StartL1 = "Bigsmoke"
StartL2 = "Has+Started"

urllib2.urlopen('http://' + ArduinoIP + '?L1=' + StartL1 + '&L2=' + StartL2)

# Wait 5 secs to allow the message to be read
time.sleep(5)

#Main loop of code now
while True:
	
	#Current Time
	Time = datetime.now().strftime('%H:%M:%S')
	timeconnection = urllib2.urlopen('http://' + ArduinoIP + '?L1=Time+Is:' + '&L2=' + Time)
	timeconnection.close()
	print("Sent Time to Arduino")
	time.sleep(30)
	
	# Outside temp from OpenHAB
	openhab = openHAB(OpenHabURL)
	tempreq = openhab.get_item('weatherunderground_weather_9d9f927c_current_feelingTemperature')
	temp = str(float(tempreq.state))
	conditionreq = openhab.get_item('weatherunderground_weather_9d9f927c_current_conditions')
	condition = str(conditionreq.state)
	openhabconnection =  urllib2.urlopen('http://' + ArduinoIP + '?L1=Outdoor:' + '&L2=' + temp + 'C' + ' ' + condition)
	openhabconnection.close()
	print("Sent Temp to Arduino")
	time.sleep(30)
