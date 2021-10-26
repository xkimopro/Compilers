; ModuleID = 'Llama program'
source_filename = "Llama program"

@vars = private global [26 x i32] zeroinitializer
@nl = private constant [3 x i8] c"\0A\0A\00"

declare void @writeInteger(i64)

declare void @writeBoolean(i1)

declare void @writeChar(i8)

declare void @writeReal(x86_fp80)

declare void @writeString(i8*)

declare i64 @readInteger()

declare i1 @readBoolean()

declare i8 @readChar()

declare x86_fp80 @readReal()

declare i8** @readString()

define i64 @main() {
entry:
  call void @writeReal(x86_fp80 0xK40018CCCCD0000000000)
  ret i64 0
}
