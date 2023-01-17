# A Kernel Seedling

One sentence description

## Building

Explain how to build your kernel module
Compile source file
```shell
make
```
Insert Kernel Module into the kernel
```shell
sudo insmod proc_count.ko
```

## Running

Explain how to run your kernel module and what to expect
```shell
cat /proc/count
````
This will print out an integer representing the number of running processes

## Cleaning Up

Explain how to remove your kernel module and clean up the code
Remove Kernel Module from the kernel
```shell
sudo rmmod proc_count.ko
```
Clean our the compiled files
```shell
make clean
```

## Testing

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

