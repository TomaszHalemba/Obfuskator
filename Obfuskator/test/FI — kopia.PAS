program re;

uses crt;

var
a,sr,max,min,sum:real;
s:string;
f:file of real;
w:char;

begin
min:=10;
clrscr;
write('podaj sciezke ');
readln(s);
assign(f,s);
rewrite(f);
writeln('esc konczy prace');
repeat
write('podaj dana ');
readln(a);
write(f,a);
w:=readkey;
until w=#27;


reset(f);
clrscr;
writeln('ilosc pozycji: ',filesize(f));

while not eof(f) do
begin
read(f,a);
writeln(filepos(f),a:10:0);
if a>max then max:=a;
if a<min then min:=a;
sum:=sum+a;
end;

sr:=sum/filesize(f);
close(f);
writeln('suma: ',sum:21:0);
writeln('maxymalna liczba ',max:10:0);
writeln('minimalna liczba ',min:10:0);
writeln('srednia:',sr:19:0);
readln
end.




