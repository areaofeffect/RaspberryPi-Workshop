#Rasperry Pi as a Web Server

##Step 1: Install Node.js
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
4. Now let's save these settings so that when you reboot you can automatically use the nvm command in the terminal and your default version of node will be used. Add these two lines to ~/.bashrc and ~/.profile

	  `source ~/.nvm/nvm.sh`

	  `nvm use default`
	
		sudo nano ~/.bashrc
		sudo nano ~/.profile
		sudo reboot

##Step 2: Build a web site and serve it from your Pi
Build a web site and serve it from your Raspberry Pi

A pre-built web site is available here (link). Or if you want to build your own we can quickly scaffold something with [Yeoman](http://yeoman.io/learning/)
Quick scaffolding with Yeoman

	sudo npm install -g yo
	npm install -g grunt-cli
	npm install -g bower
	mkdir my-yo-project
	cd my-yo-project
	yo webapp
	grunt serve
	
Make a simple Express.js file to run this front end code. (link to file)

You can this type of development on your Pi but it is very slow and there are some issues with some npm modules. For example, [compiling your web app for distribution](https://github.com/yeoman/generator-webapp/issues/348) requires a version of PhantomJS specifically compiled for the [Raspberry Pi](https://github.com/aeberhardo/phantomjs-linux-armv6l)

Copy the web site files over to your ~/Documents directory. And run this command in the folder.

	npm install express --save

Then launch the site locall

	node server.js	

##Step 3: Automatically serve your web site on start up
Make it run automatically on launch. ... more explanation about writing upstart scripts

	sudo nano /etc/init.d/mynodeserver
	sudo chmod +x /etc/init.d/mynodeserver
	sudo /etc/init.d/mynodeserver start
	which node
make some sym links (add more info about why this is needed):

	n=$(which node);n=${n%/bin/node}; chmod -R 755 $n/bin/*; sudo cp -r $n/{bin,lib,share} /usr/local

	sudo /etc/init.d/mynodeserver start
	sudo /etc/init.d/mynodeserver stop
	sudo update-rc.d mynodeserver defaults
	sudo reboot










