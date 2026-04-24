obj-m := rt_port.o
rt_port-y := rt_sample_port.o rt_mem_pool.o

# kernel build dizini
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

ccflags-y := -Wall -Werror

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean