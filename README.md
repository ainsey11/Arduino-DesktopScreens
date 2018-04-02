# Arduino-DesktopScreens

This is a simple program written for an Arduino Uno, but will probably run on other boards. It takes strings from a web client (like a browser or curl) and display the contents on an LCD screen.

Designed to be used with a 16x2 Cheap ebay LCD that utilizes I2C for comms rather than the old fashioned, pin hungry method and an Ethernet shield.

## Config

 1. Change IP / Netmask / Gateway on lines 13 > 18
 2. Hook up an LCD via the I2C method, I used pins A4/A5 and the 5v/GND on the arduino for power.
 3. Configure the I2C address on line 20 for your LCD
 4. Configure pins as required on lines 21 > 28
 5. Compile and upload!


## Usage
You can visit the IP address you assigned your Arduino in a web browser, then manually enter what you would like displayed. Or you can submit a command line request. For example :

    (Linux) curl "http://172.16.2.44/?L1=Ainsey&L2=Potato"
    (Windows Powershell) Invoke-WebRequest "http://172.16.2.44/?L1=Ainsey&L2=Potato"

## Bugs
I found chrome decides to send weird data as part of the web request, I have no idea why this is, but it's stupid and annoying. I've attempted to combat it with some str.replace()'s but I obviously can't quite beat the overlords at google. It works fine in IE / Firefox / Vivaldi / Opera so I'm happy to say I'm not going to spend ages bugfixing the chrome issue. If someone else wants to, feel free to raise a PR.

## Jenkins deploys
This project will work with Jenkins, I have just made it slightly friendlier to the average github user.
I found the best method of deploying to arduino via jenkins is to plug the usb of the arduino into a linux box (this can be the jenkins server itself) and installing the python based inotool.

1. Create a structure as follows

    |
	|-Src
		|sketch.ino
		|other libraries in git repo
	|-Lib
		| <empty dir> 
	
	This is the same structure you would get if you did an ino init
2. Test the build via ino build
3. Test the upload via ino upload

The best way I found to do it is to get jenkins to have non passworded sudo access to run ino, then copy the files to the linux box, and run the above commands as a jenkins-deploy user.
    
the build step, execute shell would look like this :
  
    cd /var/lib/jenkins/workspace/;
	chmod 777 -R Arduino-DesktopScreens/;
	cd Arduino-DesktopScreens;
	sudo ino upload;
I found builds take around between 4 and 8 seconds, pulling the repo from github.com