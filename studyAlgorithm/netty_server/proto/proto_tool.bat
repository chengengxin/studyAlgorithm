

cd ../src/main/java/proto
set "ss=%cd%"
echo %ss%
rem rmdir /s /q ../src/main/java/proto
rem protoc -I=./*.proto --java_out=../src/main/java/
echo end

