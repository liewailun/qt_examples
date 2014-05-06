import ctypes

lib = 'DllTest/release/DllTest.dll'

def printtext(text):
    print(text)

testlib = ctypes.CDLL(lib)

testlib.hello()

function_pointer_type = ctypes.CFUNCTYPE(ctypes.c_void_p, ctypes.c_char_p)

function_pointer = function_pointer_type(printtext)

testlib.test(function_pointer)