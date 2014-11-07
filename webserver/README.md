#Raspberry Pi as a Web Server


##001: Install Node.js
Install Node.js on the Raspberry Pi using [Node Version Manager (nvm)](https://github.com/creationix/nvm) and get it running when you start up your Pi.

1. Make sure your Pi has a c++ compiler installed. You can do this by running the following three commands.

		sudo apt-get update
		sudo apt-get upgrade
		sudo apt-get install git-core build-essential

2. Install nvm and source it. 

		git clone https://github.com/creationix/nvm.git ~/.nvm
		source ~/.nvm/nvm.sh

3. Use nvm to install the version of node you'd like to use. Double check that the version you want has a binary available for the Raspberry Pi. [Click on the version you want in this list](http://nodejs.org/dist/) and make sure the folder contains a file with `linux-arm-pi.tar.gz` in the file path. We will install v0.0.10.28 and set it as the default with these two commands.

		nvm install 0.10.28
	    nvm alias default 0.10.28
4. Now let's save these settings so that when you reboot you can automatically use the nvm command in the terminal and your default version of node will be used. We edit `~/.bashrc` and `~/.profile` using the following commands.

	```
	sudo nano ~/.bashrc
	sudo nano ~/.profile
	```
	
	Add these two lines at the bottom of each file.	
	
	```
	source ~/.nvm/nvm.sh
	nvm use default
	```

##002: Build a web site and serve it from your Pi
Build a web site and serve it from your Raspberry Pi

A pre-built web site is available here (link). Or if you want to build your own we can quickly scaffold a web app with [Yeoman](http://yeoman.io/learning/)
Quick scaffolding with Yeoman

	sudo npm install -g yo
	npm install -g grunt-cli
	npm install -g bower
	mkdir my-yo-project
	cd my-yo-project
	yo webapp
To test locally:

	grunt serve
To compile for distribution:

	grunt dist
	
*You can scaffold right on your Pi with Yeaomn but npm installs and grunt are very slow. There are also compatibility issues with some npm modules. For example, [compiling your web app for distribution](https://github.com/yeoman/generator-webapp/issues/348) requires a version of PhantomJS specifically compiled for the [Raspberry Pi](https://github.com/aeberhardo/phantomjs-linux-armv6l)*

Ok, let's take that simple web app and serve it. Make a [simple Express.js file](https://github.com/justpitbulls/RaspberryPi-Workshop/blob/master/webserver/files/server.js) and put it in your distribution folder.

Copy all of the distribution files over to your ~/Documents/my-yo-project directory. Then in terminal set up your packages.

	cd ~/Documents/my-yo-project
	npm install express --save

And run the site which will be viewable at `http://localhost:8080` on the Pi, or `http://{your pi name}.local:8080` from any other computer on the same network.

	node server.js	

##003: Automatically serve your web site on start up
To set up your web site to automatically launch itself when you boot your Pi up, we will add a shell script to the /etc/init.d folder.

To create a new script you can use the following command. [Here's](https://github.com/justpitbulls/RaspberryPi-Workshop/blob/master/webserver/files/autolaunch.txt) some text to enter.

	sudo nano /etc/init.d/mynodeserver

Next modify it's permissions so that is executable
	sudo chmod +x /etc/init.d/mynodeserver

You can use these commands to start/stop the process defined in your script

	sudo /etc/init.d/mynodeserver start
	sudo /etc/init.d/mynodeserver stop

If you had some trouble executing these commands it was probably a result of node not being availble from your $PATH. Type in the following command

	which node

The result is likely pointing to your /home folder which is not accessible to init.d scripts. Let's make some sym links in order to get this to run:

	n=$(which node);n=${n%/bin/node}; chmod -R 755 $n/bin/*; sudo cp -r $n/{bin,lib,share} /usr/local

Once this is complete test the previous commands again. 

Now that we have that working we can add it to the default scripts and this will make it auto launch when you boot up.

	sudo update-rc.d mynodeserver defaults
	sudo reboot










