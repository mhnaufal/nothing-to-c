# My Assembly Project

## Projects

```bash
nasm -win64 intro.asm
gcc intro.o
./a.exe
```

```bash
nasm -f win64 -o build/intro.obj intro.asm && gcc -o build/intro build/intro.obj && ./build/intro.exe
```

## References

- [Syscall Table](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
- https://cs.lmu.edu/~ray/notes/nasmtutorial/
- https://sonictk.github.io/asm_tutorial/
- https://www.ic.unicamp.br/~pannain/mc404/aulas/pdfs/Art%20Of%20Intel%20x86%20Assembly.pdf
- https://www.nasm.us/xdoc/2.16.01/nasmdoc.pdf
