#Raspberry Pi & Video


[http://http://www.gaggl.com/2013/01/installing-omxplayer-on-raspberry-pi/](http://http://www.gaggl.com/2013/01/installing-omxplayer-on-raspberry-pi/)

	sudo apt-get install omxplayer

Installing a version of omxplayer that has a somewhat working loop function

[http://omxplayer.sconde.net/](http://omxplayer.sconde.net/)

	sudo apt-get install libpcre3 fonts-freefont-ttf
	sudo apt-get install fbset
	cd /tmp
	sudo apt-get purge omxplayer
	wget http://omxplayer.sconde.net/builds/omxplayer_0.3.6~git20141024~98982df_armhf.deb
	dpkg -i omxplayer_0.3.6~git20141024~98982df_armhf.deb

		
