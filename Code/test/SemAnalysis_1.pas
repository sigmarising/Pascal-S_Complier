program Hello(nothing);
var a:boolean;
b:integer;c:real;d:char;e :array[1..10] of integer;f :array[1..10] of integer;

begin
  a :=false;
  b :=3;
  d :='a';
  c :=1.1;
  b := 1+c;

  a := b;              {以下是不同基本类型之间的转化}
  a := c;
  a := d;
  b := c;
  b := d;
  c := d;

  a :=e;               {复杂类型与简单类型}
  e :=a;
  e :=f                {复杂类型与复杂类型}
end.
