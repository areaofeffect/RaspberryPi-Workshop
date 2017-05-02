# Raspberry Pi & Video


##### Installing from apt-get

	sudo apt-get install omxplayer

##### Installing the latest release of omxplayer (replace version number with the latest from [http://omxplayer.sconde.net/](http://omxplayer.sconde.net/))

	sudo apt-get install libpcre3 fonts-freefont-ttf libssh-4 
	sudo apt-get install fbset
	sudo apt-get purge omxplayer
	cd /tmp
	wget http://omxplayer.sconde.net/builds/omxplayer_0.3.6~git20141024~98982df_armhf.deb
	dpkg -i omxplayer_0.3.6~git20141024~98982df_armhf.deb

##### Installing a specially compiled version that seamlessly loops a single video with the `--loop` flag
Download [this compiled binary](https://www.dropbox.com/s/nlr6va3fq2pknq8/omxplayer-dist.tar.gz?dl=1) of omxplayer with the capability to seamlessly loop a video:

Extract the file and a folder called `omxplayer-dist` will appear. Then you can use Finder to log into your Pi for file sharing, drag 'omxplayer-dist' to your 'Home Directory'.

Next open Terminal,  and ssh in and make sure you are in the home directory with this command:

	  cd ~/

Run this to use this new version of omxplayer.

	  sudo cp -R omxplayer-dist/* /

To make sure you have the right version installed type this command.

	  omxplayer --version

You should see this:

	  omxplayer - Commandline multimedia player for the Raspberry Pi
	        Build date: Tue, 11 Nov 2014 20:41:26 +0000
	        Version   : c39997b [seamless-looping]
	        Repository: UNKNOWN



Now seamlessly looping a video should work with this command.

	  omxplayer --loop {path to your video here}
		
