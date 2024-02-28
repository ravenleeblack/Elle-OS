; enable_gate.inc     enable_gate is the a_20 gate that needs to be enabled to access additional memory


enable_gate:
    pusha
	in al, 0x92
	or al, 2
	out 0x92, al                                ;This enables A20 on my acer PC -- A potential source for errors :(
	popa
	ret
