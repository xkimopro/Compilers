Disassembly of section .init:

0000000000401000 <_init>:
  401000:       f3 0f 1e fa             endbr64 
  401004:       48 83 ec 08             sub    $0x8,%rsp
  401008:       48 8b 05 e9 2f 00 00    mov    0x2fe9(%rip),%rax        # 403ff8 <__gmon_start__>
  40100f:       48 85 c0                test   %rax,%rax
  401012:       74 02                   je     401016 <_init+0x16>
  401014:       ff d0                   callq  *%rax
  401016:       48 83 c4 08             add    $0x8,%rsp
  40101a:       c3                      retq   

Disassembly of section .text:

0000000000401020 <_start>:
  401020:       f3 0f 1e fa             endbr64 
  401024:       31 ed                   xor    %ebp,%ebp
  401026:       49 89 d1                mov    %rdx,%r9
  401029:       5e                      pop    %rsi
  40102a:       48 89 e2                mov    %rsp,%rdx
  40102d:       48 83 e4 f0             and    $0xfffffffffffffff0,%rsp
  401031:       50                      push   %rax
  401032:       54                      push   %rsp
  401033:       49 c7 c0 b0 11 40 00    mov    $0x4011b0,%r8
  40103a:       48 c7 c1 40 11 40 00    mov    $0x401140,%rcx
  401041:       48 c7 c7 10 11 40 00    mov    $0x401110,%rdi
  401048:       ff 15 a2 2f 00 00       callq  *0x2fa2(%rip)        # 403ff0 <__libc_start_main@GLIBC_2.2.5>
  40104e:       f4                      hlt    
  40104f:       90                      nop

0000000000401050 <_dl_relocate_static_pie>:
  401050:       f3 0f 1e fa             endbr64 
  401054:       c3                      retq   
  401055:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
  40105c:       00 00 00 
  40105f:       90                      nop

0000000000401060 <deregister_tm_clones>:
  401060:       b8 28 40 40 00          mov    $0x404028,%eax
  401065:       48 3d 28 40 40 00       cmp    $0x404028,%rax
  40106b:       74 13                   je     401080 <deregister_tm_clones+0x20>
  40106d:       b8 00 00 00 00          mov    $0x0,%eax
  401072:       48 85 c0                test   %rax,%rax
  401075:       74 09                   je     401080 <deregister_tm_clones+0x20>
  401077:       bf 28 40 40 00          mov    $0x404028,%edi
  40107c:       ff e0                   jmpq   *%rax
  40107e:       66 90                   xchg   %ax,%ax
  401080:       c3                      retq   
  401081:       66 66 2e 0f 1f 84 00    data16 nopw %cs:0x0(%rax,%rax,1)
  401088:       00 00 00 00 
  40108c:       0f 1f 40 00             nopl   0x0(%rax)

0000000000401090 <register_tm_clones>:
  401090:       be 28 40 40 00          mov    $0x404028,%esi
  401095:       48 81 ee 28 40 40 00    sub    $0x404028,%rsi
  40109c:       48 89 f0                mov    %rsi,%rax
  40109f:       48 c1 ee 3f             shr    $0x3f,%rsi
  4010a3:       48 c1 f8 03             sar    $0x3,%rax
  4010a7:       48 01 c6                add    %rax,%rsi
  4010aa:       48 d1 fe                sar    %rsi
  4010ad:       74 11                   je     4010c0 <register_tm_clones+0x30>
  4010af:       b8 00 00 00 00          mov    $0x0,%eax
  4010b4:       48 85 c0                test   %rax,%rax
  4010b7:       74 07                   je     4010c0 <register_tm_clones+0x30>
  4010b9:       bf 28 40 40 00          mov    $0x404028,%edi
  4010be:       ff e0                   jmpq   *%rax
  4010c0:       c3                      retq   
  4010c1:       66 66 2e 0f 1f 84 00    data16 nopw %cs:0x0(%rax,%rax,1)
  4010c8:       00 00 00 00 
  4010cc:       0f 1f 40 00             nopl   0x0(%rax)

00000000004010d0 <__do_global_dtors_aux>:
  4010d0:       f3 0f 1e fa             endbr64 
  4010d4:       80 3d 55 2f 00 00 00    cmpb   $0x0,0x2f55(%rip)        # 404030 <completed.8060>
  4010db:       75 13                   jne    4010f0 <__do_global_dtors_aux+0x20>
  4010dd:       55                      push   %rbp
  4010de:       48 89 e5                mov    %rsp,%rbp
  4010e1:       e8 7a ff ff ff          callq  401060 <deregister_tm_clones>
  4010e6:       c6 05 43 2f 00 00 01    movb   $0x1,0x2f43(%rip)        # 404030 <completed.8060>
  4010ed:       5d                      pop    %rbp
  4010ee:       c3                      retq   
  4010ef:       90                      nop
  4010f0:       c3                      retq   
  4010f1:       66 66 2e 0f 1f 84 00    data16 nopw %cs:0x0(%rax,%rax,1)
  4010f8:       00 00 00 00 
  4010fc:       0f 1f 40 00             nopl   0x0(%rax)

0000000000401100 <frame_dummy>:
  401100:       f3 0f 1e fa             endbr64 
  401104:       eb 8a                   jmp    401090 <register_tm_clones>
  401106:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
  40110d:       00 00 00 

0000000000401110 <main>:
  401110:       50                      push   %rax
  401111:       bf 21 00 00 00          mov    $0x21,%edi
  401116:       e8 f7 0e 00 00          callq  402012 <writeInteger>
  40111b:       f2 0f 10 05 e5 0e 00    movsd  0xee5(%rip),%xmm0        # 402008 <_IO_stdin_used+0x8>
  401122:       00 
  401123:       e8 14 0f 00 00          callq  40203c <writeReal>
  401128:       bf 10 20 40 00          mov    $0x402010,%edi
  40112d:       e8 39 0f 00 00          callq  40206b <writeString>
  401132:       31 c0                   xor    %eax,%eax
  401134:       59                      pop    %rcx
  401135:       c3                      retq   
  401136:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
  40113d:       00 00 00 

0000000000401140 <__libc_csu_init>:
  401140:       f3 0f 1e fa             endbr64 
  401144:       41 57                   push   %r15
  401146:       4c 8d 3d 03 2d 00 00    lea    0x2d03(%rip),%r15        # 403e50 <__frame_dummy_init_array_entry>
  40114d:       41 56                   push   %r14
  40114f:       49 89 d6                mov    %rdx,%r14
  401152:       41 55                   push   %r13
  401154:       49 89 f5                mov    %rsi,%r13
  401157:       41 54                   push   %r12
  401159:       41 89 fc                mov    %edi,%r12d
  40115c:       55                      push   %rbp
  40115d:       48 8d 2d f4 2c 00 00    lea    0x2cf4(%rip),%rbp        # 403e58 <__do_global_dtors_aux_fini_array_entry>
  401164:       53                      push   %rbx
  401165:       4c 29 fd                sub    %r15,%rbp
  401168:       48 83 ec 08             sub    $0x8,%rsp
  40116c:       e8 8f fe ff ff          callq  401000 <_init>
  401171:       48 c1 fd 03             sar    $0x3,%rbp
  401175:       74 1f                   je     401196 <__libc_csu_init+0x56>
  401177:       31 db                   xor    %ebx,%ebx
  401179:       0f 1f 80 00 00 00 00    nopl   0x0(%rax)
  401180:       4c 89 f2                mov    %r14,%rdx
  401183:       4c 89 ee                mov    %r13,%rsi
  401186:       44 89 e7                mov    %r12d,%edi
  401189:       41 ff 14 df             callq  *(%r15,%rbx,8)
  40118d:       48 83 c3 01             add    $0x1,%rbx
  401191:       48 39 dd                cmp    %rbx,%rbp
  401194:       75 ea                   jne    401180 <__libc_csu_init+0x40>
  401196:       48 83 c4 08             add    $0x8,%rsp
  40119a:       5b                      pop    %rbx
  40119b:       5d                      pop    %rbp
  40119c:       41 5c                   pop    %r12
  40119e:       41 5d                   pop    %r13
  4011a0:       41 5e                   pop    %r14
  4011a2:       41 5f                   pop    %r15
  4011a4:       c3                      retq   
  4011a5:       66 66 2e 0f 1f 84 00    data16 nopw %cs:0x0(%rax,%rax,1)
  4011ac:       00 00 00 00 

00000000004011b0 <__libc_csu_fini>:
  4011b0:       f3 0f 1e fa             endbr64 
  4011b4:       c3                      retq   

Disassembly of section .fini:

00000000004011b8 <_fini>:
  4011b8:       f3 0f 1e fa             endbr64 
  4011bc:       48 83 ec 08             sub    $0x8,%rsp
  4011c0:       48 83 c4 08             add    $0x8,%rsp
  4011c4:       c3                      retq   
