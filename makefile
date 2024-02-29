all: elle.flp

osboot.o: osboot.asm
	nasm -f elf32 osboot.asm -o osboot.o

osload.o: osload.asm
	nasm osload.asm -f elf32 -o osload.o

core.o: core.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c core.c -o core.o

font.o: font.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c font.c -o font.o

gdt.o: gdt.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c gdt.c -o gdt.o

idt.o: idt.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c idt.c -o idt.o

service.o: service.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c service.c -o service.o

memory.o: memory.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c memory.c -o memory.o

port_hub.o: port_hub.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c port_hub.c -o port_hub.o

keyboard.o: keyboard.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c keyboard.c -o keyboard.o

request.o: request.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c request.c -o request.o

clock.o: clock.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c clock.c -o clock.o

core_malloc.o: core_malloc.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c core_malloc.c -o core_malloc.o

draw_element.o: draw_element.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c draw_element.c -o draw_element.o

main_frame.o: main_frame.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c main_frame.c -o main_frame.o

sub_frame.o: sub_frame.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c sub_frame.c -o sub_frame.o

color.o: color.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c color.c -o color.o

frame_bitmap.o: frame_bitmap.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c frame_bitmap.c -o frame_bitmap.o

terminal.o: terminal.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c terminal.c -o terminal.o

screen.o: screen.c
	gcc -m32 -fno-pie -Wall -ffreestanding --no-builtin -nostdinc -nostdlib -c screen.c -o screen.o

core.bin: core.o osload.o osboot.o font.o gdt.o idt.o service.o memory.o port_hub.o keyboard.o request.o clock.o core_malloc.o draw_element.o main_frame.o sub_frame.o color.o frame_bitmap.o terminal.o screen.o
	ld -T link.ld -melf_i386 -o core.elf core.o osload.o osboot.o font.o gdt.o idt.o service.o memory.o port_hub.o keyboard.o request.o clock.o core_malloc.o draw_element.o main_frame.o sub_frame.o color.o frame_bitmap.o terminal.o screen.o
	objcopy -O binary core.elf core.bin

elle.flp: core.bin	
	dd if=/dev/zero of=elle.flp bs=1K count=1440
	dd if=core.bin of=elle.flp conv=notrunc

clean:
	rm -f osboot.o osload.o core.o load_core.o core.bin elle.flp core.elf font.o gdt.o idt.o service.o memory.o port_hub.o keyboard.o request.o clock.o core_malloc.o draw_element.o main_frame.o sub_frame.o color.o frame_bitmap.o terminal.o screen.o
