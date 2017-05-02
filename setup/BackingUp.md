# Raspberry Pi Backup

## Backing up your SD card

Plug your SD card in and run this command in Terminal

	diskutil list

This will show you the number of your disk to use in the following command in place of `{x}`.  `path/to/image` can be anything you like. You will use the image it creates to restore your disk, or quickly make copies of it. *The r before disk stands for raw and will make the operation go faster.*

	sudo dd if=/dev/rdisk{x} of=/path/to/image bs=1m
	
## Restoring from previous back up

	sudo dd if=/path/to/image of=/dev/rdisk{x} bs=5m
	
if you get ‘Resource Busy’

	df -h
	sudo diskutil unmount /dev/disk{x}s1

To see the progress of your back up or restore press `ctrl+t` in Terminal.
