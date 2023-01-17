# A Kernel Seedling

One sentence description

## Building

Explain how to build your kernel module
```shell
make
```
```shell
sudo insmod proc_count.ko
```

## Running

Explain how to run your kernel module and what to expect
```shell
/proc/count
````

## Cleaning Up

Explain how to remove your kernel module and clean up the code
```shell
sudo rmmod proc_count.ko
make clean
```

## Testing

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

