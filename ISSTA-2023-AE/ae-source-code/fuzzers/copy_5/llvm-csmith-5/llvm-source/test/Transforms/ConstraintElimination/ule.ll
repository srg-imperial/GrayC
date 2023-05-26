; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt -constraint-elimination -S %s | FileCheck %s

declare void @use(i1)

define void @test_1_variable_constraint(i32 %x, i32 %y, i32 %z) {
; CHECK-LABEL: @test_1_variable_constraint(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[C_1:%.*]] = icmp ule i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    br i1 [[C_1]], label [[BB1:%.*]], label [[BB2:%.*]]
; CHECK:       bb1:
; CHECK-NEXT:    [[T_1:%.*]] = icmp ule i32 [[X]], [[Y]]
; CHECK-NEXT:    call void @use(i1 true)
; CHECK-NEXT:    [[C_2:%.*]] = icmp ule i32 [[X]], 10
; CHECK-NEXT:    call void @use(i1 [[C_2]])
; CHECK-NEXT:    [[C_3:%.*]] = icmp ule i32 [[Y]], [[X]]
; CHECK-NEXT:    call void @use(i1 [[C_3]])
; CHECK-NEXT:    [[C_4:%.*]] = icmp ule i32 10, [[X]]
; CHECK-NEXT:    call void @use(i1 [[C_4]])
; CHECK-NEXT:    ret void
; CHECK:       bb2:
; CHECK-NEXT:    [[T_2:%.*]] = icmp ule i32 [[Y]], [[X]]
; CHECK-NEXT:    call void @use(i1 true)
; CHECK-NEXT:    [[F_1:%.*]] = icmp ule i32 [[X]], [[Y]]
; CHECK-NEXT:    call void @use(i1 false)
; CHECK-NEXT:    [[C_5:%.*]] = icmp ule i32 [[X]], 10
; CHECK-NEXT:    call void @use(i1 [[C_5]])
; CHECK-NEXT:    [[C_6:%.*]] = icmp ule i32 10, [[X]]
; CHECK-NEXT:    call void @use(i1 [[C_6]])
; CHECK-NEXT:    ret void
;
entry:
  %c.1 = icmp ule i32 %x, %y
  br i1 %c.1, label %bb1, label %bb2

bb1:
  %t.1 = icmp ule i32 %x, %y
  call void @use(i1 %t.1)
  %c.2 = icmp ule i32 %x, 10
  call void @use(i1 %c.2)
  %c.3 = icmp ule i32 %y, %x
  call void @use(i1 %c.3)
  %c.4 = icmp ule i32 10, %x
  call void @use(i1 %c.4)
  ret void

bb2:
  %t.2 = icmp ule i32 %y, %x
  call void @use(i1 %t.2)
  %f.1 = icmp ule i32 %x, %y
  call void @use(i1 %f.1)
  %c.5 = icmp ule i32 %x, 10
  call void @use(i1 %c.5)
  %c.6 = icmp ule i32 10, %x
  call void @use(i1 %c.6)
  ret void
}

define void @test_1_constant_constraint(i32 %x) {
; CHECK-LABEL: @test_1_constant_constraint(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[C_1:%.*]] = icmp ule i32 [[X:%.*]], 10
; CHECK-NEXT:    br i1 [[C_1]], label [[BB1:%.*]], label [[BB2:%.*]]
; CHECK:       bb1:
; CHECK-NEXT:    [[T_1:%.*]] = icmp ule i32 [[X]], 10
; CHECK-NEXT:    call void @use(i1 true)
; CHECK-NEXT:    [[T_2:%.*]] = icmp ule i32 [[X]], 11
; CHECK-NEXT:    call void @use(i1 true)
; CHECK-NEXT:    [[C_2:%.*]] = icmp ule i32 [[X]], 9
; CHECK-NEXT:    call void @use(i1 [[C_2]])
; CHECK-NEXT:    [[C_4:%.*]] = icmp ule i32 10, [[X]]
; CHECK-NEXT:    call void @use(i1 [[C_4]])
; CHECK-NEXT:    ret void
; CHECK:       bb2:
; CHECK-NEXT:    [[T_3:%.*]] = icmp ule i32 10, [[X]]
; CHECK-NEXT:    call void @use(i1 true)
; CHECK-NEXT:    [[F_1:%.*]] = icmp ule i32 [[X]], 9
; CHECK-NEXT:    call void @use(i1 false)
; CHECK-NEXT:    [[F_1_1:%.*]] = icmp ule i32 [[X]], 10
; CHECK-NEXT:    call void @use(i1 false)
; CHECK-NEXT:    [[C_5:%.*]] = icmp ule i32 [[X]], 11
; CHECK-NEXT:    call void @use(i1 [[C_5]])
; CHECK-NEXT:    [[C_6:%.*]] = icmp ule i32 12, [[X]]
; CHECK-NEXT:    call void @use(i1 [[C_6]])
; CHECK-NEXT:    ret void
;
entry:
  %c.1 = icmp ule i32 %x, 10
  br i1 %c.1, label %bb1, label %bb2

bb1:
  %t.1 = icmp ule i32 %x, 10
  call void @use(i1 %t.1)
  %t.2 = icmp ule i32 %x, 11
  call void @use(i1 %t.2)
  %c.2 = icmp ule i32 %x, 9
  call void @use(i1 %c.2)
  %c.4 = icmp ule i32 10, %x
  call void @use(i1 %c.4)
  ret void

bb2:
  %t.3 = icmp ule i32 10, %x
  call void @use(i1 %t.3)
  %f.1 = icmp ule i32 %x, 9
  call void @use(i1 %f.1)


  %f.1.1 = icmp ule i32 %x, 10
  call void @use(i1 %f.1.1)
  %c.5 = icmp ule i32 %x, 11
  call void @use(i1 %c.5)
  %c.6 = icmp ule i32 12, %x
  call void @use(i1 %c.6)
  ret void
}


define i32 @test1(i32 %x, i32 %y, i32 %z) {
; CHECK-LABEL: @test1(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[C_1:%.*]] = icmp ule i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    br i1 [[C_1]], label [[BB1:%.*]], label [[EXIT:%.*]]
; CHECK:       bb1:
; CHECK-NEXT:    [[C_2:%.*]] = icmp ule i32 [[Y]], [[Z:%.*]]
; CHECK-NEXT:    br i1 [[C_2]], label [[BB2:%.*]], label [[EXIT]]
; CHECK:       bb2:
; CHECK-NEXT:    [[C_3:%.*]] = icmp ule i32 [[X]], [[Z]]
; CHECK-NEXT:    br i1 true, label [[BB3:%.*]], label [[EXIT]]
; CHECK:       bb3:
; CHECK-NEXT:    ret i32 10
; CHECK:       exit:
; CHECK-NEXT:    ret i32 20
;
entry:
  %c.1 = icmp ule i32 %x, %y
  br i1 %c.1, label %bb1, label %exit

bb1:
  %c.2 = icmp ule i32 %y, %z
  br i1 %c.2, label %bb2, label %exit

bb2:
  %c.3 = icmp ule i32 %x, %z
  br i1 %c.3, label %bb3, label %exit

bb3:
  ret i32 10

exit:
  ret i32 20
}


define i32 @test2(i32 %x, i32 %y, i32 %z, i32 %a) {
; CHECK-LABEL: @test2(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[C_1:%.*]] = icmp ule i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    br i1 [[C_1]], label [[BB1:%.*]], label [[EXIT:%.*]]
; CHECK:       bb1:
; CHECK-NEXT:    [[C_2:%.*]] = icmp ule i32 [[Y]], [[Z:%.*]]
; CHECK-NEXT:    br i1 [[C_2]], label [[BB2:%.*]], label [[EXIT]]
; CHECK:       bb2:
; CHECK-NEXT:    [[C_3:%.*]] = icmp ule i32 [[X]], [[A:%.*]]
; CHECK-NEXT:    br i1 [[C_3]], label [[BB3:%.*]], label [[EXIT]]
; CHECK:       bb3:
; CHECK-NEXT:    ret i32 10
; CHECK:       exit:
; CHECK-NEXT:    ret i32 20
;
entry:
  %c.1 = icmp ule i32 %x, %y
  br i1 %c.1, label %bb1, label %exit

bb1:
  %c.2 = icmp ule i32 %y, %z
  br i1 %c.2, label %bb2, label %exit

bb2:
  %c.3 = icmp ule i32 %x, %a
  br i1 %c.3, label %bb3, label %exit

bb3:
  ret i32 10

exit:
  ret i32 20
}


define i32 @test3(i32 %x, i32 %y) {
; CHECK-LABEL: @test3(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[C_1:%.*]] = icmp ule i32 [[X:%.*]], 10
; CHECK-NEXT:    br i1 [[C_1]], label [[BB1:%.*]], label [[EXIT:%.*]]
; CHECK:       bb1:
; CHECK-NEXT:    [[C_2:%.*]] = icmp ule i32 [[Y:%.*]], 20
; CHECK-NEXT:    br i1 [[C_2]], label [[BB2:%.*]], label [[EXIT]]
; CHECK:       bb2:
; CHECK-NEXT:    ret i32 10
; CHECK:       exit:
; CHECK-NEXT:    ret i32 20
;
entry:
  %c.1 = icmp ule i32 %x, 10
  br i1 %c.1, label %bb1, label %exit

bb1:
  %c.2 = icmp ule i32 %y, 20
  br i1 %c.2, label %bb2, label %exit

bb2:
  ret i32 10

exit:
  ret i32 20
}

define i32 @test4(i32 %x, i32 %y, i32 %z) {
; CHECK-LABEL: @test4(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[C_1:%.*]] = icmp ule i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    br i1 [[C_1]], label [[BB1:%.*]], label [[EXIT:%.*]]
; CHECK:       bb1:
; CHECK-NEXT:    [[C_2:%.*]] = icmp ule i32 [[Y]], [[Z:%.*]]
; CHECK-NEXT:    br i1 [[C_2]], label [[BB2:%.*]], label [[EXIT]]
; CHECK:       bb2:
; CHECK-NEXT:    [[T_1:%.*]] = icmp ule i32 [[X]], [[Z]]
; CHECK-NEXT:    call void @use(i1 true)
; CHECK-NEXT:    [[U_1:%.*]] = icmp eq i32 [[X]], [[Z]]
; CHECK-NEXT:    call void @use(i1 [[U_1]])
; CHECK-NEXT:    ret i32 10
; CHECK:       exit:
; CHECK-NEXT:    ret i32 20
;
entry:
  %c.1 = icmp ule i32 %x, %y
  br i1 %c.1, label %bb1, label %exit

bb1:
  %c.2 = icmp ule i32 %y, %z
  br i1 %c.2, label %bb2, label %exit

bb2:
  %t.1 = icmp ule i32 %x, %z
  call void @use(i1 %t.1)
  %u.1 = icmp eq i32 %x, %z
  call void @use(i1 %u.1)
  ret i32 10


exit:
  ret i32 20
}
