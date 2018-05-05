program Hello(n);
var b,c:integer;
 d : char;
 a: array[1..8] of integer;
function exchange(var i,j:integer):integer;
var x :integer;
begin
	x :=i;
	i :=j;
	j :=x;
end;
begin
  b:=2;
  c:=3;
  d:='a';
  exchange(a[1],b,c);   {º¯Êı²ÎÊı´íÎó}
  exchange(a,d);
  writeln (a);
end.
