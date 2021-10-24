; ModuleID = 'Llama program'
source_filename = "Llama program"

@vars = private global [26 x i32] zeroinitializer
@nl = private constant [2 x i8] c"\0A\00"

declare void @writeInteger(i64)

declare void @writeReal(double)

declare void @writeString(i8*)

define i64 @main() {
entry:
  call void @writeReal(double 4.400000e+00)
  call void @writeString(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @nl, i32 0, i32 0))
  ret i64 0
}
