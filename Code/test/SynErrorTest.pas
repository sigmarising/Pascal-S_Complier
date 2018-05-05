 example(input,output);                 //测试program_head的错误处理
const a = '1';                          
      b := '45'                         //测试常量声明部分的错误处理                     
var x,y,z : integer;    
    b c :char;                          //测试变量声明部分的错误处理
function gcd(a,char,b:integer) :integer;//测试id_list部分的错误处理
    begin
        if a mod b := 0                 //测试if语句的错误处理1
            then gcd := b
            else gcd := gcd(b, a mod b)
        if a mod b := 0                 //测试if语句的错误处理2
            then gcd = b
            else gcd := gcd(b, a mod b)
    end;

function : integer;                     //测试function的声明的错误处理
    begin
        func1 := 321;       
    end;

procedure pro1(a : integer; b real);   //测试procedure的声明的错误处理
    var
        t  integer;                    //测试subprogram的变量声明部分的错误处理
    begin
        t := t t;                       //测试subprogram的语句错误
    end;

begin
    read(x,y);
    write(gcd(x,y));
    for x := 0 to 10 do y := y+1;       //for语句测试
    for x = 0 to 10 do y := y+1;        //测试for语句的错误处理1
    for x := 0 to x y z do y := y+1;    //测试for语句的错误处理2
    x := y z;                           //测试语句级别的错误处理
    y := x + ;                          //测试语句级别的错误处理
end.