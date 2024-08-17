#include<linux/module.h>
#include<linux/init.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Johannes 4 GNU/Linux");
MODULE_DESCRIPTION("A hello world LKM");

/**
 * @brief This function is called, when the module is loaded into the kernel
 */

static int __init sample_init(void) {
        printk("HPDBG mymodule is initialized\n");
        return 0;
}


/**
 * @brief This function is called, when the module is removed from the kernel
 */

static void __exit sample_exit(void) {
        printk("HPDBG Goodbye, kernel\n");
}

module_init(sample_init);
module_exit(sample_exit);

