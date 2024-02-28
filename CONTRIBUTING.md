Clean and simple code.

All function names in c and all label names in nasm must be lowercase. 
All names must be seperated by using a underscore before or between the names depending on the circumstance. 
All variables names must have a descriptive name.

If possible put all comments to the right of what you are explaining as if its nasm comments both in c and nasm. Unless it becomes too long then we have no choice but to put the comments overhead.

If a pointer is pointing to a pos in the buffer and gets incremented then its a name, underscore, pos. ex mark_pos.
Otherwise if its just a pointer to the base, then it would be name, underscore, ptr, because it just points to the buffer. ex mark_ptr.
With this we can say that one points to the buffer while the other is the pos from the base.

If presented with the problem: I would rather have a enums list then an array list. Since an enum list is more clear on whats going on then an array sometimes. 

When it comes to the make file. I would prefer it if you kept it to where the file names still show. I cant stand an overly wildcarded make. I get some of you are linux born and bred but it makes no sense readability wise to me.

Minimal to almost no encapsulation. I would rather have to, use more functions and take structs as args, then have overly encapsulated code that relys on everything else to work. Since the idea is 
to get it where we can switch out system modules connected to the core. The less encapsulation the better. If everything is reliant on everything then it would be heck trying to switch out a newer 
module. I mean just be mindful of what we are doing. When it comes to structs and encapsulating you just have to make sure that its worth doing. For instance I had to create color.c and create a struct 
for colors so we didnt have to pass 8 args to every function that used a background and foreground color. So in this instance I think it was worth being reliant on a struct to remove so many arg passes
but I am sure there are alot of things that dont need to be encapsulated.



