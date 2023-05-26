; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
;RUN: opt -newgvn -S < %s | FileCheck %s
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.12.0"
;; Ensure we don't infinite loop when all phi arguments are really unreachable or self-defined
define void @fn1(i64 %arg) {
; CHECK-LABEL: @fn1(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    br i1 undef, label [[IF_THEN:%.*]], label [[COND_TRUE:%.*]]
; CHECK:       if.then:
; CHECK-NEXT:    br i1 false, label [[FIRSTPHIBLOCK:%.*]], label [[TEMP:%.*]]
; CHECK:       firstphiblock:
; CHECK-NEXT:    br i1 undef, label %for.cond17thread-pre-split, label [[SECONDPHIBLOCK:%.*]]
; CHECK:       secondphiblock:
; CHECK-NEXT:    [[SECONDPHI:%.*]] = phi i64 [ [[THIRDPHI:%.*]], [[THIRDPHIBLOCK:%.*]] ], [ undef, [[FIRSTPHIBLOCK]] ]
; CHECK-NEXT:    br i1 undef, label [[FIRSTPHIBLOCK]], label [[THIRDPHIBLOCK]]
; CHECK:       thirdphiblock:
; CHECK-NEXT:    [[THIRDPHI]] = phi i64 [ [[SECONDPHI]], [[SECONDPHIBLOCK]] ], [ [[DIV:%.*]], [[COND_TRUE]] ]
; CHECK-NEXT:    br label [[SECONDPHIBLOCK]]
; CHECK:       for.cond17thread-pre-split:
; CHECK-NEXT:    br label [[COND_TRUE]]
; CHECK:       cond.true:
; CHECK-NEXT:    [[DIV]] = sdiv i64 [[ARG:%.*]], 4
; CHECK-NEXT:    br label [[THIRDPHIBLOCK]]
; CHECK:       temp:
; CHECK-NEXT:    ret void
;
entry:
  br i1 undef, label %if.then, label %cond.true
if.then:
  br i1 false, label %firstphiblock, label %temp
firstphiblock:
  %firstphi = phi i64 [ %arg, %if.then ], [ undef, %secondphiblock ]
  br i1 undef, label %for.cond17thread-pre-split, label %secondphiblock
secondphiblock:
  %secondphi = phi i64 [ %thirdphi, %thirdphiblock ], [ %firstphi, %firstphiblock ]
  br i1 undef, label %firstphiblock, label %thirdphiblock
thirdphiblock:
  %thirdphi = phi i64 [ %secondphi, %secondphiblock ], [ %div, %cond.true ]
  br label %secondphiblock
for.cond17thread-pre-split:
  br label %cond.true
cond.true:
  %fourthphi = phi i64 [ %arg, %entry ], [ %firstphi, %for.cond17thread-pre-split ]
  %div = sdiv i64 %fourthphi, 4
  br label %thirdphiblock
temp:
  ret void
}
define void @fn2(i64 %arg) {
; CHECK-LABEL: @fn2(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    br i1 undef, label [[IF_THEN:%.*]], label [[COND_TRUE:%.*]]
; CHECK:       if.then:
; CHECK-NEXT:    br i1 false, label [[FIRSTPHIBLOCK:%.*]], label [[TEMP:%.*]]
; CHECK:       firstphiblock:
; CHECK-NEXT:    [[FIRSTPHI:%.*]] = phi i64 [ undef, [[IF_THEN]] ], [ [[SECONDPHI:%.*]], [[SECONDPHIBLOCK:%.*]] ]
; CHECK-NEXT:    br i1 undef, label %for.cond17thread-pre-split, label [[SECONDPHIBLOCK]]
; CHECK:       secondphiblock:
; CHECK-NEXT:    [[SECONDPHI]] = phi i64 [ [[THIRDPHI:%.*]], [[THIRDPHIBLOCK:%.*]] ], [ [[FIRSTPHI]], [[FIRSTPHIBLOCK]] ]
; CHECK-NEXT:    br i1 undef, label [[FIRSTPHIBLOCK]], label [[THIRDPHIBLOCK]]
; CHECK:       thirdphiblock:
; CHECK-NEXT:    [[THIRDPHI]] = phi i64 [ [[SECONDPHI]], [[SECONDPHIBLOCK]] ], [ [[DIV:%.*]], [[COND_TRUE]] ]
; CHECK-NEXT:    br label [[SECONDPHIBLOCK]]
; CHECK:       for.cond17thread-pre-split:
; CHECK-NEXT:    br label [[COND_TRUE]]
; CHECK:       cond.true:
; CHECK-NEXT:    [[FOURTHPHI:%.*]] = phi i64 [ [[ARG:%.*]], [[ENTRY:%.*]] ], [ [[FIRSTPHI]], %for.cond17thread-pre-split ]
; CHECK-NEXT:    [[DIV]] = sdiv i64 [[FOURTHPHI]], 4
; CHECK-NEXT:    br label [[THIRDPHIBLOCK]]
; CHECK:       temp:
; CHECK-NEXT:    ret void
;
entry:
  br i1 undef, label %if.then, label %cond.true
if.then:
  br i1 false, label %firstphiblock, label %temp
firstphiblock:
  %firstphi = phi i64 [ %arg, %if.then ], [ %secondphi, %secondphiblock ]
  br i1 undef, label %for.cond17thread-pre-split, label %secondphiblock
secondphiblock:
  %secondphi = phi i64 [ %thirdphi, %thirdphiblock ], [ %firstphi, %firstphiblock ]
  br i1 undef, label %firstphiblock, label %thirdphiblock
thirdphiblock:
  %thirdphi = phi i64 [ %secondphi, %secondphiblock ], [ %div, %cond.true ]
  br label %secondphiblock
for.cond17thread-pre-split:
  br label %cond.true
cond.true:
  %fourthphi = phi i64 [ %arg, %entry ], [ %firstphi, %for.cond17thread-pre-split ]
  %div = sdiv i64 %fourthphi, 4
  br label %thirdphiblock
temp:
  ret void
}
@b = external global i32, align 4
@a = external global i32, align 4
define void @fn3() {
; CHECK-LABEL: @fn3(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    br label [[L1:%.*]]
; CHECK:       l1.loopexit:
; CHECK-NEXT:    br label [[L1]]
; CHECK:       l1:
; CHECK-NEXT:    [[F_0:%.*]] = phi i32* [ @b, [[ENTRY:%.*]] ], [ @a, [[L1_LOOPEXIT:%.*]] ]
; CHECK-NEXT:    br label [[FOR_COND:%.*]]
; CHECK:       for.cond.loopexit:
; CHECK-NEXT:    store i8 undef, i8* null
; CHECK-NEXT:    br label [[FOR_COND]]
; CHECK:       for.cond:
; CHECK-NEXT:    br i1 undef, label [[FOR_END14:%.*]], label [[FOR_COND1_PREHEADER:%.*]]
; CHECK:       for.cond1.preheader:
; CHECK-NEXT:    br label [[FOR_BODY3:%.*]]
; CHECK:       for.cond1:
; CHECK-NEXT:    br label [[L2:%.*]]
; CHECK:       for.body3:
; CHECK-NEXT:    br i1 undef, label [[FOR_COND1:%.*]], label [[L1_LOOPEXIT]]
; CHECK:       l2:
; CHECK-NEXT:    [[G_4:%.*]] = phi i32* [ @b, [[FOR_END14]] ], [ @a, [[FOR_COND1]] ]
; CHECK-NEXT:    [[F_2:%.*]] = phi i32* [ [[F_0]], [[FOR_END14]] ], [ @a, [[FOR_COND1]] ]
; CHECK-NEXT:    br label [[FOR_INC:%.*]]
; CHECK:       for.inc:
; CHECK-NEXT:    br i1 false, label [[FOR_COND_LOOPEXIT:%.*]], label [[FOR_INC]]
; CHECK:       for.end14:
; CHECK-NEXT:    br label [[L2]]
;
entry:
  br label %l1
l1.loopexit:
  %g.223.lcssa = phi i32* [ @b, %for.body3 ]
  br label %l1
l1:
  %g.0 = phi i32* [ undef, %entry ], [ %g.223.lcssa, %l1.loopexit ]
  %f.0 = phi i32* [ @b, %entry ], [ @a, %l1.loopexit ]
  br label %for.cond
for.cond.loopexit:
  br label %for.cond
for.cond:
  %g.1 = phi i32* [ %g.0, %l1 ], [ %g.4, %for.cond.loopexit ]
  %f.1 = phi i32* [ %f.0, %l1 ], [ %f.2, %for.cond.loopexit ]
  br i1 undef, label %for.end14, label %for.cond1.preheader
for.cond1.preheader:
  br label %for.body3
for.cond1:
  br label %l2
for.body3:
  br i1 undef, label %for.cond1, label %l1.loopexit
l2:
  %g.4 = phi i32* [ %g.1, %for.end14 ], [ @a, %for.cond1 ]
  %f.2 = phi i32* [ %f.1, %for.end14 ], [ @a, %for.cond1 ]
  br label %for.inc
for.inc:
  br i1 false, label %for.cond.loopexit, label %for.inc
for.end14:
  br label %l2
}

