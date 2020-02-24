// Axel '0vercl0k' Souchet - February 15 2019
#include "kdmp-parser.h"
#include <tchar.h>

int _tmain(int argc, TCHAR *argv[]) {
  if (argc != 2) {
    _tprintf(_T("test.exe <kdump path>\n"));
    return EXIT_FAILURE;
  }

  KernelDumpParser Dmp(argv[1]);
  if (!Dmp.Parse()) {
    return EXIT_FAILURE;
  }

  //
  // kd> r
  // rax=0000000000000003 rbx=fffff8050f4e9f70 rcx=0000000000000001
  // rdx=fffff805135684d0 rsi=0000000000000100 rdi=fffff8050f4e9f80
  // rip=fffff805108776a0 rsp=fffff805135684f8 rbp=fffff80513568600
  // r8=0000000000000003  r9=fffff805135684b8 r10=0000000000000000
  // r11=ffffa8848825e000 r12=fffff8050f4e9f80 r13=fffff80510c3c958
  // r14=0000000000000000 r15=0000000000000052
  // iopl=0         nv up ei pl nz na pe nc
  // cs=0010  ss=0018  ds=002b  es=002b  fs=0053  gs=002b efl=00040202
  //

  const KDMP_PARSER_CONTEXT *C = Dmp.GetContext();
  if (C->Rax != 0x0000000000000003ULL) {
    _tprintf(_T("Rax(0x%016llx) does not match with 0x0000000000000003."),
             C->Rax);
    return EXIT_FAILURE;
  }

  if (C->Rbx != 0xfffff8050f4e9f70ULL) {
    _tprintf(_T("Rbx(0x%016llx) does not match with 0xfffff8050f4e9f70."),
             C->Rbx);
    return EXIT_FAILURE;
  }

  if (C->Rcx != 0x0000000000000001ULL) {
    _tprintf(_T("Rcx(0x%016llx) does not match with 0x0000000000000001."),
             C->Rcx);
    return EXIT_FAILURE;
  }

  if (C->Rdx != 0xfffff805135684d0ULL) {
    _tprintf(_T("Rdx(0x%016llx) does not match with 0xfffff805135684d0."),
             C->Rdx);
    return EXIT_FAILURE;
  }

  if (C->Rsi != 0x0000000000000100ULL) {
    _tprintf(_T("Rsi(0x%016llx) does not match with 0x0000000000000100."),
             C->Rsi);
    return EXIT_FAILURE;
  }

  if (C->Rdi != 0xfffff8050f4e9f80ULL) {
    _tprintf(_T("Rdi(0x%016llx) does not match with 0xfffff8050f4e9f80."),
             C->Rdi);
    return EXIT_FAILURE;
  }

  if (C->Rip != 0xfffff805108776a0ULL) {
    _tprintf(_T("Rip(0x%016llx) does not match with 0xfffff805108776a0."),
             C->Rip);
    return EXIT_FAILURE;
  }

  if (C->Rsp != 0xfffff805135684f8ULL) {
    _tprintf(_T("Rsp(0x%016llx) does not match with 0xfffff805135684f8."),
             C->Rsp);
    return EXIT_FAILURE;
  }

  if (C->Rbp != 0xfffff80513568600ULL) {
    _tprintf(_T("Rbp(0x%016llx) does not match with 0xfffff80513568600."),
             C->Rbp);
    return EXIT_FAILURE;
  }

  if (C->R8 != 0x0000000000000003ULL) {
    _tprintf(_T("R8(0x%016llx) does not match with 0x0000000000000003."), C->R8);
    return EXIT_FAILURE;
  }

  if (C->R9 != 0xfffff805135684b8ULL) {
    _tprintf(_T("R9(0x%016llx) does not match with 0xfffff805135684b8."), C->R9);
    return EXIT_FAILURE;
  }

  if (C->R10 != 0x0000000000000000ULL) {
    _tprintf(_T("R10(0x%016llx) does not match with 0x0000000000000000."),
             C->R10);
    return EXIT_FAILURE;
  }

  if (C->R11 != 0xffffa8848825e000ULL) {
    _tprintf(_T("R11(0x%016llx) does not match with 0xffffa8848825e000."),
             C->R11);
    return EXIT_FAILURE;
  }

  if (C->R12 != 0xfffff8050f4e9f80ULL) {
    _tprintf(_T("R12(0x%016llx) does not match with 0xfffff8050f4e9f80."),
             C->R12);
    return EXIT_FAILURE;
  }

  if (C->R13 != 0xfffff80510c3c958ULL) {
    _tprintf(_T("R13(0x%016llx) does not match with 0xfffff80510c3c958."),
             C->R13);
    return EXIT_FAILURE;
  }

  if (C->R14 != 0x0000000000000000ULL) {
    _tprintf(_T("R14(0x%016llx) does not match with 0x0000000000000000."),
             C->R14);
    return EXIT_FAILURE;
  }

  if (C->R15 != 0x0000000000000052ULL) {
    _tprintf(_T("R15(0x%016llx) does not match with 0x0000000000000052."),
             C->R15);
    return EXIT_FAILURE;
  }

  _tprintf(_T("GPRs matches the testdatas.\n"));

  return EXIT_SUCCESS;
}