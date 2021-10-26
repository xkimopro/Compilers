; ModuleID = 'Llama program'
source_filename = "Llama program"

@vars = private global [26 x i32] zeroinitializer
@nl = private constant [2 x i8] c"\0A\00"

declare void @writeInteger(i64)

declare void @writeBoolean(i1)

declare void @writeChar(i8)

declare void @writeReal(x86_fp80)

declare void @writeString(i8*)

define i64 @main() {
entry:
<<<<<<< Updated upstream
  call void @writeReal(double 4.400000e+00)
=======
  call void @writeReal(x86_fp80 0xK40018CCCCD0000000000)
  call void @writeString(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @nl, i32 0, i32 0))
  call void @writeBoolean(i1 false)
  call void @writeBoolean(i1 false)
  call void @writeString(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @nl, i32 0, i32 0))
  call void @writeChar(i8 119)
>>>>>>> Stashed changes
  call void @writeString(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @nl, i32 0, i32 0))
  ret i64 0
}
