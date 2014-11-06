#Rasperry Pi

## 000 download
**Rasbian Wheezy** <br />
<http://www.raspberrypi.org/downloads/>


<br/>
## 001 terminal guide
**To update and fetch packages/dependencies** <br />

`~sudo apt-get update` <br />
`~sudo apt-get upgrade`
	
**To change your hostname** <br />
notes: ctrl+o to write out, ctrl+x to quit
	
`~sudo nano /etc/hostname` <br/>
`~sudo nano /etc/hosts`

<br/>
## 002 file sharing && vnc
####Installing avahi-daemon <br />

`~sudo apt-get install avahi-daemon` <br />
`~sudo update-rc.d avahi-daemon defaults` <br />
`~sudo insserv avahi-daemon` <br />

####File sharing and autodiscovery <br />
Makes your Raspberry Pi viewable through Finder. <br />
<http://4dc5.com/2012/06/12/setting-up-vnc-on-raspberry-pi-for-mac-access/>

`~sudo apt-get install netatalk` <br />

Then you can access with goto using Finder. <br />

`⌘K afp://xxx.xxx.x.xx (pi ip)` <br />

Install network service discovery daemon. <br />

`~sudo apt-get install avahi-daemon`  <br />
`~sudo update-rc.d avahi-daemon defaults` <br />
`~sudo nano /etc/avahi/services/afpd.service` <br />

Then paste this in:

	<?xml version="1.0" standalone='no'?><!--*-nxml-*-->
	<!DOCTYPE service-group SYSTEM "avahi-service.dtd">
	<service-group>
	  	<name replace-wildcards="yes">%h</name>
	  	<service>
	     <type>_afpovertcp._tcp</type>
	     <port>548</port>
	  	</service>
	</service-group>

`~sudo /etc/init.d/avahi-daemon restart` <br />


####VNC <br />
	
`~sudo apt-get install tightvncserver` <br />
`~tightvncserver`


<br/>
## 003 helpful commands

**Changing your password** <br />
	
`~passwd pi` <br />


**Release dhcp from wireless** <br />
`~sudo dhclient -v -r wlan0`


**Get a new IP address** <br />
`~sudo dhclient -v wlan0`

**Address resolution protocol** <br />	
`~ping 192.168.1.255`
`~arp -a`

**nmap** <br />
download: <http://nmap.org/book/inst-macosx.html> <br />
`~!nmap`
	
**Remove your ssh key** <br />
note: this is in case of emergency only ;) <br />
`~ssh-keygen -R raspberry.local`


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