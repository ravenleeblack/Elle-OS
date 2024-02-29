# Elle-OS

I have been programming for quite a few years in pure c and nasm. I have most of a compiler finished, for my own language Illeshian, without any tools so it was no surprise when my interest delved deeper and I found the love of os development. What can I say, I like a challenge, and I inspire to be like the original old school programmers who knew their stuff really well. 

Elle is a 32-bit Operating System. Im not looking to make a windows or linux clone, nor do I want to port their tools, into this os. I am having fun designing what I can without tools. 

Currently its does nothing but show some vesa graphics on the screen. I wasnt really trying to be the graphics first guy but it turned out to be easier then alot of other things.
So I wrote some functions, to at least, start testing stuff and start using the framebuffer without using the actual vesa's functions.

Right now I kind of have my ideas and terms in the wiki so check it out to learn more. I suppose I better find a better way to express my thoughts on there.

Currently have to pull all the files into the main folder to use the makefile since I dont know how to make it switch folders, or you can rewrite the make file.



![elle_os](https://github.com/ravenleeblack/Elle-OS/assets/76606152/62338810-4413-47a3-a214-1c31e8296587)


## IMPLEMENTED 
- Bootloader loads the core without relying on a file system.
- Switches to graphical mode.
- A few functions to write a mark, strand, or hex to screen using pixels.
- A few functions to draw elements onto screen using pixels.
- A few functions to color the foreground and background of text and elements.

## TODO
- Revert back and build a proper boot menu in nasm. I left the text mode code.
- Figure out how to properly set the vesa mode without hard coding it and get the infomation needed from vesa to use in c from nasm.
- Interrupts are shaky right now. So properly set up interrupts. Close to getting the keyboard working right.
- Multitasking with events and threads
- Sadule - Paging
- Core Mode (runs in ring0) and User Mode (runs in ring3) are separated
- File System
- System calls
- Mmap support
- Extend the framebuffer graphics
- Shared memory
- Serial port
- PS/2 mouse
- Terminal


current os inspirations:  

base kernel: https://github.com/dthain/basekernel. It has some clean code in most parts and a really nice system call system
even doe its overly encapsulated on everything and assembly is in gas.

visopsys: https://visopsys.org/. def way too encapsulated but the system is nice so I look once in a while to get inspired.

soso: https://github.com/ozkl/soso.


Feel free to reach out. Any help, explanations, or contributions would be much appreciated, not only in code, but in email as well.






