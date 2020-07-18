FNAME=test
obj-m += $(FNAME).o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	sudo dmesg -C 
	sudo insmod $(FNAME).ko
	sudo rmmod $(FNAME).ko
	dmesg