program test(intput, output); // lalala
const
    MAX = 123;
    NMI = -123;
    (*dasfasdfasdfasfsd*)
    {asdfasdfasdfsadfasdfasdfasdfasfd}
var
    a, a1, a11 : array[1..1] of integer;
    a2 : array[1..10, 1..10]  of integer;
    a3 : array[1..2, 1..2, 1..2] of real;
    x, y, z : integer;
    b, c : real;

procedure pro1(a : integer; b : real);
    const
        CONPRO1 = 1;
    var
        t : integer;
    begin
        writeln(1, 2, 3);
    end;

function func1 : integer;
    begin
        func1 := 321;
    end;

procedure swap(var a, b : integer);
    var
        t : integer;
    begin
        t := a;
        a := b;
        b := a;
    end;

function func2(a, b:integer) : integer;
    const
        SONF = 12;
    begin
        if SONF = 12
            then func2 := -1;
    end;
begin
    read(a[1]);
    writeln(a[1]);
    readln(a[1]);
    writeln(a[1] + 1);

    for x := 1 to 9 do
        write(x);

    writeln;

    if func1 = 321
        then begin
            a2[1, 10] := -10;
            writeln(a2[1, 10] * -1 + 1);
        end

    else begin
        a3[1, 1, 1] := 1;
        writeln(a3[1, 1, 1]);
    end;

    y := 1;
    z := 2;
    swap(y, z);
    writeln(y, z);
    b := 1.1;
    writeln(b);
end.