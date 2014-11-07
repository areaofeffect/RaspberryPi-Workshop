#Rasperry Pi Set Up

##Backing up your SD card

Plug your SD card in and run this command in Terminal

	diskutil list

This will show you the name of your disk to use in the following command in place of `{disk}`.  `path/to/image` can be anything you like.

	dd if=/dev/r{disk} of=/path/to/image bs=1m
	
##Restoring from previous back up

	sudo dd if=/path/to/image of=/dev/r{disk}
	
if you get ‘Resource Busy’

	df -h
	sudo diskutil unmount /dev/{disk}s1