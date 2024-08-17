#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Johannes 4 GNU/Linux");
MODULE_DESCRIPTION("Registers a device nr. and implement some callback functions");

static struct class *myClass;
static struct device *myDevice;

/**
 * @brief This function is called, when the device file is opened
 */
static int driver_open(struct inode *device_file, struct file *instance) {
	printk("dev_nr - open was called!\n");
	return 0;
}

/**
 * @brief This function is called, when the device file is closed
 */
static int driver_close(struct inode *device_file, struct file *instance) {
	printk("dev_nr - close was called!\n");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};

#define MYMAJOR 169 /* Max 511 */
/* Registered device numbers can be seen on cat /proc/devices */

/**
 * @brief This function is called, when the module is loaded into the kernel
 */
static int __init ModuleInit(void) {
	int retval;
	printk("Hello, Kernel!\n");

	/* register device nr. */
	retval = register_chrdev(MYMAJOR, "my_dev_nr", &fops);

	/* if you don't know which major number to give you can register device below method:
	 * int major_number;
	 * major_number = register_chrdev(0, "my_dev_nr", &fops);
	 * if (majorNumber < 0) {
         *     pr_alert("Failed to register a major number\n");
         *     return majorNumber;
         * }
         * pr_info("Registered with major number %d\n", majorNumber);
	 * */

	if(retval == 0) {
		printk("dev_nr - registered Device number Major: %d, Minor: %d\n", MYMAJOR, 0);
	}
	else if(retval > 0) {
		printk("dev_nr - registered Device number Major: %d, Minor: %d\n", retval>>20, retval&0xfffff);
	}
	else {
		printk("Could not register device number!\n");
		return -1;
	}

	/* After device entry is created in /proc/devices we need to create device file in /dev, this can be done in two ways:
	 * 1. After the entry is created in /proc/devices we need to create device file entry manually using below command:
	 * sudo mknod /dev/<filename> c <majornumber> <minornumber>
	 * 2. We can create the device file from code itself by creating class and device files like shown below:
	 * */

	myClass = class_create(THIS_MODULE, "mydevice_class");
	if (IS_ERR(myClass)) {
            unregister_chrdev(MYMAJOR, "mydevice");
            printk("Failed to register device class\n");
            return PTR_ERR(myClass);
        }

	myDevice = device_create(myClass, NULL, MKDEV(MYMAJOR, 0), NULL, "mydevice");
	if (IS_ERR(myDevice)) {
            class_destroy(myClass);
            unregister_chrdev(MYMAJOR, "mydevice");
            printk("Failed to create the device\n");
            return PTR_ERR(myDevice);
        }

	printk("Device class and Device file created successfully\n");
	return 0;
}

/**
 * @brief This function is called, when the module is removed from the kernel
 */
static void __exit ModuleExit(void) {
	unregister_chrdev(MYMAJOR, "my_dev_nr");
	printk("Goodbye, Kernel\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
