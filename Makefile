ifneq ($(KERNELRELEASE),)
obj-m := proc_count.o
else
KDIR ?= /lib/modules/`uname -r`/build

PARENT=$(basename $(dirname $$PWD))

default:
	$(MAKE) -C $(KDIR) M=$$PWD modules

modules_install:
	$(MAKE) -C $(KDIR) M=$$PWD modules_install

install:
	$(MAKE) -C $(KDIR) M=$$PWD install

tar:
	tar -cf lab0-submission.tar proc_count.c README.md

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif
