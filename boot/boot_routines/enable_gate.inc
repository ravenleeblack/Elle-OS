
enable_gate:                                        ;enable_gate is the a_20 gate that needs to be enabled to access additional memory
    pusha
    in al, 0x92
    or al, 2
    out 0x92, al                           
    popa
    ret
