uses crt;

var a:integer;

function fib(a:integer):integer;
begin
if ((a=0) or (a=1)) then fib:=a
else
fib:=fib(a-1)+fib(a-2);
end;


begin
clrscr;
write('podaj liczbe z ciagu fibonacciego: ');
readln(a);
writeln(fib(a));
readln;
end.