# Elle-OS

I have been programming for quite a few years in pure c and nasm. I have most of a compiler finished, for my own language Illeshian, without any tools so it was no surprise when my interest delved deeper and I found the love of os development. What can I say, I like a challenge, and I inspire to be like the original old school programmers who knew their stuff really well. 

I would like to start Elle out being being a 32-bit multitasking os. I am not looking to make a windows or linux clone nor do I want to port their tools into this os. I am having fun designing what I can without tools. Currently its does nothing but show some vesa graphics on the screen. I wasnt really trying to be the graphics first guy but it turned out to be easier then alot of other things. So I wrote some functions, to at least, start testing stuff and start using the framebuffer without vesa's functions.

The bootloader currently loads the core up without being dependent on a file system to do it. The interrupt system is shaky but I think I am close to getting the keyboard working. Which is needed to start a terminal. Since there is graphics involved I suppose thats a good place to start. A nice graphical terminal. 

Since I dont know how to set the make file up for folder switching, you will have to pull all the files into the main folder to use, or rewrite the make file. Ill get there.



![elle_os](https://github.com/ravenleeblack/Elle-OS/assets/76606152/62338810-4413-47a3-a214-1c31e8296587)




current os inspirations:  

base kernel: https://github.com/dthain/basekernel. It has some clean code in most parts and a really nice system call system
even doe its overly encapsulated on everything and assembly is in gas.

visopsys: https://visopsys.org/. def way too encapsulated but the system is nice so I look once in a while to get ideas.

soso: https://github.com/ozkl/soso.


Feel free to reach out. Any help, explanations, or contributions would be much appreciated, not only in code, but in email as well.






