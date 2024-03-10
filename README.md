# Elle-OS

I have been programming for quite a few years in pure c and nasm. I have most of a compiler finished, for my own language Illeshian, without any tools so it was no surprise when my interest delved deeper and I found the love of os development. What can I say, I like a challenge, and I inspire to be like the original old school programmers who really knew thier stuff. 

Elle is a 32-bit Operating System. I have been introducing some new concepts into Elle and/or changing some names to make some things make more sense in the over all understanding of the os. Im not looking to make a windows or linux clone, nor do I want to port their tools, into this os. I am having fun designing what I can without tools. I do however inspire to make it a somewhat legit and unique operating system.

Currently its shows some vesa graphics on the screen. I wasnt really trying to be the graphics first guy but it turned out to be easier then alot of other things. In the bootloader I have text mode commented out so its just as easy to use text mode for testing purposes as well. Since I am using graphics mode I wrote some functions, to at least, start testing stuff and start using the framebuffer without using the actual vesa's functions.

core.c is the main file and the entry point to the core.

Currently have to pull all the files into the main folder to use the makefile since I dont know how to make it switch folders, or you can rewrite the make file. I just recently started using the wsl2.

## IMPLEMENTED 
- Bootloader loads the core without relying on a file system.
- Switches to graphical mode.
- A few functions to write a mark, strand, or hex to screen using pixels.
- A few functions to draw elements onto screen using pixels.
- A few functions to color the foreground and background of text and elements.
- Easy to switch it to text mode and use text mode functions

## TODO
- Revert back and build a proper boot menu in nasm. I left the text mode code.
- Figure out how to properly set the vesa mode without hard coding it and get the infomation needed from vesa to use in c from nasm.
- Fix Interrupt System. The interrupts are shaky right now. Close to getting the keyboard working right.
- Multitasking with events and threads
- Implement the dule system
- Core Mode seperated from User Mode
- Archive Filing System (AFS)
- Root Archive seperated from Home Archive
- System calls
- Memory map support
- Extend the framebuffer graphics
- Serial port
- PS/2 mouse
- Terminal


current os inspirations:  
- base kernel: https://github.com/dthain/basekernel. 
- visopsys: https://visopsys.org/. 
- soso: https://github.com/ozkl/soso.

I have ideas, terms, and infomation in the wiki. I am still working on making the wiki look nicer and getting my thoughts collected into written form. Feel free to reach out. Any help, explanations, or contributions would be much appreciated, not only in the code, but in the discussions tab or email as well.






