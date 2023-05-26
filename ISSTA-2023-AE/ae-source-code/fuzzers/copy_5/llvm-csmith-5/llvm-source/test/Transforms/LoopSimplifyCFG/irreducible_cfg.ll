; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; REQUIRES: asserts
; RUN: opt -S -enable-loop-simplifycfg-term-folding=true -loop-simplifycfg -debug-only=loop-simplifycfg -verify-loop-info -verify-dom-info -verify-loop-lcssa 2>&1 < %s | FileCheck %s
; RUN: opt -S -enable-loop-simplifycfg-term-folding=true -passes='require<domtree>,loop(loop-simplifycfg)' -debug-only=loop-simplifycfg -verify-loop-info -verify-dom-info -verify-loop-lcssa 2>&1 < %s | FileCheck %s
; RUN: opt -S -enable-loop-simplifycfg-term-folding=true -loop-simplifycfg -enable-mssa-loop-dependency=true -verify-memoryssa -debug-only=loop-simplifycfg -verify-loop-info -verify-dom-info -verify-loop-lcssa 2>&1 < %s | FileCheck %s

target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128-ni:1"

; This test has irreducible CFG, and RPO may be the following:
; Header, Dead, Irreducible2, Latch, Irreducible3, Irreducible1.
; As result, we will process Irreducible2 before its predecessor Irreducible1.
; The current algorithm gets confused in this case. We may support irreducible
; CFG in the future.
define void @irreducible_cfg(i1 %cond) {
; CHECK-LABEL: @irreducible_cfg(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    br label [[HEADER:%.*]]
; CHECK:       header:
; CHECK-NEXT:    br i1 false, label [[DEAD:%.*]], label [[IRREDUCIBLE1:%.*]]
; CHECK:       dead:
; CHECK-NEXT:    br label [[IRREDUCIBLE2:%.*]]
; CHECK:       irreducible2:
; CHECK-NEXT:    br i1 [[COND:%.*]], label [[LATCH:%.*]], label [[IRREDUCIBLE3:%.*]]
; CHECK:       latch:
; CHECK-NEXT:    br label [[HEADER]]
; CHECK:       irreducible3:
; CHECK-NEXT:    br label [[IRREDUCIBLE1]]
; CHECK:       irreducible1:
; CHECK-NEXT:    br label [[IRREDUCIBLE2]]
;
entry:
  br label %header

header:                                             ; preds = %latch, %entry
  br i1 false, label %dead, label %irreducible1

dead:                                          ; preds = %header
  br label %irreducible2

irreducible2:                                             ; preds = %irreducible1, %dead
  br i1 %cond, label %latch, label %irreducible3

latch:                                         ; preds = %irreducible2
  br label %header

irreducible3:                                           ; preds = %irreducible2
  br label %irreducible1

irreducible1:                                          ; preds = %irreducible3, %header
  br label %irreducible2
}