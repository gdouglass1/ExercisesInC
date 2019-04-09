1. Where is GLib from and why does it exist? Who uses it, and for what? Would it have been better if they had given it a name less likely to be confused with glibc?

 GLib began as part of the GTK+ project, now named GTK. It was originally part of a graphical window system and the graphical interface features are separated from the data structure later and is now GLib. GLib is a bundle of three (formerly five) low-level system libraries written in C and developed mainly by GNOME. GLib provides advanced data structures, such as memory chunks, doubly and singly linked lists, hash tables, dynamic strings and string utilities.

2. What are the most important pros and cons of using GLib, as opposed to another library, or just using core C features?

  pros: GLib has many useful data structures as portable libraries. It allows you to have access to data structure common to higher level programming languages.

  cons: GLib is not as good as Apr for network programming things. APR is also a larger library. Many glib functions will return values as objects that have been allocated from heap space, whereas hardly any standard library functions will allocate memory for their return values. The glib approach allows greater flexibility in how functions operate but also requires that the programmer eventually free up that allocated memory.

3. What do you have to do to compile and run a "Hello GLib" example?

  To compile, you need t o tell the compiler where to find the GLib header files and libraries. This is done with the pkg-config utility. The simplest way to compile a program is to use the "backticks" feature of the shell. If you enclose a command in backticks. The command is: `gcc hello.c `pkg-config --cflags --libs glib-2.0` -o hello`.
