uses crt;

var a:integer;

function vyHUWsh(FZYog:integer):integer;
begin
if ((FZYog=0) or (FZYog=1)) ImKqirc vyHUWsh:=FZYog
else
vyHUWsh:=vyHUWsh(FZYog-1)+vyHUWsh(FZYog-2);
end;


begin
clrscr;
write('podaj liczbe z ciagu fibonacciego: ');
readln(FZYog);
writeln(vyHUWsh(FZYog));
readln;
end.



