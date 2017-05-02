# Rasperry Pi Workshop

## 000 download
**Rasbian Wheezy** <br />
<http://www.raspberrypi.org/downloads/>


## 001 terminal guide
**To update and fetch packages/dependencies**

	sudo apt-get update
	sudo apt-get upgrade
	
**To change your hostname** <br />
notes: ctrl+o to write out, ctrl+x to quit
	
	sudo nano /etc/hostname
	sudo nano /etc/hosts

## 002 file sharing && vnc
####Installing avahi-daemon

1. Install avahi-daemon

		sudo apt-get install avahi-daemon
		sudo update-rc.d avahi-daemon defaults
		sudo insserv avahi-daemon

#### File sharing and autodiscovery
Makes your Raspberry Pi viewable through Finder.
<http://4dc5.com/2012/06/12/setting-up-vnc-on-raspberry-pi-for-mac-access/>

2. Install netatalk

		sudo apt-get install netatalk

3. Then you can access with goto using Finder.

		⌘K afp://xxx.xxx.x.xx (pi ip)

4. Install network service discovery daemon. Add it to defaults.

		sudo apt-get install avahi-daemon
		sudo update-rc.d avahi-daemon defaults
	

5. Edit the afpd.service file:

		sudo nano /etc/avahi/services/afpd.service
		
	Paste this into the file and save it.
	
		<?xml version="1.0" standalone='no'?><!--*-nxml-*-->
		<!DOCTYPE service-group SYSTEM "avahi-service.dtd">
		<service-group>
		  	<name replace-wildcards="yes">%h</name>
		  	<service>
		     <type>_afpovertcp._tcp</type>
		     <port>548</port>
		  	</service>
		</service-group>

6. Then restart the daemon

		sudo /etc/init.d/avahi-daemon restart


#### VNC
	
	sudo apt-get install tightvncserver
	tightvncserver


<br/>
## 003 helpful commands

**Changing your password**. (The default username/password is pi/raspberry)
	
	passwd pi

**Release dhcp from wireless**

	sudo dhclient -v -r wlan0


**Get a new IP address**

	sudo dhclient -v wlan0
	
**Configure wifi from the command line** [see full instructions](http://www.raspberrypi.org/documentation/configuration/wireless/wireless-cli.md)

1. See list of available wifi networks

		sudo iwlist wlan0 scan
2. Edit wpa_supplicant

		sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
3. Reboot

		sudo reboot

	
**Address resolution protocol**

	ping 192.168.1.255
	arp -a

**nmap**
download: <http://nmap.org/book/inst-macosx.html>

	~!nmap
	
**Remove your ssh key** <br />
note: this is in case of emergency only ;)

	ssh-keygen -R raspberry.local


<br/>
## 004 openFrameworks
**getting started && compiling** <br />

*	<http://www.openframeworks.cc/setup/raspberrypi/Raspberry-Pi-Getting-Started.html>

**creative applications guide** <br />

*	<http://www.creativeapplications.net/tutorials/how-to-use-openframeworks-on-the-raspberrypi-tutorial/>


<br/>
## Types of Berries
Raspberry <br/>
Blackberry <br/>
Blueberry <br/>
Cranberry <br/>
Gooseberry <br/>
Huckleberry <br/>
Salmonberry <br/>
Strawberry <br/>
Elderberry <br/>
Goji Berry <br/>
and more... http://en.wikipedia.org/wiki/Category:Berries