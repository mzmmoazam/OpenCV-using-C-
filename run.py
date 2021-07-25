import os,sys

print("\n")

print("Compiling ... \n")

print("*"*10)

flags = " -static-libgcc -static-libstdc++ "

if os.system(f"g++ {' '.join(sys.argv[1:])} {flags}") == 0:

    # print("*"*10,"\n"*2)

    print ("Compiled\n")

    print("#"*10,"\n"*2)
    
    if "-o" in sys.argv:
        os.system(sys.argv[sys.argv.index("-o") + 1])
    else:
        os.system("a.exe")
        os.remove("a.exe")

else:
    print ("Compilation failed")