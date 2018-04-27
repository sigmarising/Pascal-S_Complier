program example(input,output);
var 
    x,y,z : integer;
    a : array[1..2, 1..2] of integer;
begin
    a[1][1] := 2;
    a[2][2] := 1;
    writeln(a[2][2], a[1][1]);
    writeln(a[1][1], a[2][2]);
end.