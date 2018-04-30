program test(intput, output); // 这里检测注释风格1 ;
const
    MAX = 123;      // 检测 + - const = 各种 const 风格
    MIN = -123;
    CH = '1';
    MAX1 = +MAX;
    MAX2 = -MAX;
    MAX3 = +123;

    (* 这里检测注释风格2 *)
    { 这里检测注释风格3 }

var
    a, a1, a11 : array[-1..1] of integer;   //  这里检测负下标 数组赋值 .. :  [ ]
    a2 : array[1..10, 1..10]  of integer;   //  检测 多维int数组
    a3 : array[1..2, 1..2, 1..2] of real;   //  检测 多维real数组 ,
    x, y, z : integer;      // 检测int赋值
    b, c : real;            // 检测real赋值

    {
    x1, x2, x3 : boolean;
    c1, c2, c3 : char;
    }

procedure pro1(a : integer; b : real);  // 带参数过程
    const
        CONPRO1 = 1;    // 过程内 const 检测
    var
        t : integer;    // 过程内 var 检测
    begin
        writeln(1, 2, 3);   // 过程内 语句 识别
    end;

function func1 : integer;   // 无参数函数
    begin
        func1 := 321;       // 检查 :=
    end;

procedure swap(var a, b : integer);     // 有参数过程 其中包含变参调用
    var
        t : integer;
    begin
        t := a;
        a := b;
        b := t;
    end;

function func2(a, b:integer) : integer;     // 有参数函数
    const
        SONF = 12;
    begin
        if SONF = 12
            then func2 := -1;
    end;

begin
    read(a[-1]);            // 检测read 负下标调用
    writeln(a[-1]);         // 检测writeln
    writeln;                // 检测 无参数过程调用

    readln(a[1]);           // 检测readln
    writeln(a[1] + 1);
    writeln;

    for x := 1 to 9 do      // 检测 for
        write(x);           // 检测 write
    writeln;

    if func1() = 321        // 检测无参数函数调用 if 调用
    then
        if ( ((2>1) and (1>=0) and (1=1) and (1<2) and (1<=2) and (1<>2)) or (not(2<>2)) )   // 检测各个关系运算符 not ( )
        then
            begin
                a2[1, 10] := -10;                               // 检测多维数组调用
                writeln(a2[1, 10] * -1 + 1 div 10 + 11 mod 10); // 检测 div mod * + -
                writeln;
            end
        else
            begin
                a3[1, 1, 1] := 1;
                writeln(a3[1, 1, 1]);
                writeln;
            end;

    y := 1;
    z := 2;
    swap(y, z);         // 变参调用
    writeln(y, z);
    writeln;

    b := 1.1 / 10;      // 检测 / .
    writeln(b);

    {
    x1 := true;
    x2 := false;
    c1 := '1';
    }

end.