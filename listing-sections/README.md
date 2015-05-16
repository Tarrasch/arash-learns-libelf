```
~/repos/arash-learns-libelf/listing-sections master
❯ ./a.out a.out
Section 0001 .interp
Section 0002 .note.ABI-tag
Section 0003 .note.gnu.build-id
Section 0004 .gnu.hash
Section 0005 .dynsym
Section 0006 .dynstr
Section 0007 .gnu.version
Section 0008 .gnu.version_r
Section 0009 .rela.dyn
Section 0010 .rela.plt
Section 0011 .init
Section 0012 .plt
Section 0013 .text
Section 0014 .fini
Section 0015 .rodata
Section 0016 .eh_frame_hdr
Section 0017 .eh_frame
Section 0018 .init_array
Section 0019 .fini_array
Section 0020 .jcr
Section 0021 .dynamic
Section 0022 .got
Section 0023 .got.plt
Section 0024 .data
Section 0025 .bss
Section 0026 .comment
Section 0027 .shstrtab
Section 0028 .symtab
Section 0029 .strtab
.shstrab: size=264
\^@ . s y m t a b \^@ . s t r t a b
\^@ . s h s t r t a b \^@ . i n t e
r p \^@ . n o t e . A B I - t a g
\^@ . n o t e . g n u . b u i l d
- i d \^@ . g n u . h a s h \^@ . d
y n s y m \^@ . d y n s t r \^@ . g
n u . v e r s i o n \^@ . g n u .
v e r s i o n _ r \^@ . r e l a .
d y n \^@ . r e l a . p l t \^@ . i
n i t \^@ . t e x t \^@ . f i n i \^@
. r o d a t a \^@ . e h _ f r a m
e _ h d r \^@ . e h _ f r a m e \^@
. i n i t _ a r r a y \^@ . f i n
i _ a r r a y \^@ . j c r \^@ . d y
n a m i c \^@ . g o t \^@ . g o t .
p l t \^@ . d a t a \^@ . b s s \^@ .
c o m m e n t \^@

~/repos/arash-learns-libelf/listing-sections master
❯ ./a.out /usr/lib/libdialog.a
a.out: /usr/lib/libdialog.a is not an ELF object.

~/repos/arash-learns-libelf/listing-sections master
❯ ./a.out ~/repos/ghc/inplace/bin/ghc-stage2
a.out: /home/arash/repos/ghc/inplace/bin/ghc-stage2 is not an ELF object.
```
