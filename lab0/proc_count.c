#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

#define procfs_name "count"

// static ssize_t read_count(struct file *filePointer, char __user *buffer, 
//                              size_t buffer_length, loff_t *offset) 
// { 
// 	int *len = NULL;
// 	*len = 0;

// 	struct task_struct *task_list;
// 	char s[8];

// 	for_each_process(task_list) {
// 		*len  += 1;
// 	}
// 	printk(KERN_INFO "%d", *len);
// 	printk(KERN_INFO "%p", len);
// 	if (copy_to_user(buffer, len, sizeof(*len))) {
// 		printk(KERN_INFO "Failed to print number of processes to user");
// 	};

	
// 	return 0;
//     // char s[13] = "HelloWorld!\n"; 
//     // int len = sizeof(s); 
//     // ssize_t ret = len; 
 
//     // if (*offset >= len || copy_to_user(buffer, s, len)) { 
//     //     pr_info("copy_to_user failed\n"); 
//     //     ret = 0; 
//     // } else { 
//     //     pr_info("procfile read %s\n", filePointer->f_path.dentry->d_name.name); 
//     //     *offset += len; 
//     // } 
 
//     //return ret; 
// } 

// static const struct proc_ops proc_file_fops = { 
//     .proc_read = read_count, 
// }; 

static struct proc_dir_entry *count_proc_file;

static ssize_t count_proc_show(struct seq_file *filePointer, void *offset) {
	
}

static int __init proc_count_init(void)
{
	pr_info("proc_count: init\n");
	count_proc_file = proc_create_single_data(procfs_name, 0644, NULL, &show, 0);
	if (NULL == count_proc_file) {
		proc_remove(count_proc_file);
		pr_alert("Error:Could not initialize /proc/%S\n", procfs_name);
		return -ENOMEM;
	}

	pr_info("/proc/%s created\n", procfs_name);  
	return 0;
}

static void __exit proc_count_exit(void)
{
	pr_info("proc_count: exit\n");
	proc_remove(count_proc_file);
    pr_info("/proc/%s removed\n", procfs_name); 
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Anthony Chen");
MODULE_DESCRIPTION("Create a /proc/count file that shows the current number of running processes");
MODULE_LICENSE("GPL");
