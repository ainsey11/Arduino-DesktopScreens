import urllib2
import time
from datetime import datetime


# Set up the Arduino IP address
ArduinoIP = "172.16.2.44"


# Send startup message to show big smoke has launched the 
# script up

StartL1 = "Bigsmoke"
StartL2 = "Has+Started"

urllib2.urlopen('http://' + ArduinoIP + '?L1=' + StartL1 + '&L2=' + StartL2)



