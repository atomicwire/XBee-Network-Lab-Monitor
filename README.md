# XBee-Network-Lab-Monitor
A network of sensors to monitor conditions in a lab setting and post alerts
The Lab Monitor Xbee network is designed to monitor a variety of conditions in the engineering labs

The system consists of a master data collection server and several clients all connected wirelessly through Xbee trancievers.
	Communication protocol is fairly simple(maybe). A combination of letters and numbers.Each client is assigned a letter. The server issues a query to the network which consists of a letter (addressing a single client) and a number (requesting a specific type of response) and a terminator (return, or some other control character). The Client responds with the same letter(to acknoledge the request) and data followed by a terminator.
	Configuration of the clients must be done at the client node through a hardware connection. Each client firmware must be archived in some location so that if the client fails it can be replaced.
	The data that the client collects from each sensor input is proccessed in the client firmware to determine a trigger which is assigned a priority. The server can quickly pole the system at different priority levels to determine if any actions need to be taken.


Client Hardware:
  The physical client is based on the ATmega328 proccessor running the Ardino operating system coupled with an Xbee tranciever. All the digital and analog inputs are connectored with 3 pin headers (GND, Vcc, Input). All sensors must connect to the client with this configuration.
	Sensors that may be part of the base client hardware could be motion sensor, light sensor, Computer Connected/ON/OFF USB input, Sound Level sensor, Vibration Level sensor.
	Other sensor inputs could include switch inputs, potentiometer inputs.
