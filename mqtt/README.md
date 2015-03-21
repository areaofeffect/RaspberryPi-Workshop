#Installing MQTT

##Option 1: Build from source

[http://www.xappsoftware.com/wordpress/2014/10/27/installing-mosquitto-on-raspberry-pi/](http://www.xappsoftware.com/wordpress/2014/10/27/installing-mosquitto-on-raspberry-pi/)

##Option 2: Install Debian package

[http://mosquitto.org/2013/01/mosquitto-debian-repository/](http://mosquitto.org/2013/01/mosquitto-debian-repository/)

Then you will also need to install these

	sudo apt-get install mosquitto python-mosquitto
	sudo apt-get install mosquitto-clients

##Use it in a python script
	pip install paho-mqtt
[Documenation](https://pypi.python.org/pypi/paho-mqtt)

##Control LEDs from anywhere
Example coming soon
